#include<iostream>

int ADDER(int num1 = 1, int num2 = 2)
{
	return num1 + num2;
}

int main(void)
{
	std::cout << ADDER() << std::endl;
	std::cout << ADDER(5) << std::endl;
	std::cout << ADDER(3, 5) << std::endl;
}
//20191224