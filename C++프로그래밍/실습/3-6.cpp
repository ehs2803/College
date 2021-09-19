#include<iostream>
using namespace std;

class Rectangle {
	int width, height;
public:
	Rectangle();
	Rectangle(int w, int h);
	Rectangle(int length);
	bool IsSquare();
};

Rectangle::Rectangle() :Rectangle(1, 1) {}

Rectangle::Rectangle(int w, int h) : width(w), height(h) {}

Rectangle::Rectangle(int length) : Rectangle(length, length) {}

bool Rectangle::IsSquare() {
	if (width == height) return true;
	else return false;
}

int main(void) {
	cout << "2019305059 이현수" << endl<<endl;
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);
	
	if (rect1.IsSquare()) cout << "rect1은 정사각형이다." << endl;
	if (rect2.IsSquare()) cout << "rect2은 정사각형이다." << endl;
	if (rect3.IsSquare()) cout << "rect3은 정사각형이다." << endl;
}