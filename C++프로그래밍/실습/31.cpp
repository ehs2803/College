#include<iostream>
using namespace std;

class vector
{
private:
	double x, y;
public:
	vector(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}
	void print()
	{
		cout << "(" << x << ", " << y << ")" << endl;
	}
	friend vector operator-(vector v1, vector v2); //�������ߺ��� �����Լ��� ����!!
	vector operator+(vector v2) //�������ߺ��� ����Լ��� ����!!
	{
		vector v;
		v.x = this->x + v2.x;
		v.y = this->y + v2.y;
		return v;
	}
	vector& operator=(vector v) //�ǿ������� Ÿ�Կ� ���� �Ҵ翬���ڴ� ��� �ߺ��Ͽ� ���ǰ���!!
	{
		this->x = v.x;
		this->y = v.y;
		return *this;
	}
	vector& operator=(double a) 
	{
		this->x = a;
		this->y = a;
		return *this;
	}
	friend bool operator==(vector v1, vector v2);
	friend bool operator!=(vector v1, vector v2);
	friend ostream& operator<<(ostream& os, const vector& v);
};

vector operator-(vector v1, vector v2)
{
	vector v;
	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	return v;
}

bool operator==(vector v1, vector v2)
{
	return v1.x == v2.x && v1.y == v2.y;
}
bool operator!=(vector v1, vector v2)
{
	return !(v1 == v2); //�ߺ��� ==�����ڸ� ���!!
}

ostream& operator<<(ostream & os, const vector & v) // <<������ �Լ��� �ݵ�� �����Լ��� ����!!
{
	os << "(" << v.x << ", " << v.y << ")" << endl;
	return os;
}

int main(void)
{
	vector v1(1, 1), v2(2, 2), v3;

	v3 = v1 + v2;
	v3.print();

	v3 = v2 - v1;
	v3.print();

	cout << endl << endl;

	vector v4, v5;
	v4 = v5 = v1;
	v4.print();
	v5.print();

	cout << endl << endl;

	vector v6;
	v6 = 5;
	v6.print();
	v4 = 6;
	v4.print();

	cout << endl << endl;

	bool a = (v1 == v2);
	bool b = (v1 != v2);
	cout << a <<" "<<b<< endl;

	cout << endl << endl;

	cout << v1 << v2 << v3;
}
/*
<<�����ڸ� ����Լ��� �����ϰ� �ʹٸ�
vector v1;
v1 << cout;

istream& operator>>(istream& in, vector& v)
{
   in >> v.x >> v.y;
   return in;
}
*/
/*
�Ҵ翬���ڴ� ����Լ���
��������ڿ� ���迬���ڴ� �����Լ���
*/
//20200119