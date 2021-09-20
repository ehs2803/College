class TestThread extends Thread{
	TestThread(ThreadGroup g, String name){
		super(g,name);
	}
	public void run() {
		try {
			System.out.println(getName());
			sleep(1000);
		}catch(InterruptedException e) {}
	}
}

public class ch11_9 {
	public static void main(String[] args) {
		ThreadGroup myThreadGroup = new ThreadGroup("ThreadGroupName");
		TestThread t1 = new TestThread(myThreadGroup, "x");
		TestThread t2 = new TestThread(myThreadGroup, "y");
		TestThread t3 = new TestThread(myThreadGroup, "z");
		t1.start(); t2.start(); t3.start();
	}
}
