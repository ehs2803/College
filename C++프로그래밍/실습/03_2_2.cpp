#include<iostream>
#include<cstring>
using namespace std;

class Printer
{
private:
	char str[30];
public:
	void setstring(const char* s);
	void showstring();
};
void Printer::setstring(const char* s)
{
	strcpy(str, s);
}
void Printer::showstring()
{
	cout << str << endl;
}

int main(void)
{
	Printer pnt;
	cout << "input string: ";
	char st[20];
	cin >> st;
	pnt.setstring(st);
	pnt.showstring();
}
//20191231
