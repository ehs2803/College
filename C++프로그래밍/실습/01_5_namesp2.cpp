#include<iostream>

namespace bestcom
{
	void simple(void);
}

namespace progcom
{
	void simple(void);
}

int main(void)
{
	bestcom::simple();
	progcom::simple();
}

void bestcom::simple(void)
{
	std::cout << "bestcom�� ������ �Լ�" << std::endl;
}

void progcom::simple(void)
{
	std::cout << "progcom�� ������ �Լ�" << std::endl;
}
//20191224