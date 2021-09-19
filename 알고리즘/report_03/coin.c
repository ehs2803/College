#include<stdio.h>
#define INF 2147483647

int CoinChange_greedy_A(int cash) {
	int change = cash;
	int n500 = 0, n100 = 0, n50 = 0, n10 = 0, n5 = 0, n1 = 0;

	while (change >= 500) {
		change -= 500; 
		n500++;	
	}
	while (change >= 100) {
		change -= 100;
		n100++;
	}
	while (change >= 50) {
		change -= 50;
		n50++;
	}
	while (change >= 10) {
		change -= 10;
		n10++;
	}
	while (change >= 5) {
		change -= 5;
		n5++;
	}
	while (change >= 1) {
		change -= 1;
		n1++;
	}
	return n500 + n100 + n50 + n10 + n5 + n1;
}

int CoinChange_greedy_B(int cash) {
	int change = cash;
	int n500 = 0, n130 = 0, n51 = 0, n10 = 0, n5 = 0, n1 = 0;

	while (change >= 500) {
		change -= 500;
		n500++;
	}
	while (change >= 130) {
		change -= 130;
		n130++;
	}
	while (change >= 51) {
		change -= 51;
		n51++;
	}
	while (change >= 10) {
		change -= 10;
		n10++;
	}
	while (change >= 5) {
		change -= 5;
		n5++;
	}
	while (change >= 1) {
		change -= 1;
		n1++;
	}
	return n500 + n130  + n51 + n10 + n5 + n1;
}

int CoinChange_dynamic_A(int cash) {
	int i, j, answer;
	int d[6] = { 500,100,50,10,5,1 };
	int* Cash = (int*)malloc((cash + 1) * sizeof(int));

	for (i = 1; i <= cash; i++) 
	{
		Cash[i] = INF;
	}
	Cash[0] = 0;
	for (j = 1; j <= cash; j++) 
	{
		for (i = 0; i < 6; i++) 
		{
			if (d[i] <= j && (Cash[j - d[i]] + 1 < Cash[j])) 
			{
				Cash[j] = Cash[j - d[i]] + 1;
			}
		}
	}
	answer = Cash[cash];
	free(Cash);
	return answer;
}

int CoinChange_dynamic_B(int cash) {
	 int i, j, answer;
	 int d[6] = { 500,130, 51,10,5,1 };
	 int* Cash = (int*)malloc((cash+1)*sizeof(int));

	 for (i = 1; i <= cash; i++) 
	 {
		 Cash[i] = INF;
	 }
	 Cash[0] = 0;
	 for (j = 1; j <= cash; j++) 
	 {
		 for (i = 0; i < 6; i++) 
		 {
			 if (d[i] <= j && (Cash[j - d[i]] + 1 < Cash[j])) 
			 {
				 Cash[j] = Cash[j - d[i]] + 1;
			 }
		 }
	 }
	 answer = Cash[cash];
	 free(Cash);
	 return answer;
}

int main(void) {
	int cash;
	printf("거스름돈을 입력하세요 : ");
	scanf_s("%d", &cash);

	printf("\nGreedy  A적용 : %d개\n", CoinChange_greedy_A(cash));
	printf("Dynamic A적용 : %d개\n\n", CoinChange_dynamic_A(cash));
	printf("Greedy  B적용 : %d개\n", CoinChange_greedy_B(cash));
	printf("Dynamic B적용 : %d개\n", CoinChange_dynamic_B(cash));
}

//153,1306, 2210,806
/*
 for (int i = 1; i <= 10000; i++) {
		if (CoinChange_dynamic_B(i) != CoinChange_greedy_B(i))printf("%d ", i);
	}
*/