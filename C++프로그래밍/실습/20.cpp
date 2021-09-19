#include<iostream>
#include<string>
using namespace std;

class car
{
private:
	const int id;
	string color;
	static int code;
	static const int company = 123456789; //static const���� �ٷ� �ʱ�ȭ����
public:
	static int numberofcar;
	car() :id(0)
	{
		color = "white";
	}
	car(int id, string s) :id(id), color(s)
	{
		numberofcar++;
	}
	void print() const //const�� ���� �̷��� ���ȭ���Լ����� ���ȭ���� ���� �Լ��� ȣ�����.
	{
		cout << id << " " << color << " " << company << endl;
	}
	void a() const //const�� �ֳ� ���Ĵ� �Լ������ε� �������� ����!!
	{
		cout << "a" << endl;
	}
	void a()
	{
		cout << "b" << endl;
	}
	static void first() //�����Լ��� ��������, �����Լ����� ȣ�Ⱑ��!!
	{
		two();
	}
	static void two() 
	{
		cout << numberofcar <<" "<<company<<endl;
	}
	~car()
	{
		cout << "delete car class" << endl;
		numberofcar--;
	}

};
int car::numberofcar = 0;
int car::code = 1234;

int main(void)
{
	cout << car::numberofcar << endl;
	car::first();

	cout << endl << endl;

	car array[2] = {
		car(1,"white"), car(2, "red")
	};
	for(int i = 0; i < 2; i++)
	{
		(array + i)->print();   //array[i].print(); 
	}

	cout << endl << endl;

	car::first();
}
//20200118