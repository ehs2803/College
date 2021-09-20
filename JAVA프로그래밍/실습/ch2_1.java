import java.util.Scanner;

public class ch2_1 {
	public static void main(String [] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("input three integer : ");
		int one=scanner.nextInt();
		int two=scanner.nextInt();
		int three=scanner.nextInt();
		System.out.println("입력한 숫자의 합은 "+(one+two+three)+"입니다.");
		
		System.out.print("연산>>");
		int first = scanner.nextInt();
		String op = scanner.next();
		int second = scanner.nextInt();
		if(op.equals("+")) {
			System.out.println(first+op+second+"의 계산결과는 "+(first+second));
		}
		else if(op.equals("-")) {
			System.out.println(first+op+second+"의 계산결과는 "+(first-second));
		}
		else if(op.equals("*")) {
			System.out.println(first+op+second+"의 계산결과는 "+(first*second));
		}
		else if(op.equals("/")) {
			if(second==0)
				System.out.println("0으로 나눌수 없습니다.");
			else
				System.out.println(first+op+second+"의 계산결과는 "+(first/second));
		}
		scanner.close();
	}
}
