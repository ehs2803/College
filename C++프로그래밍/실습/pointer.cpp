#include<iostream>
using namespace std;

void SwapArray(int* p, int* q, int size);
void PrintArray(int* p, int size);

int main(void) {
	cout << "2019305059 ������" << endl << endl;
	int a[] = { 1,2,3,4,5 };
	int b[]{ 9,8,7,6,5 };
	cout << "�迭 a = ";	PrintArray(a, 5);
	cout << "�迭 b = ";	PrintArray(b, 5);
	SwapArray(a, b, 5);
	cout << "�迭 a = ";	PrintArray(a, 5);
	cout << "�迭 b = ";	PrintArray(b, 5);
}

void SwapArray(int* p, int* q, int size) {
	cout << "SwapArray() ����..." << endl;
	int* temp = new int[size];
	for (int i = 0;i < size;i++) {
		*(temp + i) = *(p + i);
	}
	for (int i = 0;i < size;i++) {
		*(p + i) = *(q + i);
	}
	for (int i = 0;i < size;i++) {
		*(q + i) = *(temp + i);
	}
	delete[]temp;
}

void PrintArray(int* p, int size) {
	for (int i = 0;i < size;i++) {
		cout << *(p+i) << " ";
	}
	cout << endl;
}