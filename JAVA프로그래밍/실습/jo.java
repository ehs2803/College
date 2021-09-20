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

	//add 메소드
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

	//delete 메소드
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

public class jo {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int total, interval; //데이터개수, 간격변수
		// "데이터 개수? 간격?";
		total = sc.nextInt();
		interval = sc.nextInt();

		Queue11 Q=new Queue11(); //큐 Q선언
		for (int i = 1;i <= total;i++) 
		{ //1번째부터 total번째까지 1~total 값 삽입
			Q.add(i);
		}
		int n = 0; //삭제할데이터 판별할때 사용
		int survivor = total; //생존자변수 total로 초기화

		//생존자 수가 간격수-1보다 크면 계속 반복
		while (survivor > 15) {//(survivor > interval -1)
			n++;
			if (n% interval ==0) //n이 interval 배수일 때
			{
				Q.delete(); //첫번째 데이터 삭제
				survivor--; //생존자수 1개 줄임
			}
			else  //그 외
			{ 
				int temp = Q.getfront();//temp변수에 첫번째 데이터 저장
				Q.delete();  //첫번째 데이터 삭제
				Q.add(temp);//첫번째 데이터 맨 뒤로 삽입	         
			}
		}
		while (!Q.IsEmpty()){//큐가 빌때까지
			//cout << Q.getfront() << ' ';//첫번째 데이터 출력
			System.out.print(Q.getfront()+" ");
			Q.delete(); //첫번째 데이터 삭제
		}

	}
}
