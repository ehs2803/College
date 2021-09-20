class CircularQueue{
	private int contents[], size;
	private int head, tail;
	private int count;
	
	public CircularQueue(int sz) {
		size=sz;
		head=tail=0;
		count=0;
		contents = new int[size];
	}
	
	public synchronized int get() {
		int res;
		while(count==0) {
			try {
				wait();
			} catch(InterruptedException e) {}
		}
		res=contents[tail];
		tail=(tail+1)%size;
		count--;
		notifyAll();
		return res;
	}
	
	public synchronized void put(int value) {
		while(count==size) {
			try {
				wait();
			} catch(InterruptedException e) {}
		}
		contents[head]=value;
		head=(head+1)%size;
		count++;
		notifyAll();
	}
}

class Producer extends Thread{
	private CircularQueue boundedBuffer;
	private int number;
	
	public Producer(CircularQueue c, int number) {
		super("Producer #"+number);
		boundedBuffer = c;
		this.number=number;
	}
	
	public synchronized void run() {
		for(int i=0;i<10;i++) {
			boundedBuffer.put(i);
			System.out.println(getName()+" put: "+i);
			try {
				sleep((int)(Math.random()*1000));
			} catch(InterruptedException e) {}
		}
	}
}

class Consumer extends Thread{
	private CircularQueue boundedBuffer;
	private int number;
	
	public Consumer(CircularQueue c, int number) {
		super("Consumer #"+number);
		boundedBuffer=c;
		this.number=number;
	}
	
	public synchronized void run() {
		int value;
		for(int i=0;i<10;i++) {
			value = boundedBuffer.get();
			System.out.println(getName()+" got: "+value);
		}
	}
}

public class ch11_producerConsumerTest {
	public static void main(String[] args) {
		CircularQueue c = new CircularQueue(2);
		Producer p1 = new Producer(c,1);
		Consumer c1 = new Consumer(c,1);
		p1.start();
		c1.start();
	}
}

