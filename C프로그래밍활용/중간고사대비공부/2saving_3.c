#include<stdio.h>

void save(int amount)
{
	static int balance = 0;

	if (amount >= 0)
	{
		printf("%d \t\t", amount);
	}
	else
	{
		printf("\t %d \t", -amount);
	}

	balance += amount;
	printf("%d \n", balance);
	printf("\n");
}

int input_money()
{
	int a;

	printf("�ݾ��� �Է��Ͻÿ� : ");
	scanf_s("%d", &a);
	return a;
}

int main(void)
{
	int a;	
	for (;;)
	{
		a = input_money();
		printf("===========================================\n");
	    printf("�Ա� \t���\t �ܰ�\n");
	    printf("===========================================\n");
		save(a);
	}	
}
//20191010