#include<stdio.h>
float area();

int main(void)
{
	float a;

	printf("���� �������� �Է��Ͻÿ�: ");
	scanf_s("%f", &a);

	printf("���� ������ %f�Դϴ�. ", area(a));

}

float area(float i)
{
	return 3.14* i* i;
}