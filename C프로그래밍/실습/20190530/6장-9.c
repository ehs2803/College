#include<stdio.h>

int main(void)
{
	float a, b;

	printf("x�� ���� �Է��Ͻÿ�: ");
	scanf_s("%f", &a);

	if (a <= 0)
	{
		b = a * a - 9 * a + 2;
	}
	else
	{
		b = 7 * a + 2;
	}

	printf("f(x)�� ���� %f", b);
}