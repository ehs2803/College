S=[0,1,2,3,4,5,6,7,8]
V=[0,0,0,0,0,0,0,0,0,0]

a0=[0,1,1,0,0,0,0,0,0,0]
a1=[1,0,1,0,0,0,0,0,1,0]
a2=[0,0,0,1,0,1,0,0,0,0]
a3=[1,0,0,0,1,0,0,0,0,0]
a4=[0,0,0,0,0,1,1,0,0,0]
a5=[0,0,0,0,0,0,1,1,1,0]
a6=[0,0,0,0,1,0,0,1,0,1]
a7=[0,0,0,0,0,0,1,0,0,1]
a8=[0,0,0,0,0,0,0,1,1,0]
a9=[0,0,0,0,0,0,0,0,0,0]
a=[a0,a1,a2,a3,a4,a5,a6,a7,a8]

p0=[0,0.5,0.5,0,0,0,0,0,0,0]
p1=[0.4,0,0.3,0,0,0,0,0,0.3,0]
p2=[0,0,0,0.8,0,0.2,0,0,0,0]
p3=[0.6,0,0,0,0.4,0,0,0,0,0]
p4=[0,0,0,0,0,0.5,0.5,0,0,0]
p5=[0,0,0,0,0,0,0.4,0.3,0.3,0]
p6=[0,0,0,0,0.2,0,0,0.4,0,0.4]
p7=[0,0,0,0,0,0,0.2,0,0,0.8]
p8=[0,0,0,0,0,0,0,0.6,0.4,0]
p9=[0,0,0,0,0,0,0,0,0,0]
p=[p0,p1,p2,p3,p4,p5,p6,p7,p8]

r0=[0,0,0,0,0,0,0,0,0,0]
r1=[0,0,1,0,0,0,0,0,-1,0]
r2=[0,0,0,0,0,0,0,0,0,0]
r3=[-1,0,0,0,0,0,0,0,0,0]
r4=[0,0,0,0,0,1,0,0,0,0]
r5=[0,0,0,0,0,0,1,-1,-2,0]
r6=[0,0,0,0,0,0,0,0,0,10]
r7=[0,0,0,0,0,0,0,0,0,2]
r8=[0,0,0,0,0,0,0,0,0]
r9=[0,0,0,0,0,0,0,0,0]
r=[r0,r1,r2,r3,r4,r5,r6,r7,r8]

policy_iteration_step = 0
while True:
    policy_iteration_step += 1
    print("===================================")
    print(f'policy_iteration_step: {policy_iteration_step}')

    while True:
        print("\npolicy Evaluation: ")
        delta = 0
        for s in S:
            v = V[s]
            value = 0
            i = 0
            for percentage, reward in zip(p[s], r[s]):
                value += percentage * (reward + 0.9 * V[i])
                i += 1
            V[s] = value
            delta = max(delta, abs(v - V[s]))
            print(f'V[s{s}] = {V[s]}')

        if delta < 0.001:
            break

    print("\npolicy Improvement: ")
    policy_stable = True
    for s in S:
        #print(f'a[s{s}] = {a[s]}', end=' ---> ')
        old_action = a[s].index(1)
        q_list = []
        i = 0
        for percentage, reward in zip(p[s], r[s]):
            q_value = percentage * (reward + 0.9 * V[i])
            q_list.append(q_value)
            i += 1
        index = q_list.index(max(q_list))
        a[s][old_action] = 0
        a[s][index] = 1

        #print(f'a[s{s}] = {a[s]}')
        if old_action != index:
            policy_stable = False
    if policy_stable == True:
        break