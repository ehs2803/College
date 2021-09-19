#include<iostream>
using namespace std;

class nopersonexception
{
private:
	int persons;
public:
	nopersonexception();
	nopersonexception(int p) { persons = p; };
	int get_person() { return persons; };
};

int main(void)
{
	int pizza_slice = 12;
	int persons = 1;
	int per_person = 0;

	try
	{
		cout << "input pizza slice number: ";
		cin >> pizza_slice;
		cout << "input person number: ";
		cin >> persons;

		if (persons <= 0) throw nopersonexception(persons);
		per_person = pizza_slice / persons;
		cout << "per person pizza is " << per_person << endl;
	}
	catch (nopersonexception e)
	{
		cout << "error: person number " << e.get_person() << "!!"<< endl;
	}
}
//20200122