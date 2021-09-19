#include <iostream>
#include <string>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius = 1, string name = "") {
		this->radius = radius; this->name = name;
	}
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
	friend ostream& operator << (ostream& outs, Circle c); 
	friend istream& operator >> (istream& ins, Circle& c); 
};

ostream& operator << (ostream& outs, Circle c) { 
	outs << "(������" << c.radius << "�� " << c.name << ")";
	return outs;
}
istream& operator >> (istream& ins, Circle& c) { 
	cout << "������ >> ";
	int radius;
	ins >> radius;
	c.radius = radius;
	cout << "�̸� >> ";
	string name;
	ins >> name;
	c.name = name;
	return ins;
}

int main() {
	cout << "2019305059 ������" << endl << endl;
	Circle d, w;
	cin >> d >> w; 
	cout << d << w << endl; 
}