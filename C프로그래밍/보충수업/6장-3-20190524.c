#include<stdio.h>

int main(void)
{
	int a, b, c, min;

	printf("3���� ������ �Է��Ͻÿ�: ");
	scanf_s("%d %d %d", &a, &b, &c);

	min = a < b ? a : b;
	min = min < c ? min : c;

	printf("���� ���� ������ %d�Դϴ�.", min);
}