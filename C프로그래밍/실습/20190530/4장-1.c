#include<stdio.h>

int main(void)
{
	double a;

	printf("�Ǽ��� �Է��Ͻÿ�: ");
	scanf_s("%lf", &a);

	printf("�Ǽ��������δ� %lf�Դϴ�\n", a);
	printf("�����������δ� %e�Դϴ�", a);
}