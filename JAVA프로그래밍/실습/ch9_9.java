
public class ch9_9 {
	public static int factorial(int n) {
		assert (n>=1) : "n must be one or more.";
		int fact=1;
		for(int i=1;i<=n;i++) {
			fact*=i;
		}
		return fact;
	}
	public static void main(String[] args) {
		System.out.println("3 factorial = "+factorial(0));
	}
}
/*
�⺻������ ������ ��Ȱ��ȭ �Ǿ��ִ�. 
-enableassertions�� -ea�ɼ����� ���α׷��� �����Ͽ� ������ Ȱ��ȭ�Ѵ�
java -ea MainClass
*/