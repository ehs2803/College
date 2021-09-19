#include<iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) :xpos(x), ypos(y)
	{ }
	void show()
	{
		cout << "["<< xpos << ", " << ypos << "]" << endl;
	}
	Point operator-()
	{
		Point pos(-xpos, -ypos);
		return pos;
	}
	friend Point operator~(const Point& a);
};

Point operator~(const Point& a)
{
	Point pos(a.ypos, a.xpos);
	return pos;
}

int main(void)
{
	Point pos1(9, -7);
	pos1.show();

	Point pos2 = -pos1;
	pos2.show();

	(~pos2).show();

	pos2.show();
	return 0;
}
//20200114