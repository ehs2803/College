class Swap<T>{
	public T x, y;
	public Swap(T x, T y) {
		this.x=x;
		this.y=y;
	}
	public void swap() {
		T temp;
		temp= x; x=y; y=temp;
	}
}

public class ch10_7 {
	public static void main(String[] args) {
		Swap<Integer> swapInt = new Swap<Integer>(1,2);
		Swap<Double> swapDouble = new Swap<Double>(1.5, 2.5);
		
		System.out.println(swapInt.x+" "+swapInt.y);
		System.out.println(swapDouble.x+" "+swapDouble.y);
		
		swapInt.swap(); swapDouble.swap();
		
		System.out.println(swapInt.x+" "+swapInt.y);
		System.out.println(swapDouble.x+" "+swapDouble.y);
	}
}
