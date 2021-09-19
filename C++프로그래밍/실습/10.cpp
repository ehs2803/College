#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class point
{
private:
	int x;
	int y;
public:
	/*point()
	{
		x = 0;
		y = 0;
	}*/ 
	point();  //�����ڴ� �������� �ʾƵ� �ڵ�����!!
	point(int x, int y)
	{
		setnum(x, y);
	}
	void setnum(int x, int y)
	{   
		this->x = x;
		this->y = y;
	}
	void pri()
	{
		cout << x << " " << y << endl;
	}
	~point()//�Ҹ��ڴ� �������� �ʾƵ� �ڵ�����!!
	{
		cout << "delete point object!!" << endl;
	}
};
point::point()
{
	setnum(0, 0);
	//x = 0;  y = 0;
}

class mul
{
private:
	const int a;
	char* name;
	string& b;
	
public:
    point p;
    int c;
	mul(int num, const char* iname, int one, int two, int three, string s) :a(num), p(one, two), b(s)
	{                                                                          //const��, ��ü, �������� �ʱ�ȭ����Ʈ�� �ʱ�ȭ!!
		name = new char[strlen(iname) + 1];
	    strcpy(name, iname);
	    c = three;
		cout << b << endl;
	}
	mul(mul& s) :a(s.a), p(s.p), b(s.b)  //��������� : ������ص� �ڵ����� �߰������� ���ڿ�(�����Ҵ�)���� �����ּ� ����!!
	{                                   //�ذ�����δ� char[]�� ���� ��...
		name = new char[strlen(s.name) + 1];
		strcpy(name, s.name);
		c = s.c;
	}
	void setname(const char* edit)
	{
		delete[]name;
		name = new char[strlen(edit) + 1];
		strcpy(name, edit);
	}
	void print();
	~mul()
	{
		delete[]name;
		cout <<"delete mul object!!"<< endl;
	}
};
void mul::print()
{
	cout << a << " " << name << " " << c << endl;;
}

void display(mul obj)  //��ü�� ������ �����ϴ� ��쿡 ��������� ���!!
{
	cout << obj.c << endl;
}

int main(void)
{
	int n = 3;
	mul ex1(n, "aaa", 1, 2, 3, "string"); //mul(3, "aaa", 1, 2, n, 4); possible
	ex1.print();
	ex1.p.pri();

	cout << endl << endl;

	mul ex2(ex1);
	ex2.setname("bbb");
	ex2.print();

	cout << endl << endl;

	mul ex3 = ex1;
	ex3.setname("ccc");
	ex3.print();

	cout << endl << endl;

	display(ex3);

	cout << endl << endl;

	point a;
	a.pri();

	cout << endl << endl;

	point b(8, 9);
	b.pri();

	cout << endl << endl;
}
/*
[������ ����Լ�]

1. ����Ʈ ������
   point() { }

2. ����Ʈ �Ҹ���
   ~point() { }

3. ����Ʈ ���� ������
   point(point& p)
   {
      x=p.x; y=p.y;
   }

4. ����Ʈ �Ҵ� ������
   point& operator=(point& p)
   {
      x=p.x; y=p.y;
	  return *this;
   }
*/
//20200118