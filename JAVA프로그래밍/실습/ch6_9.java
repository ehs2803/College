interface Collection1 {
	int MAX = 100;
	void add(Object obj);
	void delete();
	Object find(Object obj);
	int currentCount();
}

class Link {
	Object data;
	Link next;

	Link(Object d, Link n) {
		data = d;
		next = n;
	}
}

class Queue1 implements Collection1 {
	private Link head = null;
	private Link tail = null;
	private Link ptr = null;
	private int count = 0;

	//add 메소드
	public void add(Object obj) {
		Link p = new Link(obj, null);
		if (head == null)
			head = tail = p;
		else {
			tail.next = p;
			tail = p;
		}
		count++;
		System.out.println(tail.data + "is added.");
	}

	//delete 메소드
	public void delete() {
		if (head == null)
			System.out.println("Queue is Empty");
		else {
			System.out.println(head.data + "is deleted.");
			head = head.next;

			count--;
		}
	}

	//find 메소드
	public Object find(Object obj) {
		int scan = 0;
		ptr = head;
		for (int i = 1; i <= count; i++) {
			if (ptr.data == obj) {
				scan++;
				switch (i) {
				case 1:
					System.out.print(i + "st ");
					break;
				case 2:
					System.out.print(i + "nd ");
					break;
				case 3:
					System.out.print(i + "rd ");
					break;
				default:
					System.out.print(i + "th ");
					break;
				}
			}
			ptr = ptr.next;
		}
		System.out.println("\n" + scan + " Objects are find.");
		return obj;
	}

	// currentCount 메소드
	public int currentCount() {
		return count;
	}
}

public class ch6_9 {
	public static void main(String[] args) {
		Queue1 tmpQ = new Queue1();
		Integer iT1 = new Integer(2);
		Integer iT2 = new Integer(3);

		System.out.println(tmpQ.currentCount());
		tmpQ.delete();
		System.out.println(tmpQ.currentCount());
		tmpQ.add(iT1);

		tmpQ.add(iT2);
		tmpQ.add(iT2);
		tmpQ.add(iT2);
		tmpQ.add(iT2);
		System.out.println(tmpQ.currentCount());
		tmpQ.delete();
		System.out.println(tmpQ.currentCount());

		tmpQ.find(iT2);
	}
}
