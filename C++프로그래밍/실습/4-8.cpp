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
	cout << "2019305059 이현수" << endl << endl;
	int n, r;

	cout << "원의 개수 >> "; cin >> n;
	Circle* p = new Circle[n];

	for (int i = 0;i < n;i++) {
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> r;
		p[i].SetRadius(r);
	}
	int count = 0;
	for (int i = 0;i < n;i++) {
		if (p[i].GetArea() > 100) count++;
	}
	cout << "면적이 100보다 큰 원은 " << count << "개 입니다" << endl;

	delete[]p;
}