#include<iostream>
using namespace std;

void half(double& m);

int main(void) {
	cout << "2019305059 ÀÌÇö¼ö" << endl << endl;

	double n = 20;
	half(n);
	cout << n;
}

void half(double& m) {
	m = m / 2;
}