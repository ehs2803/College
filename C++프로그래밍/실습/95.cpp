#include<iostream>
#include<set>
using namespace std;

template<typename T>
void printlist(const T& container);

int main(void)
{
	set<int> myset;
	multiset<int> mymultiset;

	myset.insert(1);
	myset.insert(2);
	myset.insert(3);

	mymultiset.insert(myset.begin(), myset.end());
	mymultiset.insert(3);
	mymultiset.insert(4);

	printlist(myset);
	printlist(mymultiset);
}

template<typename T>
void printlist(set<T>& container)
{
	set<T>::iterator it;
	for (it = container.begin(); it != container.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//20200123 error
/*
Å½»ö
set<int>::iterator pos=my_set.find(2);
if(pos!=my_set.end())
{
   cout<<*pos<<"fint!!"<<endl;
}
else
{
   cout<<"not found"<<endl;
}
*/