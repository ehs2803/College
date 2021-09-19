#include<iostream>
using namespace std;

bool Ispositive(int num)
{
	if (num <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main(void)
{
	bool ispos;
	int num;
	cout << "Input number: ";
	cin >> num;

	ispos = Ispositive(num);
	if (ispos)
	{
		cout << "positive number" << endl;
	}
	else
	{
		cout << "negative number" << endl;
	}
}
//20191228