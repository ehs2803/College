import java.util.Scanner;

public class ch2_1 {
	public static void main(String [] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("input three integer : ");
		int one=scanner.nextInt();
		int two=scanner.nextInt();
		int three=scanner.nextInt();
		System.out.println("�Է��� ������ ���� "+(one+two+three)+"�Դϴ�.");
		
		System.out.print("����>>");
		int first = scanner.nextInt();
		String op = scanner.next();
		int second = scanner.nextInt();
		if(op.equals("+")) {
			System.out.println(first+op+second+"�� ������� "+(first+second));
		}
		else if(op.equals("-")) {
			System.out.println(first+op+second+"�� ������� "+(first-second));
		}
		else if(op.equals("*")) {
			System.out.println(first+op+second+"�� ������� "+(first*second));
		}
		else if(op.equals("/")) {
			if(second==0)
				System.out.println("0���� ������ �����ϴ�.");
			else
				System.out.println(first+op+second+"�� ������� "+(first/second));
		}
		scanner.close();
	}
}
