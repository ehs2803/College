#include<iostream>
using namespace std;

int add(int x[], int size);
int add(int x[], int size, int y[]);

int main(void) {
	cout << "2019305059 ������" << endl << endl;
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int c = add(a, 5);
	int d = add(a, 5, b);
	cout << c << endl;
	cout << d << endl;
}

int add(int x[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) sum += x[i];
	return sum;
}

int add(int x[], int size, int y[]) {
	int sum = 0;
	for (int i = 0;i < size;i++) sum += x[i];
	for (int i = 0;i < size;i++)sum += y[i];
	return sum;
}