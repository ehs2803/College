#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	void SetRadius(int radius);
	double GetArea();
};

void Circle::SetRadius(int radius) {
	this->radius = radius;
}

double Circle::GetArea() {
	return 3.14 * radius * radius;
}

int main(void) {
	cout << "2019305059 이현수" << endl <<endl;
	Circle c[3];
	int n;
	for (int i = 0;i < 3;i++) {
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> n;
		c[i].SetRadius(n);
	}
	int count = 0;
	for (int i = 0;i < 3;i++) {
		if (c[i].GetArea() > 100) count++;
	}
	cout << "면적이 100보다 큰 원은 " << count << "개 입니다" << endl;
}