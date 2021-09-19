#include<iostream>

int main(void)
{
	char name[100];
	char lang[200];

	std::cout << "input name: ";
	std::cin >> name;

	std::cout << "what do you like programming language? ";
	std::cin >> lang;

	std::cout << "my name is " << name << "!\n";
	std::cout << "my favorite programming language is " << lang << "!" << std::endl;
}
//20191224