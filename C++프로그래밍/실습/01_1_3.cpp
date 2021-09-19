#include<iostream>

int main(void)
{
	int num;

	std::cout << "input number: ";
	std::cin >> num;

	for (int i = 1; i <= 9; i++)
	{
		std::cout << num << "*" << i << "=" << num * i << std::endl;
	}
}
//20191224