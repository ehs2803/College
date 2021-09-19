#include<iostream>

int main(void)
{
	char name[10];
	char phone[15];

	std::cout << "input name: ";
	std::cin >> name;
	std::cout << "phone number input: ";
	std::cin >> phone;

	std::cout << "name is " << name << ", phone number is " << phone << std::endl;
}
//20191224