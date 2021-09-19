#include<iostream>
using namespace std;

class Rectangle {
public:
	int width;
	int height;
	void setwidth(int n);
	void setheight(int n);
	int getArea();
};

void Rectangle::setwidth(int n) {
	width = n;
}

void Rectangle::setheight(int n) {
	height = n;
}

int Rectangle::getArea() {
	return width * height;
}

int main(void) {
	Rectangle rect;
	rect.setwidth(3); 
	rect.setheight(5);
	cout << "사각형의 면적은 " << rect.getArea() << endl;
}