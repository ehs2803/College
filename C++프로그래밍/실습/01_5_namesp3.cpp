#include<iostream>

namespace bestcom
{
	void simple(void);
}

namespace bestcom
{
	void pretty(void);
}

namespace progcom
{
	void simple(void);
}

namespace progcom
{
	void pretty(void);
}

int main(void)
{
	bestcom::simple();
}

void bestcom::simple(void)
{
	std::cout << "bestcom�� ������ �Լ�" << std::endl;
	pretty();
	progcom::simple();
}

void bestcom::pretty(void)
{
	std::cout << "so pretty!!" << std::endl;
}

void progcom::simple(void)
{
	std::cout << "progcom�� ������ �Լ�" << std::endl;
}
//20191224