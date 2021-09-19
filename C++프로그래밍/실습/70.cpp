#include<iostream>
using namespace std;

int main(void)
{
	int pizza = 0;
	int person = -1;
	int slice = 0;

	try
	{
		cout << "intput pizza: ";
		cin >> pizza;
		cout << "input person: ";
		cin >> person;

		if (person == 0)
		{
			throw person;
		}
		slice = pizza / person;
		cout << "pizza per person is " << slice << endl;
	}
	catch (int e) //catch(...) -> 모든예외를 잡아서  처리할수 있음!!
	{
		cout << "person num is " << e << endl;
	}
}
//20200122