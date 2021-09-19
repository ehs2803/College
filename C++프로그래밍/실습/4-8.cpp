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
	cout << "2019305059 ������" << endl << endl;
	int n, r;

	cout << "���� ���� >> "; cin >> n;
	Circle* p = new Circle[n];

	for (int i = 0;i < n;i++) {
		cout << "�� " << i + 1 << "�� ������ >> ";
		cin >> r;
		p[i].SetRadius(r);
	}
	int count = 0;
	for (int i = 0;i < n;i++) {
		if (p[i].GetArea() > 100) count++;
	}
	cout << "������ 100���� ū ���� " << count << "�� �Դϴ�" << endl;

	delete[]p;
}