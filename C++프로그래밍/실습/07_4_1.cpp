#include<iostream>
using namespace std;

class rectangel
{
private:
	int width;
	int height;
public:
	rectangel(int wid, int hei)
		:width(wid), height(hei)
	{ }
	void show()
	{
		cout << "¸éÀû: " << width * height << endl;
	}
};

class square :public rectangel
{
public:
	square(int side)
		:rectangel(side,side)
	{ }
};

int main(void)
{
	rectangel rec(4, 3);
	rec.show();

	square sqr(7);
	sqr.show();
}
//20200109