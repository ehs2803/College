#include<stdio.h>
double area();

int main(void)
{
	double a;

	printf("���� �������� �Է��Ͻÿ�: ");
	scanf_s("%lf", &a);

	printf("���� ������ %lf�Դϴ�. ", area(a));

}

double area(double i)
{
	return 3.14 * i * i;
}