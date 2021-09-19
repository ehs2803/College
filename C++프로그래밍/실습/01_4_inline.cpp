#include<iostream>

inline int square(int x)
{
	return x * x;
}

int main(void)
{
	std::cout << square(5) << std::endl;
	std::cout << square(12) << std::endl;
}
//20191224