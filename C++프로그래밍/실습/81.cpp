#include<iostream>
using namespace std;

template<typename T=int>//디폴트값선정가능!!
class box
{
	T data;
public:
	box() {  }
	void set(T a)
	{
		data = a;
	}
	T get();
};

template<typename T>
T box<T>::get()
{
	return data;
}

int main(void)
{
	box<int> a;
	a.set(100);
	cout << a.get() << endl;

	box<double> b;
	b.set(3.14);
	cout << b.get() << endl;

	box<> c;
	c.set(1);
	cout << c.get() << endl;
}
//20200122