#include<stdio.h>

int main(void)
{
	int a,b;

	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &a);

	printf("2�� ���ϰ� ���� Ƚ��: ");
	scanf_s("%d", &b);

	printf("%d<<%d�� �� : %d", a, b, a << b);
}