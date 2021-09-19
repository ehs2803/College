#include<iostream>

namespace hybrid
{
	void hyfunc(void)
	{
		std::cout << "so simple function!" << std::endl;
		std::cout << "in namespace hybrid!" << std::endl;
	}
}

int main(void)
{
	using hybrid::hyfunc;
	hyfunc();
}
//20191224