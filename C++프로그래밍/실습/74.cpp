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
	catch(parentexception& e) //�ڽ�Ŭ������ �θ�Ŭ������ �����̵�!!
	{
		e.display();
	}
	catch (childexception & e) //�̰��� �� ���� ��ġ��Ű�� �ڽ�Ŭ����display�� ��ȯ��!!
	{
		e.display();
	}
}
//20200122