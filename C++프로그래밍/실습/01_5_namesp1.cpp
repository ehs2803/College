#include<iostream>

namespace bestcomp1
{
	void simple(void)
	{
		std::cout << "bestcom�� ������ �Լ�" << std::endl;
	}
}

namespace progcom1
{
	void simple(void)
	{
		std::cout << "progcom�� ������ �Լ�" << std::endl;
	}
}

int main(void)
{
	bestcomp1::simple();
	progcom1::simple();
}
//20191224