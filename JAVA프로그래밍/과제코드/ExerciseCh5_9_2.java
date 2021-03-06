import java.io.*;

public class ExerciseCh5_9_2 {
	static int method(int x, int y) {
		while(x!=y) {
			if(x>y) x-=y;
			else y-=x;
		}
		return x;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int i, j;
		int a, b;
		
		System.out.print("Enter first number : ");
		i = Integer.parseInt(input.readLine());
		System.out.print("Enter second number : ");
		j = Integer.parseInt(input.readLine());
		a = method(i, j);
		System.out.println("a = "+ a);
		b = (i/a)*(j/a)*a;
		System.out.println("b = "+ b);
	}
}
