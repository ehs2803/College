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
	cout << "2019305059 ������" << endl <<endl;
	Circle c[3];
	int n;
	for (int i = 0;i < 3;i++) {
		cout << "�� " << i + 1 << "�� ������ >> ";
		cin >> n;
		c[i].SetRadius(n);
	}
	int count = 0;
	for (int i = 0;i < 3;i++) {
		if (c[i].GetArea() > 100) count++;
	}
	cout << "������ 100���� ū ���� " << count << "�� �Դϴ�" << endl;
}