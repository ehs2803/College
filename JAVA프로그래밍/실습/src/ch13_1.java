import java.util.Scanner;

class MyThread_ch13_1 implements Runnable{
	@Override
	public void run() {
		System.out.println("������ ���� ����");
		for(int i=1;i<=10;i++) {
			System.out.print(i+" ");
			try {
				Thread.sleep(1000);
			}
			catch(InterruptedException e) {return;}
		}
		System.out.println();
		System.out.println("������ ����");
	}
}
public class ch13_1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("�ƹ� Ű�� �Է�>> ");
		String str = sc.next();
		
		Thread th = new Thread(new MyThread_ch13_1());
		th.start();
		sc.close();
	}
}
