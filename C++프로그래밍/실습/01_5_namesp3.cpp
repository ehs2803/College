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
	std::cout << "bestcom이 정의한 함수" << std::endl;
	pretty();
	progcom::simple();
}

void bestcom::pretty(void)
{
	std::cout << "so pretty!!" << std::endl;
}

void progcom::simple(void)
{
	std::cout << "progcom이 정의한 함수" << std::endl;
}
//20191224