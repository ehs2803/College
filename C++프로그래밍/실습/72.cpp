#include<iostream>
using namespace std;

int main(void)
{
	int pizza_slice = 12;
	int person = 0;
	int per_person = 0;

	try
	{
		cout << "input pizza slice number: ";
		cin >> pizza_slice;
		cout << "input person number: ";
		cin >> person;

		if (person < 0) throw "negative";
		if (person == 0) throw person;
		per_person = pizza_slice / person;
		cout << "per person pizza is " << per_person << endl;
	}
	catch (const char* e)
	{
		cout << "error: person number " << e << endl;
	}
	catch (int e)
	{
		cout << "error: person number " << e << endl;
	}
}
//20200122