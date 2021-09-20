class Philosopher extends Thread {
	private Fork leftfork;
	private Fork rightfork;
	private String name;
	private int rounds;
	
	public Philosopher ( String name, Fork left, Fork right, int rounds){
		this.name = name;
		leftfork = left;
		rightfork = right;
		this.rounds = rounds;
	}
	
	public void eat()
	{
		if(! leftfork.used){
			if(!rightfork.used){
			    int temp1 = leftfork.take(name);
			    if(temp1==0) {
			    	think();
			    	return;
			    }
				int temp2 = rightfork.take(name);
				if(temp2==0) {
			    	think();
			    	return;
			    }
				Log.msg(name + " : Eat");
				Log.Delay(1000);

				rightfork.release(name);
		 		leftfork.release(name);
			}
		}		
		think();
	}
	
	public void think(){
		 	Log.msg(name + " : Think");
		 	Log.Delay(1000);
	}
	
	public void run(){
		for(int i=0; i<=rounds; i++){
			eat();
		}
	}
}

class Fork{
	public boolean used;
	public String fname;

	public Fork(String name){
		this.fname = name;
	}
	
	public synchronized int take(String name) {
		if(this.used) return 0;
		Log.msg (name+" : Used : " + fname );
		this.used = true;
		return 1;
	}
	
	public synchronized void release(String name) {
		Log.msg (name + " : Released : " + fname );
		this.used = false ;
	}
}

class Log{
	public static void msg(String msg){
		System.out.println(msg);
	}
	
	public static void Delay(int ms){
		try{
			Thread.sleep(ms);
		}
		catch(InterruptedException ex){ }
	}
}

public class DiningPhilosophers{
	public static void main(String[] args){

		int rounds=10;
 
		Fork[] forks = new Fork[5];

		//initlize the forks
		for(int i=0; i< forks.length; i++){
			forks[i] = new Fork("fork"+(i+1));
		}
		
		Philosopher[] philosophers = new Philosopher[5];
		
		philosophers[0] = new Philosopher("태조", forks[0], forks[1], rounds);
		philosophers[1] = new Philosopher("정조", forks[1], forks[2], rounds);
		philosophers[2] = new Philosopher("세종", forks[2], forks[3], rounds);
		philosophers[3] = new Philosopher("문종", forks[3], forks[4], rounds);
		philosophers[4] = new Philosopher("단종", forks[0], forks[4], rounds);

		for(int i=0;i<philosophers.length;i++){
			Log.msg("Thread "+ (i+1) + " has started");
			Thread t= new Thread( philosophers[i]);
			t.start();
		}
 	}
}

