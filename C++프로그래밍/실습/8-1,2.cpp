#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

class NameCircle :public Circle {
	string name;
public:
	NameCircle(int n=0, string name="") :Circle(n) {
		this->name = name;
	}
	string getName() { return name; }
	void setName(string name) { this->name = name; }
	void show() {
		cout << "반지름이 " << getRadius() << "인 " << name << endl;
	}
};

int main(void) {
	cout << "2019305059 이현수" << endl << endl;
	NameCircle pizza[5];
	cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;
	for (int i = 0;i < 5;i++) {
		cout << i + 1 << ">> ";
		int num; string name;
		cin >> num; cin >> name;
		pizza[i].setRadius(num);
		pizza[i].setName(name);
	}
	int most = 0;
	for (int i = 0;i < 5;i++) {
		if (pizza[most].getArea() < pizza[i].getArea()) {
			most = i;
		}
	}
	cout << "가장 면적이 큰 피자는 " << pizza[most].getName() <<"입니다"<< endl;
}

/*
int main(void) {
	cout << "2019305059 이현수" << endl << endl;
	NameCircle waffle(3, "waffle");
	waffle.show();
}*/
