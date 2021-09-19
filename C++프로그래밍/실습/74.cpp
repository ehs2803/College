#include<iostream>
using namespace std;

class parentexception
{
public:
	void display() { cout << "parentexception" << endl; }
};

class childexception :public parentexception
{
public:
	void display() { cout << "childexception" << endl; }
};

int main(void)
{
	try
	{
		throw childexception();
	}
	catch(parentexception& e) //자식클래스가 부모클래스에 연결이됨!!
	{
		e.display();
	}
	catch (childexception & e) //이것을 더 위에 위치시키면 자식클래스display가 반환됨!!
	{
		e.display();
	}
}
//20200122