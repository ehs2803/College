#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " 인 원" << endl; }
	friend void operator++(Circle& a);
	friend Circle operator++(Circle& a, int b);
};

void operator++(Circle& a) {
	a.radius++;
}

Circle operator++(Circle& a, int b) {
	Circle temp = a;
	a.radius++;
	return temp;
}

int main(void) {
	cout << "2019305059 이현수" << endl << endl;
	Circle a(5),b(4);
	++a;
	b = a++;
	a.show();
	b.show();
}