#include<iostream>

void num(int a, int b)
{
	std::cout << a <<' '<< b << std::endl;
}

void cha(char a, char b)
{
	std::cout << a << ' ' << b << std::endl;
}

void dou(double a, double b)
{
	std::cout << a << ' ' << b << std::endl;
}

int main(void)
{
	num(30, 20);
	cha('Z', 'A');
	dou(5.555, 1.111);
}
//20191224