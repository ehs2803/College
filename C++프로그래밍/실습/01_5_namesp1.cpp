#include<iostream>

namespace bestcomp1
{
	void simple(void)
	{
		std::cout << "bestcom이 정의한 함수" << std::endl;
	}
}

namespace progcom1
{
	void simple(void)
	{
		std::cout << "progcom이 정의한 함수" << std::endl;
	}
}

int main(void)
{
	bestcomp1::simple();
	progcom1::simple();
}
//20191224