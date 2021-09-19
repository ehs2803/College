#include<iostream>
#include<string>
using namespace std;

class Date {
	int year;
	int month;
	int day;
public:
	Date(int y, int m, int d);
	Date(string str, string st, string ss);
	int getYear();
	int getMonth();
	int getDay();
	void show();
};

Date::Date(int y, int m, int d) :year(y), month(m), day(d){ }

Date::Date(string str, string st, string s) {
	year = stoi(str);
	month = stoi(st);
	day = stoi(s);
}

int Date::getYear() { return year; }

int Date::getMonth() { return month; }

int Date::getDay() { return day; }

void Date::show() {
	cout << year << "년" << month << "월" << day << "일" << endl;
}

int main(void) {
	cout << "2019305059 이현수" << endl << endl;
	Date birth(2014, 3, 20);
	Date independenceDay("1945","8","15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}