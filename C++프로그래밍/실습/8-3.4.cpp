#include<iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint :public Point {
	string name;
public:
	ColorPoint(int a=0, int b=0, string name="BLACK") :Point(a, b) {
		this->name = name;
	}
	void setPoint(int a, int b) { move(a, b); }
	void setColor(string name) { this->name = name; }
	void show() {
		cout << name << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl;
	}
};
///*
int main(void) {
	cout << "2019305059 이현수" << endl << endl;
	ColorPoint zeroPoint;
	zeroPoint.show();

	ColorPoint cp(5, 5);
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}//*/
/*
int main(void) {
	cout << "2019305059 이현수" << endl << endl;
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}*/