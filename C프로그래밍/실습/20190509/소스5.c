#include<stdio.h>

int main(void)
{

	int a;
	int i;
	int sum;

	

	printf("������ �Է��Ͻÿ�.");
	scanf_s("%d", &a);
	
	i = 1;
	sum = 0;

	while (i <= a)
	{
		sum = sum + i;
		i++;
	}

	printf("1���� %d���� ���� %d�Դϴ�.", a, sum);

}