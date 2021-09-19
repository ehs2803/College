#include<iostream>
#include<assert.h>
using namespace std;

class myarray
{
	friend ostream& operator<<(ostream& os, myarray& a);
private:
	int* data;
	int size;
public:
	myarray(int size = 10)
	{
		this->size = (size > 0 ? size : 10);
		data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = 0;
		}
	}
	~myarray()
	{
		delete[]data;
		data = NULL;
	}
	int getsize() const
	{
		return size;
	}
	myarray& operator=(myarray a)
	{
		if (&a != this)
		{
			delete[]data;
			size = a.size;
			data = new int[size];

			for (int i = 0; i < size; i++)
			{
				data[i] = a.data[i];
			}
		}
		return *this;
	}
	int& operator[](int i)
	{
		assert(0 <= i && i < size);
		return data[i];
	}
};

ostream& operator<<(ostream& os, myarray& a) //배열의 경우에는 myarray& a에서 &를 꼭 붙여야 정상작동함!!
{
	for (int i = 0; i < a.size; i++)
	{
		os << a.data[i] << " ";
	}
	os << endl;
	return os;
}

int main(void)
{
	myarray a1(10);

	a1[0] = 1;
	a1[1] = 2;
	a1[2] = 3;
	a1[3] = 4;
	cout << a1;
}
//20200119