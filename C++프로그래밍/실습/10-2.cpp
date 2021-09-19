#include<iostream>
using namespace std;

template<class T>
bool equalArrays(T a[], T b[], int c) {
	for (int i = 0;i < c;i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

int main(void) {
	cout << "2019305059 이현수" << endl << endl;

	int x[] = { 1,10,100,5,4 };
	int y[] = { 1,10,100,5,4 };
	if (equalArrays(x, y, 5))cout << "같다"<<endl;
	else cout << "다르다";

	double a[] = { 1.0,2.0 };
	double b[] = { 1.1,2.0 };
	if (equalArrays(a, b, 2))cout << "같다";
	else cout << "다르다";
}