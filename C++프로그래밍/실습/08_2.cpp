#include<iostream>
using namespace std;

class first
{
public:
	virtual void simple() { cout << "a" << endl; }
};

class two :public first
{
public:
	virtual void simple() { cout << "b" << endl; }
};

int main(void)
{
	first* ptr = new first();
	ptr->simple();
	delete ptr;

	ptr = new two();
	ptr->simple();
	delete ptr;
}
//20200110