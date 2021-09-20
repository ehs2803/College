import java.util.Scanner;

class Stack{
	private int stack[];
	int sp=0;
	Stack(){
		stack = new int[100];
	}
	Stack(int size){
		stack = new int[size];
	}
	public void push(int data) {
		stack[sp++]=data;
	}
	public int pop() {
		return stack[--sp];
	}
}

public class ch5_8 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Stack s=new Stack();
		int cnt=0;
		
		System.out.print("input: ");
		while(true) {
			int num = sc.nextInt();
			if(num==0) break;
			s.push(num);
			cnt++;
		}	
		
		System.out.print("stack pop result: ");
		for(int i=0;i<cnt;i++) {
			System.out.printf("%-4d ", s.pop());
		}
		
		sc.close();
	}
}
