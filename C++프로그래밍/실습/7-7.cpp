#include<iostream>
using namespace std;

class Matrix {
	int num[4];
public:
	Matrix(int a=0, int b=0, int c=0, int d=0) {
		num[0] = a; num[1] = b; num[2] = c; num[3] = d;
	}
	void show() {
		cout << "Matrix = { ";
		for (int i = 0;i < 4;i++) {
			cout << num[i] << ' ';
		}
		cout << "}" << endl;
	}
	/*
	void operator>>(int a[]) {
		for (int i = 0;i < 4;i++) {
			a[i] = num[i];
		}
	}
	void operator<<(int a[]) {
		for (int i = 0;i < 4;i++) {
			num[i] = a[i];
		}
	}
	*/
	friend void operator>>(Matrix a, int b[]);
	friend void operator<<(Matrix& a, int b[]);
};

void operator>>(Matrix a, int b[]) {
	for (int i = 0;i < 4;i++) {
		b[i] = a.num[i];
	}
}

void operator<<(Matrix& a, int b[]) {
	for (int i = 0;i < 4;i++) {
		a.num[i] = b[i];
	}
}

int main(void) {
	cout << "2019305059 ÀÌÇö¼ö" << endl << endl;
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };
	a >> x;
	b << y;

	for (int i = 0;i < 4;i++) {
		cout << x[i] << ' ';
	}
	cout << endl;
	b.show();
}