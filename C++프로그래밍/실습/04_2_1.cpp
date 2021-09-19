#include<iostream>
using namespace std;

class point
{
private:
	int xpos;
	int ypos;
public:
	void input(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void show() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class circle
{
private:
	int rad;
	point center;
public:
	void input(int x, int y, int r)
	{
		rad = r;
		center.input(x, y);
	}
	void show() const
	{
		cout << "radius: " << rad << endl;
		center.show();
	}
};

class ring
{
private:
	circle incircle;
	circle outcircle;
public:
	void input(int inx, int iny, int inr, int outx, int outy, int outr)
	{
		incircle.input(inx, iny, inr);
		outcircle.input(outx, outy, outr);
	}
	void show() const
	{
		cout << "inner circle info..." << endl;
		incircle.show();
		cout << "outter circle info..." << endl;
		outcircle.show();
	}
};

int main(void)
{
	ring r;
	r.input(1, 1, 4, 2, 2, 9);
	r.show();
}
//20191231