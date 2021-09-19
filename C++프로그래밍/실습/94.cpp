#include<iostream>
#include<list>
using namespace std;

void print(list<int>& a);
int main(void)
{
	list<int> mylist;

	mylist.push_back(10);
	mylist.push_back(20);
	mylist.push_back(30);
	mylist.push_back(40);

	mylist.insert(mylist.begin(), 5);
	mylist.insert(mylist.end(), 45);
	print(mylist);
}

void print(list<int>& a)
{
	list<int>::iterator it;
	for (it = a.begin(); it != a.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//20200123