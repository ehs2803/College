#include<iostream>
using namespace std;

class base
{
	int a;
public:
	base(int a)
	{
		cout << "base make" << endl;
		this->a = a;
	}
	virtual void print() = 0; //순수가상함수정의 -> 추상클래스가 된다 -> 추상클래스는 객체생성 못함(포인터변수 생성 가능)!!
	virtual ~base()
	{
		cout << "base delete" << endl;
	}
};

class upper :public base
{
	int b;
public:
	upper(int a, int b) :base(a)
	{
		cout << "upper make" << endl;
		this->b = b;
	}
	void print()
	{
		cout << "upper print" << endl;
	}
	~upper()
	{
		cout << "upper delete" << endl;
	}
};

int main(void)
{
	cout << "부모 클래스 포인트 이용" << endl; // 14줄에 선언하지 virtual를 선언하지 않으면 자식클래스소멸자가 되지 않음.
	base* pb = new upper(0, 0);
	pb->print();
	delete pb;

	cout << endl << endl;

	cout << "자식 클래스 포인트 이용" << endl;
	upper* pu = new upper(0, 0);
	pu->print();
	delete pu;
}
//20200120