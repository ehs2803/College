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
	printf("[규정A]\n");
	printf("500원 : %d, 100원 : %d, 50원 : %d, 10원 : %d, 5원 : %d, 1원 : %d\n",
		n500, n100, n50, n10, n5, n1);
	printf("총 동전개수 : %d\n", n500 + n100 + n50 + n10 + n5 + n1);
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
	printf("[규정B]\n");
	printf("500원 : %d, 130원 : %d, 100원 : %d, 50원 : %d, 10원 : %d, 5원 : %d, 1원 : %d\n", 
		n500, n130, n100, n50, n10, n5, n1);
	printf("총 동전개수 : %d\n", n500 + n130 + n100 + n50 + n10 + n5 + n1);
}

int main(void) 
{
	int inputChange;
	printf("거스름돈 액수를 입력하세요 : ");
	scanf_s("%d", &inputChange);
	printf("\n");

	CoinChange_A(inputChange);
	printf("\n");
	CoinChange_B(inputChange);
}