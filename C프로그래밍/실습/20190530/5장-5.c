#include<stdio.h>

int main(void)
{
	int a;

	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &a);

	printf("���� �ڸ�:%d \n", a / 10);
	printf("���� �ڸ�:%d \n", a % 10);
}