#include<iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	Power operator+(Power op2);
	bool operator==(Power op2);
	Power& operator+=(Power op2);
	Power operator+(int op2);
	Power& operator++();
	Power operator++(int x);
	friend void show(Power a, Power b, Power c);
};

Power Power::operator+(Power op2) {
	Power temp;
	temp.kick = this->kick + op2.kick;
	temp.punch = this->punch + op2.punch;
	return temp;
}

bool Power::operator==(Power op2) {
	if (kick == op2.kick && punch == op2.punch) return true;
	else return false;
}

Power& Power::operator+=(Power op2) {
	kick = kick + op2.kick;
	punch = punch + op2.punch;
	return *this;
}

Power Power::operator+(int op2) {
	Power temp;
	temp.kick = kick + op2;
	temp.punch = punch + op2;
	return temp;
}

Power& Power::operator++() {
	kick++;
	punch++;
	return *this;
}

Power Power::operator++(int x) {
	Power temp = *this;
	kick++;
	punch++;
	return temp;
}

//void show(Power a, Power b, Power c);

int main(void) {
	cout << "2019305059 이현수" << endl << endl;

	Power a(3, 5), b(3, 5), c;
	c = a + b;
	show(a, b, c);
	if (a == b)cout << "두 파워가 같다" << endl<<endl;
	else cout << "두 파워가 같지 않다" << endl<<endl;
	c = a += b;
	a = c + 3;
	show(a, b, c);
	b = ++a;
	c = b++;
	show(a, b, c);
}

void show(Power a, Power b, Power c) {
	cout << "a의 kick = " << a.kick << " " << "punch = " << a.punch << endl;
	cout << "b의 kick = " << b.kick << " " << "punch = " << b.punch << endl;
	cout << "c의 kick = " << c.kick << " " << "punch = " << c.punch << endl << endl;
}