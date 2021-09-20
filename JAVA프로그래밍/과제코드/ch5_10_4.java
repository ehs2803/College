import java.util.Scanner;

class Sort{
	void swap(int v[], int i, int j) {
		int temp;
		temp = v[i];
		v[i] = v[j];
		v[j] = temp;
	}
	public void Qsort(int a[], int left, int right) {
		int pe;
		int i, last;
		
		if(left>=right) return;
		pe = (left+right)/2;
		swap(a, left, pe);
		last = left;
		for(i = left+1; i<=right; i++)
			if(a[i]<a[left]) swap(a, ++last, i);
		swap(a, left, last);
		Qsort(a, left,last-1);
		Qsort(a, left+1, right);
	}
}

public class ch5_10_4 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
	    int a[] = new int[100];
	    Sort s = new Sort();
		int cnt=0;
		
		System.out.print("input: ");
		while(true) {
			int num = sc.nextInt();
			if(num==0) break;
			a[cnt]=num;
			cnt++;
		}	
		
		s.Qsort(a, 0, cnt-1);
		
		System.out.print("quick sort result: ");
		for(int i=0;i<cnt;i++) {
			System.out.print(a[i]+" ");
		}
		
		sc.close();
	}
}
