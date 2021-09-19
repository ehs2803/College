#include<iostream>
using namespace std;
int divpizza(int pizza, int persons);

int main(void)
{
	int pizza_slice = 0;
	int person = 0;
	int slice_per_person = 0;

	try
	{
		cout << "input pizza slice: ";
		cin >> pizza_slice;
		cout << "input person number: ";
		cin >> person;
		slice_per_person = divpizza(pizza_slice, person);
		cout << "pizza per person is " << slice_per_person << endl;
	}
	catch (int e)
	{
		cout << "person number is " << e << endl;
	}
}

int divpizza(int pizza, int persons)
{
	/*if (persons == 0)
	{
		throw persons;
	}
	return pizza / persons;
	*/
	try
	{
	    if(persons==0)
		{
		   throw persons;
		}
		return pizza/persons;
	}
	catch(int e)
	{
	    cout<<"person number is "<<e<<"divpizza"<<endl;
		throw;
	}	
}
//20200122