#include<cstring>
#include <iostream>
using namespace std;

namespace comp
{
	enum {clerk, senior, assist, manager};

	void show(int pos)
	{
		switch (pos)
		{
		case clerk:
			cout << "사원" << endl;
			break;
		case senior:
			cout << "주임" << endl;
			break;
		case assist:
			cout << "대리" << endl;
			break;
		case manager:
			cout << "과장" << endl;
			break;
		}
	}
}

class namecard
{
private:
	char* name;
	char* company;
	char* phone;
	int position;
public:
	namecard(char* _name, char* _company, char* _phone, int pos)
		:position(pos)
	{
		name = new char[strlen(_name) + 1];
		company = new char[strlen(_company) + 1];
		phone = new char[strlen(_phone) + 1];
		strcpy(name, _name);
		strcpy(company, _company);
		strcpy(phone, _phone);
	}
	void show()
	{

	}
	~namecard()
	{
		delete[]name;
		delete[]company;
		delete[]phone;
	}
};

int main(void)
{
	namecard manclerk("Lee", "ABCEng", "010-1111-2222", comp::clerk);
	manclerk.show();
}
//20191231