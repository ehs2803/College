#include<iostream>
using namespace std;

typedef struct {
	int xpos;
	int ypos;
}POINT;

POINT& pntadder(const POINT& p1, const POINT& p2)
{
	POINT* pptr = new POINT;
	pptr->xpos = p1.xpos + p2.xpos;
	pptr->ypos = p1.ypos + p2.ypos;
	return *pptr;
}

int main(void)
{
	POINT* pptr1 = new POINT;
	pptr1->xpos = 3;
	pptr1->ypos = 30;

	POINT* pptr2 = new POINT;
	pptr2->xpos = 70;
	pptr2->ypos = 7;

	POINT& pref=pntadder(*pptr1, *pptr2);
	cout << "[" << pref.xpos << ", " << pref.ypos << "]" << endl;
	delete pptr1;
	delete pptr2;
	delete& pref;
}
//20191228