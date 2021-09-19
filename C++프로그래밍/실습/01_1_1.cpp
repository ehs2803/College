#include<iostream>

int main(void)
{
	int in1, in2, in3, in4, in5;

	std::cout << "first number input: ";
	std::cin >> in1;
	std::cout << "second number input: ";
	std::cin >> in2;
	std::cout << "third number input: ";
	std::cin >> in3;
	std::cout << "fourth number input: ";
	std::cin >> in4;
	std::cout << "five number input: ";
	std::cin >> in5;

	int result = in1 + in2 + in3 + in4 + in5;
	std::cout << "sum is " << result << std::endl;
}
//20191224