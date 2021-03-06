import numpy as np
import time
import gym
import itertools
from matplotlib import pyplot as plt

# Number of RBF kernels
p1_NUM_RBF = 15
p2_NUM_RBF = 15
v_NUM_RBF = 15

NUM_STATES = p1_NUM_RBF * p2_NUM_RBF * v_NUM_RBF
NUM_ACTIONS = 1
INIT_SIGMA = 0.5
TERM_SIGMA = 0.1

p1_mu = np.linspace(-1, 1, p1_NUM_RBF)
p2_mu = np.linspace(-1, 1, p2_NUM_RBF)
v_mu = np.linspace(-1, 1, v_NUM_RBF)
MUS = np.array(list(itertools.product(p1_mu, p2_mu, v_mu)))

class ActorCritic(object):
    def __init__(self, env, gamma=0.99, sigma=0.1, alpha_value=0.1, alpha_policy=0.1):
        # Upper and lower limits of the state
        self.max_state = env.observation_space.high
        self.min_state = env.observation_space.low

        self.value = np.zeros((NUM_STATES,))
        self.mean_policy = np.zeros((NUM_STATES, NUM_ACTIONS))

        # Discount factor
        self.gamma = gamma

        # Standard deviation of the policy (this will follow epsilon-greedy)
        self.sigma = sigma

        # Standard deviation of the RBF kernel width
        self.rbf_sigma = 0.1

        # Step sizes for the value function and policy
        self.alpha_value = alpha_value
        self.alpha_policy = alpha_policy

    def _compute_policy_gradient(self, state, action, advantage):
        grad = (state * (action - self.mean_policy.T.dot(state)) / (self.sigma ** 2)) * advantage
        return grad.T

    def _policy_gradient_step(self, grad, I):
        self.mean_policy = np.add(self.mean_policy, np.reshape(grad * self.alpha_policy * I, (grad.shape[0], 1)))

    def _update_value(self, state, advantage):
        grad_baseline = self.alpha_value * advantage * state
        self.value += grad_baseline

    def _rbf_transform(self, state):
        # Normalize the states between -1 and 1
        state = np.reshape(state, (3,))
        state = np.divide(((state - self.min_state) * 2), (self.max_state - self.min_state)) - 1

        # compute the mean of the states
        state_mu = np.linalg.norm(np.reshape(state, (len(state),)) - MUS, 2, axis=1)

        # compute how far away the original states are from the radial basis function kernel centers
        output = np.array(
            np.exp(- (state_mu) ** 2 / (2 * (self.rbf_sigma ** 2))) / (self.rbf_sigma * np.sqrt(2 * np.pi)))
        return output

    def _compute_mean(self, state):
        return self.mean_policy.T.dot(state)  # linear

    def _compute_value(self, state, done=False):
        # check for terminal state
        if done:
            return 0
        else:
            return self.value.dot(state)

    # This function should return an action given the
    # state by evaluating the Gaussian polic
    def act(self, state):
        mean = self._compute_mean(state)  # plug in the state into the function approximator to get mean
        action = np.random.normal(mean, self.sigma)  # the standard deviation is the exp of mean
        return [action]

    def update(self, state, action, reward, next_state, done, I):
        advantage = reward + self.gamma * self._compute_value(next_state, done) - self._compute_value(state)
        self._update_value(state, advantage)
        grad = self._compute_policy_gradient(state, action, advantage)
        self._policy_gradient_step(grad, I)


def plot(i, total_rewards, states, final_plot_i=1000, plot_frequency=100):
    if i > 0 and i % plot_frequency == 0:
        print(f'EP[{i}]: {total_rewards[-1]}')  # raw total rewards for that episode

    if i == final_plot_i:
        fig = plt.figure()
        ax1 = fig.add_subplot(111)
        ax1.set_ylabel('Rewards')
        ax1.set_xlabel('Episodes')
        ax1.set_title('Training (moving avg reward window of 500 episodes)')
        plt.plot(total_rewards)
        plt.show()


def train(env, policy):
    num_episodes = 501
    plotting_rewards = []
    for i in range(num_episodes):
        I = 1
        done = False
        rewards = []
        states = []
        policy.sigma -= (INIT_SIGMA - TERM_SIGMA) / num_episodes
        state = env.reset()
        while not done:
            state = policy._rbf_transform(state)
            action = policy.act(state)
            next_state, reward, done, _ = env.step(action)
            policy.update(state, action, reward, policy._rbf_transform(next_state), done, I * policy.gamma)
            state = next_state

            # Book keeping
            states.append(state)
            rewards.append(reward)
        plotting_rewards.append(np.sum(rewards))
        moving_rewards = np.convolve(plotting_rewards, np.ones((100,)) / 100, mode='valid')
        plot(i, moving_rewards, states, num_episodes - 1)


if __name__ == "__main__":
    start_time = time.time()
    env = gym.make('Pendulum-v0')
    env.reset()
    policy = ActorCritic(env, alpha_policy=1e-4, alpha_value=5e-3, sigma=INIT_SIGMA)
    train(env, policy)
    print(f'Training took: {(time.time() - start_time):.2f} seconds')

    # Test time
    state = env.reset()
    done = False
    print(policy.sigma)
    input('press a key to continue for test run')
    while not done:
        state = policy._rbf_transform(state)
        action = policy.act(state)
        next_state, reward, done, _ = env.step(action)
        state = next_state
        env.render()
    env.close()