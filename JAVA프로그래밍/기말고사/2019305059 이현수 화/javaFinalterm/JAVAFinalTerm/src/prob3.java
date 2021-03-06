class Stack{
	private int stack[];
	int sp=0;
	int count;
	int size;
	
	Stack(int size){
		this.size=size;
		stack=new int[size];
		count=0;
	}
	
	public synchronized void put(int data, String name) {
		while(count==size) {
			try {
				System.out.println(name+"wait");
				wait();
			}catch(InterruptedException e) { }	
		}
		count++;
		stack[sp++]=data;
		notifyAll();
	}
	
	public synchronized int get(String name) {
        while (count == 0) {
            try {
            	System.out.println(name+"wait");
            	wait();
            } catch (InterruptedException e) { }
        }
        count--;
        notifyAll();
        return stack[--sp];
	}
}

class Consumer extends Thread {
    private Stack boundedBuffer;

    public Consumer(Stack s, String name) {
        super("Consumer " + name);
        boundedBuffer = s;
    }
    public void run() {
        int value = 0;
        for (int i = 0; i < 4; i++) {
        	String name = getName()+" ";
            value = boundedBuffer.get(name);
            System.out.println(getName() + " " + value+" ????");
        }
    }
}

class Producer extends Thread {
    private Stack boundedBuffer;

    public Producer(Stack s, String name) {
        super("Producer " + name);
        boundedBuffer = s;
    }

    public void run() {
        for (int i = 0; i < 4; i++) {
        	String name = getName()+" ";
            boundedBuffer.put(i, name);
            System.out.println(getName() + " " + i+" ????");
            try {
                sleep((int)(Math.random() * 100));
            } catch (InterruptedException e) { }
        }
    }
}

public class prob3 {
    public static void main(String[] args) {
    	Stack s = new Stack(4);
    	
        Producer p1 = new Producer(s, "apple");
        Producer p2 = new Producer(s, "orange");
        Consumer c1 = new Consumer(s, "pear");
        Consumer c2 = new Consumer(s, "banana");
        
        p1.start();
        c1.start();
        p2.start();
        c2.start();
    }
}
