#include<iostream>

int main(void) {
	int num1, num2;
	std::cout << "두 수를 입력하라>>";
	std::cin >> num1 >> num2;

	int big;
	if (num1 > num2) {
		big = num1;
	}
	else {
		big = num2;
	}
	
	std::cout << "큰 수 = " << big << std::endl;
}