#include<stdio.h>

int main(void)
{
	int n,i, sum;

	sum = 0;

	printf("n�� ���� �Է��Ͻÿ�: ");
	scanf_s("%d", &n);

	for (i = 1; i <= n; i++)
	{
		sum = sum + i * i;
	}

	printf("��갪�� %d�Դϴ�.", sum);

}