/*
import java.util.concurrent.Semaphore;
import java.util.concurrent.ThreadLocalRandom;

public class Main {

    static int philosopher = 5;
    static philosopher philosophers[] = new philosopher[philosopher];
    static chopstick chopsticks[] = new chopstick[philosopher];

    static class chopstick {

        public Semaphore mutex = new Semaphore(1);

        void grab() {
            try {
                mutex.acquire();
            }
            catch (Exception e) {
                e.printStackTrace(System.out);
            }
        }

        void release() {
            mutex.release();
        }

        boolean isFree() {
            return mutex.availablePermits() > 0;
        }

    }

    static class philosopher extends Thread {

        public int number;
        public chopstick leftchopstick;
        public chopstick rightchopstick;

        philosopher(int num, chopstick left, chopstick right) {
            number = num;
            leftchopstick = left;
            rightchopstick = right;
        }

        public void run(){

            while (true) {
                leftchopstick.grab();
                System.out.println("philosopher " + (number+1) + " grabs left chopstick.");
                rightchopstick.grab();
                System.out.println("philosopher " + (number+1) + " grabs right chopstick.");
                eat();
                leftchopstick.release();
                System.out.println("philosopher " + (number+1) + " releases left chopstick.");
                rightchopstick.release();
                System.out.println("philosopher " + (number+1) + " releases right chopstick.");
            }
        }

        void eat() {
            try {
                int sleepTime = ThreadLocalRandom.current().nextInt(0, 1000);
                System.out.println("philosopher " + (number+1) + " eats for " + sleepTime);
                Thread.sleep(sleepTime);
            }
            catch (Exception e) {
                e.printStackTrace(System.out);
            }
        }

    }

    public static void main(String argv[]) {

        for (int i = 0; i < philosopher; i++) {
            chopsticks[i] = new chopstick();
        }

        for (int i = 0; i < philosopher; i++) {
            philosophers[i] = new philosopher(i, chopsticks[i], chopsticks[(i + 1) % philosopher]);
            philosophers[i].start();
        }

        while (true) {
            try {
                // sleep 1 sec
                Thread.sleep(1000);

                // check for deadlock
                boolean deadlock = true;
                for (chopstick f : chopsticks) {
                    if (f.isFree()) {
                        deadlock = false;
                        break;
                    }
                }
                if (deadlock) {
                    Thread.sleep(1000);
                    System.out.println("Everyone Eats");
                    break;
                }
            }
            catch (Exception e) {
                e.printStackTrace(System.out);
            }
        }

        System.out.println("Exit The Program!");
        System.exit(0);
    }

}
*/
/*
import java.util.concurrent.Semaphore;
import java.util.concurrent.ThreadLocalRandom;

public class DiningPhilosophers {

  static int philosophersNumber = 5;
  static Philosopher philosophers[] = new Philosopher[philosophersNumber];
  static Fork forks[] = new Fork[philosophersNumber];

  static class Fork {

    public Semaphore mutex = new Semaphore(1);

    void grab() {
      try {
        mutex.acquire();
      }
      catch (Exception e) {
        e.printStackTrace(System.out);
      }
    }

    void release() {
      mutex.release();
    }

    boolean isFree() {
      return mutex.availablePermits() > 0;
    }

  }

  static class Philosopher extends Thread {

    public int number;
    public Fork leftFork;
    public Fork rightFork;

    Philosopher(int num, Fork left, Fork right) {
      number = num;
      leftFork = left;
      rightFork = right;
    }

    public void run(){
      System.out.println("Hi! I'm philosopher #" + number);

      while (true) {
        leftFork.grab();
        System.out.println("Philosopher #" + number + " grabs left fork.");
        rightFork.grab();
        System.out.println("Philosopher #" + number + " grabs right fork.");
        eat();
        leftFork.release();
        System.out.println("Philosopher #" + number + " releases left fork.");
        rightFork.release();
        System.out.println("Philosopher #" + number + " releases right fork.");
      }
    }

    void eat() {
      try {
        int sleepTime = ThreadLocalRandom.current().nextInt(0, 1000);
        System.out.println("Philosopher #" + number + " eats for " + sleepTime);
        Thread.sleep(sleepTime);
      }
      catch (Exception e) {
        e.printStackTrace(System.out);
      }
    }

  }

  public static void main(String argv[]) {
    System.out.println("Dining philosophers problem.");

    for (int i = 0; i < philosophersNumber; i++) {
      forks[i] = new Fork();
    }

    for (int i = 0; i < philosophersNumber; i++) {
      philosophers[i] = new Philosopher(i, forks[i], forks[(i + 1) % philosophersNumber]);
      philosophers[i].start();
    }

    while (true) {
      try {
        // sleep 1 sec
        Thread.sleep(1000);

        // check for deadlock
        boolean deadlock = true;
        for (Fork f : forks) {
          if (f.isFree()) {
            deadlock = false;
            break;
          }
        }
        if (deadlock) {
          Thread.sleep(1000);
          System.out.println("Hurray! There is a deadlock!");
          break;
        }
      }
      catch (Exception e) {
        e.printStackTrace(System.out);
      }
    }

    System.out.println("Bye!");
    System.exit(0);
  }

}
*/
/*
import java.util.ArrayList;
import java.util.concurrent.locks.ReentrantLock;

class Fork {

    Lock lock = new ReentrantLock();

    public void useFork() {
        lock.lock();
    }

    public void unUseFork() {
        lock.unlock();
    }
}

class Tableware {

    public static final ArrayList<Fork> forks = new ArrayList<Fork>();

    static {
        forks.add(new Fork());
        forks.add(new Fork());
        forks.add(new Fork());
        forks.add(new Fork());
        forks.add(new Fork());
    }
}
class Philosopher implements Runnable {

    private String name;
    private int number;

    public Philosopher(String name, int number) {
        this.name = name;
        this.number = number;
    }

    public void think() {
        System.out.print(name + " thinking ...");
    }

    public void eat() {
    	System.out.print(name + " eating ... yum-yum-yum");
    }

    public void takeFork(int i) {

    	System.out.print(name + " attemp to take (" + i + ") fork ...");

        Fork fork = Tableware.forks.get(i);
        fork.useFork();

        System.out.print(name + " take (" + i + ") fork now!");
    }

    public void putFork(int i) {

    	System.out.print(name + " put (" + i + ") fork down ...");

        Fork fork = Tableware.forks.get(i);
        fork.unUseFork();
    }

    @Override
    public void run() {
        while (true) {
            think();
            takeFork(this.number);
            takeFork((this.number + 1) % 5);
            eat();
            putFork(this.number);
            putFork((this.number + 1) % 5);
        }
    }
}
public class DiningPhilosophers {
	public static void main(String[] args) {
		Philosopher a = new Philosopher("A", 0);
        Philosopher b = new Philosopher("B", 1);
        Philosopher c = new Philosopher("C", 2);
        Philosopher d = new Philosopher("D", 3);
        Philosopher e = new Philosopher("E", 4);

        a.run();
        b.run();
        c.run();
        d.run();
        e.run();
	}
}

*/