#include<iostream>
#include<string>
using namespace std;

class book
{
private:
	int isbn;
	string name;
public:
	book()
	{
		isbn = 0;
		name="unknown";
	}
	book(int isbn) //��ȯ������(int -> book)
	{
		this->isbn = isbn;
		this->name = "unknown";
	}
	operator int() //const //��ȯ������(book -> int)
	{
		return isbn;
	}
	void print()
	{
		cout << isbn << ":" << name << endl;
	}
};

bool check(int a)
{
	cout << a << endl;
	return true;
}

int main(void)
{
	book b1 = 9782001;
	b1.print();
	b1 = 9783001;
	b1.print();

	cout << endl << endl;

	book b2 = 999999; //��ȯ�����ڽ���!!
	b1.print();
	int isbn = b1; //��ȯ ������ ����!!

	cout << isbn << endl;
	check(b1); //��ȯ ������ ����
}
//20200119