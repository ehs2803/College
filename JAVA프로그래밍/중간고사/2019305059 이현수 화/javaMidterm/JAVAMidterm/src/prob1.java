import java.util.Scanner;

class Stack{
	private int stack[];
	int sp=0;
	Stack(){
		stack=new int[10];
	}
	public void push(int data) {
		if(sp==10) {
			System.out.println("stack is full");
		}
		else {
			stack[sp++]=data;
		}
	}
	public int pop() {
		if(sp==0) {
			System.out.println("stack is empty");
			return Integer.MAX_VALUE;
		}
		else {
			return stack[--sp];
		}
	}
}

public class prob1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		Stack s=new Stack();
		
		for(int i=0;i<5;i++) {
			int num = sc.nextInt();
			s.push(num);
		}
		
		for(int i=0;i<5;i++) {
			System.out.printf("%-4d ", s.pop());
		}
	}
}