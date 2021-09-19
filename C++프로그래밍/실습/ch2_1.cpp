#include<iostream>

int main(void)
{
	int k = 1;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << k << '\t';
			k++;
		}
		std::cout<<'\n';
	}
}