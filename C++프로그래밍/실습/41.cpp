#include<iostream>
using namespace std;

class A
{
public:
	int x;
	void sub()
	{
		cout << "A class" << endl;
	}
};

class B
{
public:
	int x;
	void sub()
	{
		cout << "B class" << endl;
	}
};

class sub :public A, public B
{

};

int main(void)
{
	sub obj;
	obj.A::x = 10;
	obj.A::sub();
	obj.B::sub();
}
//20200120