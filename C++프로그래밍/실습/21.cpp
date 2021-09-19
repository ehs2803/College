#include<iostream>
#include<string>
using namespace std;

class car
{
private:
    int speed;
	int gear;
	static const int a = 1;
	string color;
	//const int i; 이것이 선언되면 아래 두개의 함수가 오류가 뜬다.
public:
	car(int s=0, int g=1, string c="white") :speed(s), gear(g), color(c)
	{ }
	void print()
	{
		cout << speed << " " << gear << " " << color << endl;
	}
};

void swap(car* p1, car* p2)
{
	car temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void refrence(car& a, car& b)
{
	car temp;
	temp = a;
	a = b;
	b = temp;
}

int main(void)
{
	car a(1,1);
	car b(2, 2,"red");
	a.print();
	b.print();

	swap(&a, &b);
	a.print();
	b.print();

	refrence(a, b);
	a.print();
	b.print();
}
//20200118