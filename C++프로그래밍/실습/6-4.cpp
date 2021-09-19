#include<iostream>
using namespace std;

class MyVector {
	int* mem;
	int size;
public:
	MyVector(int n=100, int val=0);
	~MyVector() { delete[]mem; }
	void show() {
		cout << "size = " << size << endl;
		cout << "원소값 = " << mem[0] << endl<<endl;
	}
};

MyVector::MyVector(int n, int val) {
	mem = new int[n];
	size = n;
	for (int i = 0;i < size;i++)mem[i] = val;
}

int main(void) {
	cout << "2019305059 이현수" << endl << endl;
	MyVector a;
	MyVector b(5);
	MyVector c(10, 1);

	cout << "[MyVector a]"<<endl;
	a.show();cout << "[MyVector b(5)]"<<endl;
	b.show();cout << "[MyVector c(10, 1)]"<<endl;
	c.show();

}