interface SimpleList{
	void insert(Object obj);
	void delete(Object obj);
	Object find(Object obj);
	int currentCount();
}

class List<T> implements SimpleList{
	int count=0;
	T[] list;
	public List(){
		list=(T[])new Object[10];
	}
	public void insert(Object obj) {
		if(10==count) {
			System.out.println("list is full!!");
		}
		else {
			list[count++]=(T)obj;
		}
	}
	public void delete(Object obj) {
		T temp = (T)obj;
		for(int i=0;i<count;i++) {
			if(list[i]==temp) {
				for(int j=i;j<count-1;j++) {
					list[j]=list[j+1];
				}
				count--;
				return;
			}
		}
		System.out.println(obj+"is not found!!");
	}
	public Object find(Object obj) {
		T temp = (T)obj;
		for(int i=0;i<count;i++) {
			if(list[i]==temp) return i;
		}
		return -1;
	}
	public int currentCount() {
		return count;
	}
}

public class ch10_9 {
	public static void main(String[] args) {
		List<Integer> li = new List<Integer>();
		li.insert(1);li.insert(2);li.insert(3);
		System.out.println(li.currentCount());
		li.delete(1);
		System.out.println(li.currentCount());
		System.out.println(li.find(1));
		System.out.println(li.find(2));
	}
}
