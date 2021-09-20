import java.util.Scanner;

interface Collection11 {
	int MAX = 100;
	void add(Object obj);
	void delete();
	Object find(Object obj);
	int currentCount();
}

class Link1 {
	Object data;
	Link1 next;

	Link1(Object d, Link1 n) {
		data = d;
		next = n;
	}
}

class Queue11 implements Collection11 {
	private Link1 head = null;
	private Link1 tail = null;
	private Link1 ptr = null;
	private int count = 0;

	//add �޼ҵ�
	public void add(Object obj) {
		Link1 p = new Link1(obj, null);
		if (head == null)
			head = tail = p;
		else {
			tail.next = p;
			tail = p;
		}
		count++;
		//System.out.println(tail.data + "is added.");
	}

	//delete �޼ҵ�
	public void delete() {
		if (head == null)
			System.out.println("Queue is Empty");
		else {
			//System.out.println(head.data + "is deleted.");
			head = head.next;

			count--;
		}
	}
	public int getfront() {
		return (int)head.data;
	}
	public boolean IsEmpty() {
		if(count==0) return true;
		else return false;
	}
	//find �޼ҵ�
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

	// currentCount �޼ҵ�
	public int currentCount() {
		return count;
	}
}

public class jo {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int total, interval; //�����Ͱ���, ���ݺ���
		// "������ ����? ����?";
		total = sc.nextInt();
		interval = sc.nextInt();

		Queue11 Q=new Queue11(); //ť Q����
		for (int i = 1;i <= total;i++) 
		{ //1��°���� total��°���� 1~total �� ����
			Q.add(i);
		}
		int n = 0; //�����ҵ����� �Ǻ��Ҷ� ���
		int survivor = total; //�����ں��� total�� �ʱ�ȭ

		//������ ���� ���ݼ�-1���� ũ�� ��� �ݺ�
		while (survivor > 15) {//(survivor > interval -1)
			n++;
			if (n% interval ==0) //n�� interval ����� ��
			{
				Q.delete(); //ù��° ������ ����
				survivor--; //�����ڼ� 1�� ����
			}
			else  //�� ��
			{ 
				int temp = Q.getfront();//temp������ ù��° ������ ����
				Q.delete();  //ù��° ������ ����
				Q.add(temp);//ù��° ������ �� �ڷ� ����	         
			}
		}
		while (!Q.IsEmpty()){//ť�� ��������
			//cout << Q.getfront() << ' ';//ù��° ������ ���
			System.out.print(Q.getfront()+" ");
			Q.delete(); //ù��° ������ ����
		}

	}
}
