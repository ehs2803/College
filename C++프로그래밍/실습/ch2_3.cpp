#include<iostream>

int main(void) {
	int num1, num2;
	std::cout << "�� ���� �Է��϶�>>";
	std::cin >> num1 >> num2;

	int big;
	if (num1 > num2) {
		big = num1;
	}
	else {
		big = num2;
	}
	
	std::cout << "ū �� = " << big << std::endl;
}