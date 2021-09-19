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
	friend vector operator-(vector v1, vector v2); //연산자중복을 비멤버함수로 선언!!
	vector operator+(vector v2) //연산자중복을 멤버함수로 선언!!
	{
		vector v;
		v.x = this->x + v2.x;
		v.y = this->y + v2.y;
		return v;
	}
	vector& operator=(vector v) //피연산자의 타입에 따라서 할당연산자는 몇개라도 중복하여 정의가능!!
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
	return !(v1 == v2); //중복된 ==연산자를 사용!!
}

ostream& operator<<(ostream & os, const vector & v) // <<연산자 함수는 반드시 비멤버함수로 정의!!
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
<<연산자를 멤버함수로 정의하고 싶다면
vector v1;
v1 << cout;

istream& operator>>(istream& in, vector& v)
{
   in >> v.x >> v.y;
   return in;
}
*/
/*
할당연산자는 멤버함수로
산술연산자와 관계연산자는 비멤버함수로
*/
//20200119