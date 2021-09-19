#include<iostream>
#define getmax(x,y) (x>y?x:y)
using namespace std;

template<typename a>
a get_max(a x, a y)
{
	if (x > y) return x;
	else return y;
}

int main(void)
{
	cout << get_max(1, 3) << endl;

	cout << get_max(1.1, 2.5) << endl;

	cout << getmax(1, 5) << endl;
}
//20200122