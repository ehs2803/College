#include<iostream>
#include<cstring>
using namespace std;

class myfriendinfo
{
private:
	char* name;
	int age;
public:
	myfriendinfo(const char* fname, int fage) :age(fage)
	{
		name = new char[strlen(fname) + 1];
		strcpy(name, fname);
	}
	void showfriendinfo()
	{
		cout << "name: " << name << endl;
		cout << "age: " << age << endl;
	}
	~myfriendinfo()
	{
		delete[]name;
	}
};

class detailinfo :public myfriendinfo
{
private:
	char* addr;
	char* phone;
public:
	detailinfo(const char* fname, int fage, const char* add, const char* phon)
		:myfriendinfo(fname, fage)
	{
		addr = new char[strlen(add) + 1];
		phone = new char[strlen(phon) + 1];
		strcpy(addr, add);
		strcpy(phone, phon);
	}
	void show()
	{
		showfriendinfo();
		cout << "address: " << addr << endl;
		cout << "phone: " << phone << endl;
	}
	~detailinfo()
	{
		delete[]addr;
		delete[]phone;
	}
};

int main(void)
{
	detailinfo fren1("������", 22, "�泲 �ƻ�", "010-1234-0000");
	detailinfo fren2("���ּ�", 19, "��� ��õ", "010-3333-0000");
	fren1.show();
	fren2.show();
}
//20200109