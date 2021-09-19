#include<iostream>
using namespace std;

class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g;blue = b; }
	void SetColor(int r, int g, int b) { red = r; green = g;blue = b; }
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
};

int main(void) {
	cout << "2019305059 ÀÌÇö¼ö" << endl << endl;

	Color screenColor(255, 0, 0);
	Color* p;
	p = &screenColor;
	p->show();
	Color colors[3];
	p = colors;
	
	p->SetColor(255, 0, 0); 
	(p+1)->SetColor(0, 255, 0); 
	(p+2)->SetColor(0, 0, 255);

	for (int i = 0;i < 3;i++) {
		(p+i)->show();
	}
}