#include<stdio.h>

int main(void)
{
	int a, b, c,d,e;

	printf("3���� ������ �Է��Ͻÿ�: ");
	scanf_s("%d %d %d", &a, &b, &c);

	d = a > b ? a : b;
	e = d > c ? d : c;

	printf("�ִ밪:%d", e);
}