#include<iostream>
using namespace std;

int& refret(int& ref)
{
	ref++;
	return ref;
}

int main(void)
{
	int num1 = 1;
	int num2 = refret(num1);

	num1 += 1;
	num2 += 100;
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
}
//20191228