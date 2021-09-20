
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
기본적으로 단정은 비활성화 되어있다. 
-enableassertions나 -ea옵션으로 프로그램을 실행하여 단정을 활성화한다
java -ea MainClass
*/