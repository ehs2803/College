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
	virtual void print() = 0; //���������Լ����� -> �߻�Ŭ������ �ȴ� -> �߻�Ŭ������ ��ü���� ����(�����ͺ��� ���� ����)!!
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
	cout << "�θ� Ŭ���� ����Ʈ �̿�" << endl; // 14�ٿ� �������� virtual�� �������� ������ �ڽ�Ŭ�����Ҹ��ڰ� ���� ����.
	base* pb = new upper(0, 0);
	pb->print();
	delete pb;

	cout << endl << endl;

	cout << "�ڽ� Ŭ���� ����Ʈ �̿�" << endl;
	upper* pu = new upper(0, 0);
	pu->print();
	delete pu;
}
//20200120