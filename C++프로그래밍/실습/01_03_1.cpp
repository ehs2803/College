#include<iostream>

int box(int a, int b, int c)
{
	return a * b * c;
}

int box(int a, int b)
{
	return a * b * 1;
}

int box(int a)
{
	return a * 1 * 1;
}

int main(void)
{
	std::cout << "[3, 3, 3] : " << box(3, 3, 3) << std::endl;
	std::cout << "[5, ,5, D] : " << box(5, 5) << std::endl;
	std::cout << "[7, D, D] : " << box(7) << std::endl;
}
//20191224