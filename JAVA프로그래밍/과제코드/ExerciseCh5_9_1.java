class Count{
	public static int scount=0;
	public int count=0;
	public static void sIncrement() {
		scount++;
	}
	public void increment() {
		count++;
	}
}
public class ExerciseCh5_9_1 {
	public static void main(String[] args) {
		Count c = new Count();
		c.increment(); Count.sIncrement(); c.sIncrement();
		System.out.print("Instance Value = "+c.count);
		System.out.println(", Static Value = " + Count.scount);
	}
}
