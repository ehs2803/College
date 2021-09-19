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
	point();  //생성자는 선언하지 않아도 자동생성!!
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
	~point()//소멸자는 선언하지 않아도 자동생성!!
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
	{                                                                          //const형, 객체, 참조형은 초기화리스트로 초기화!!
		name = new char[strlen(iname) + 1];
	    strcpy(name, iname);
	    c = three;
		cout << b << endl;
	}
	mul(mul& s) :a(s.a), p(s.p), b(s.b)  //복사생성장 : 선언않해도 자동으로 추가되지만 문자열(동적할당)에서 같은주소 공유!!
	{                                   //해결법으로는 char[]형 선언 등...
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

void display(mul obj)  //객체를 값으로 전달하는 경우에 복사생성자 사용!!
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
[디폴드 멤버함수]

1. 디폴트 생성자
   point() { }

2. 디폴트 소멸자
   ~point() { }

3. 디폴트 복사 생성자
   point(point& p)
   {
      x=p.x; y=p.y;
   }

4. 디폴트 할당 연산자
   point& operator=(point& p)
   {
      x=p.x; y=p.y;
	  return *this;
   }
*/
//20200118