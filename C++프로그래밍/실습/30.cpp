#include<iostream>
using namespace std;

class date
{
private:
	int year;
	int month;
	int day;
	friend int printsub(date c); //전역함수를 프렌드로!!
    friend class control; //클래스를 프렌드로!!
	friend bool equal(date d1, date d2); //비교할때 프렌드함수를 사용하기도함!!
	friend date add(date d1, date d2); //두개의 객체를 연산할때 프렌드함수를 사용!!
public:
	date()
	{
		year = 0; month = 0; day = 0;
	}
	date(int year, int month, int day)
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}
	void print()
	{
		cout << year << "." << month << "." << day << endl;
	}
};

class control
{
private:
	int code;
public:
	control(int a=0) :code(a)
	{ }
	void shift(date& c, int year)
	{
		c.year = year;
	}

};

int printsub(date c) //void printsub(date& c) 가능!!
{
	return c.year;
}

bool equal(date d1, date d2)
{
	return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
}

date add(date d1, date d2)
{
	date sum;
	sum.year = d1.year + d2.year;
	sum.month = d1.month + d2.month;
	sum.day = d1.day + d2.day;
	return sum;
}

int main(void)
{
	date d1(2020, 1, 1), d2(2020, 1, 1), d3(2019, 2, 5);
	control con;

	cout<<equal(d1, d2)<<endl;
	cout<<equal(d2, d3)<<endl;

    cout<< printsub(d1)<<endl;
	con.shift(d1, 2021);
	cout<< printsub(d1)<<endl;

	date d4sum = add(d1, d2);
	d4sum.print();
}
//20200119