#include<stdio.h>
double square(double i);

int main(void)
{
	float a;

	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%f", &a);

	printf("�־��� ���� %f�� ������ %f�Դϴ�.", a, square(a));

}

double square(double i)
{
	return i * i;
}