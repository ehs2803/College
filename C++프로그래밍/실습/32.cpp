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
	book(int isbn) //변환생성자(int -> book)
	{
		this->isbn = isbn;
		this->name = "unknown";
	}
	operator int() //const //변환연산자(book -> int)
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

	book b2 = 999999; //변환생성자실행!!
	b1.print();
	int isbn = b1; //변환 연산자 실행!!

	cout << isbn << endl;
	check(b1); //변환 연산자 실행
}
//20200119