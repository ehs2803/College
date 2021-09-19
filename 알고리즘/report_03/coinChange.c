#include<stdio.h>

void CoinChange_A(int cash) {
	int change = cash;
	int n500 = 0, n100 = 0, n50 = 0, n10 = 0, n5 = 0, n1 = 0;

	while (change >= 500){
		change -= 500;
		n500++;
	}
	while (change >= 100){
		change -= 100;
		n100++;
	}
	while (change >= 50){
		change -= 50;
		n50++;
	}
	while (change >= 10){
		change -= 10;
		n10++;
	}
	while (change >= 5){
		change -= 5;
		n5++;
	}
	while (change >= 1){
		change -= 1;
		n1++;
	}
	printf("[����A]\n");
	printf("500�� : %d, 100�� : %d, 50�� : %d, 10�� : %d, 5�� : %d, 1�� : %d\n",
		n500, n100, n50, n10, n5, n1);
	printf("�� �������� : %d\n", n500 + n100 + n50 + n10 + n5 + n1);
}

void CoinChange_B(int cash) {
	int change = cash;
	int n500 = 0, n130 = 0, n100 = 0, n50 = 0, n10 = 0, n5 = 0, n1 = 0;

	while (change >= 500){
		change -= 500;
		n500++;
	}
	while (change >= 130) {
		change -= 130;
		n130++;
	}
	while (change >= 100){
		change -= 100;
		n100++;
	}
	while (change >= 50){
		change -= 50;
		n50++;
	}
	while (change >= 10){
		change -= 10;
		n10++;
	}
	while (change >= 5){
		change -= 5;
		n5++;
	}
	while (change >= 1){
		change -= 1;
		n1++;
	}
	printf("[����B]\n");
	printf("500�� : %d, 130�� : %d, 100�� : %d, 50�� : %d, 10�� : %d, 5�� : %d, 1�� : %d\n", 
		n500, n130, n100, n50, n10, n5, n1);
	printf("�� �������� : %d\n", n500 + n130 + n100 + n50 + n10 + n5 + n1);
}

int main(void) 
{
	int inputChange;
	printf("�Ž����� �׼��� �Է��ϼ��� : ");
	scanf_s("%d", &inputChange);
	printf("\n");

	CoinChange_A(inputChange);
	printf("\n");
	CoinChange_B(inputChange);
}