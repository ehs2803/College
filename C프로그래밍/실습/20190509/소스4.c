#include<stdio.h>

int main(void)
{

	int a;
	int i;
	int sum;

	sum = 0;

	printf("������ �Է��Ͻÿ�.");
	scanf_s("%d", &a);

	for (i = 1; i <= a; i++)
	{
		
		sum = sum + i;

	}

	printf("1���� %d���� ���� %d�Դϴ�.", a, sum);

}