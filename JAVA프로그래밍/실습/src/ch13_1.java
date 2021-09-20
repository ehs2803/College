import java.util.Scanner;

class MyThread_ch13_1 implements Runnable{
	@Override
	public void run() {
		System.out.println("스레드 실행 시작");
		for(int i=1;i<=10;i++) {
			System.out.print(i+" ");
			try {
				Thread.sleep(1000);
			}
			catch(InterruptedException e) {return;}
		}
		System.out.println();
		System.out.println("스레드 종료");
	}
}
public class ch13_1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("아무 키나 입력>> ");
		String str = sc.next();
		
		Thread th = new Thread(new MyThread_ch13_1());
		th.start();
		sc.close();
	}
}
