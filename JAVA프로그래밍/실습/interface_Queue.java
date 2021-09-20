//6.9
interface Collection{
	int MAX=100;
	void add(Object obj);
	void delete(Object obj);
	Object find(Object obj);
	int currentCount();
}

class Queue implements Collection{
	private int contents[];
	private int head, tail;
	private int count;
	
	public Queue() {
		head=tail=0;
		count=0;
		contents = new int[MAX];
	}
	
	public void add(Object obj) {
		if(head==MAX) {
			System.out.println("queue is full!!");
			return;
		}
		contents[tail]=(int)obj;
		tail++;
		count++;
	}
	
	public void delete(Object obj) {
		if(head==tail) {
			System.out.println("queue is empty!!");
			return;
		}
		head++;
		count--;
	}
	
	public Object find(Object obj) {
		int temp = (int)obj;
		for(int i=head;i<tail;i++) {
			if(temp==contents[i]) {
				return i;
			}
		}
		return -1;
	}
	
	public int currentCount() {
		return count;
	}
	
}

public class interface_Queue {
	public static void main(String[] args) {
		Queue q = new Queue();
		System.out.println(q.currentCount());
		q.add(1);q.add(2);q.add(3);q.add(4);q.add(5);
		System.out.println(q.currentCount());
		System.out.println(q.find(1));
		System.out.println(q.find(3));
		System.out.println(q.find(5));
		q.delete(1);
		System.out.println(q.find(1));
		System.out.println(q.currentCount());
		
	}
}
//+원형큐 구현!!