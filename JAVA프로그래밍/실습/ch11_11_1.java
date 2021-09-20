class CircularQueue1 {
    private int contents[], size;       // 큐의 내용, 크기
    private int head, tail;             // head와 tail
    private int count;                  // 큐 내에 있는 원소의 수

    public CircularQueue1(int sz) {
        size = sz; 
        head = tail = 0;
        count = 0;
        contents = new int[size];
    }
    public synchronized int get() {
        int res;
        while (count == 0)
            try { wait();
            } catch (InterruptedException e) { }
        res = contents[tail];
        tail = (tail + 1) % size;
        count--;
        notifyAll();
        return res;
    }
    public synchronized void put(int value) { 
        while ( count == size ) 
            try { wait(); 
            } catch (InterruptedException e) { }
        contents[head] = value; 
            head = (head + 1) % size;
            count++;
            notifyAll();
        }
}

class Consumer1 extends Thread {
    private CircularQueue1 boundedBuffer;
    private int number;

    public Consumer1(CircularQueue1 c, int number) {
        super("Consumer #" + number);
        boundedBuffer = c;
        this.number = number;
    }
    public void run() {
        int value = 0;
        for (int i = 0; i < 10; i++) {
            value = boundedBuffer.get();
            System.out.println(getName() + " got: " + value);
        }
    }
}

class Producer1 extends Thread {
    private CircularQueue1 boundedBuffer;
    private int number;

    public Producer1(CircularQueue1 c, int number) {
        super("Producer #" + number);
        boundedBuffer = c;
        this.number = number;
    }

    public void run() {
        for (int i = 0; i < 10; i++) {
            boundedBuffer.put(i);
            System.out.println(getName() + " put: " + i);
            try {
                sleep((int)(Math.random() * 100));
            } catch (InterruptedException e) { }
        }
    }
}

public class ch11_11_1 {
    public static void main(String[] args) {
        CircularQueue1 c = new CircularQueue1(2);
        Producer1 p1 = new Producer1(c, 1);
        Consumer1 c1 = new Consumer1(c, 1);
        Producer1 p2 = new Producer1(c, 2);
        Consumer1 c2 = new Consumer1(c, 2);
        p1.start();
        c1.start();
        p2.start();
        c2.start();
    }
}