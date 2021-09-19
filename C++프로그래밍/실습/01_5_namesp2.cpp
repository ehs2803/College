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
	std::cout << "bestcom이 정의한 함수" << std::endl;
}

void progcom::simple(void)
{
	std::cout << "progcom이 정의한 함수" << std::endl;
}
//20191224