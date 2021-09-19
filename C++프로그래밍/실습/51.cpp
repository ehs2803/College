#include<iostream>
using namespace std;

class shape
{
protected:
	int x, y;
public:
	virtual void draw() //가상함수 -> 동적바인딩!!
	{
		cout << "shape draw" << endl;
	}
	void setorigin(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

class rectangle :public shape
{
private:
	int wid, hei;
public:
	void setwid(int a)
	{
		wid = a;
	}
	void sethei(int a)
	{
		hei = a;
	}
	void draw()
	{
		cout << "rectangle draw" << endl;
	}
};

int main(void)
{
	shape* ps = new rectangle();
	ps->draw();
	delete ps;
}
//20200120