#include<iostream>
using namespace std;

void plus1(int& a)
{
	a++;
}

void change(int& a)
{
	a *= -1;
}

int main(void)
{
	int num;
	cout << "input number: ";
	cin >> num;

	plus1(num);
	cout << num << endl;

	change(num);
	cout << num << endl;
}
//20191228