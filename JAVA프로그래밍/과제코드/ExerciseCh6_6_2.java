class BaseClass{
	public boolean equals(Object obj) {
		if(getClass() == obj.getClass()) return true;
		else return false;
	}
}
class DerivedClass extends BaseClass{}
public class ExerciseCh6_6_2 {
	public static void main(String[] args) {
		BaseClass b1 = new BaseClass();
		BaseClass b2 = new BaseClass();
		DerivedClass d1 = new DerivedClass();
		DerivedClass d2 = new DerivedClass();
		if(b1.equals(d1)) System.out.println("derived equals base.");
		if(d1.equals(b1)) System.out.println("base equals derived.");
		if(b1.equals(b2)) System.out.println("base equals base.");
		if(d1.equals(d2)) System.out.println("derived equals derived.");
	}
}
