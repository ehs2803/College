#include<stdio.h>

int main(void)
{
	int n, r,i,result;

	result = 1;

	printf("n�� ��: ");
	scanf_s("%d", &n);

	printf("r�� ��: ");
	scanf_s("%d", &r);

	for (i = n; i >= n - r - 1; i--)
	{
		result = result * i;
	}

	printf("������ ���� %d�Դϴ�.", result);

}