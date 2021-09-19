#include<iostream>
using namespace std;

int big(int a, int b);
int big(int a, int b, int c);

int main(void) {
	cout << "2019305059 ÀÌÇö¼ö" << endl << endl;
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << endl;
}

int big(int a, int b) {
	if (a > b) {
		if (a < 100)return a;
		else return 100;
	}
	else {
		if (b < 100)return b;
		else return 100;
	}
}

int big(int a, int b, int c) {
	if (a > b) {
		if (a < c)return a;
		else return c;
	}
	else {
		if (b < c)return b;
		else return c;
	}
}