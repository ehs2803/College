#include<stdio.h>

int power(int a, int b);

int result=0;

int main(void)
{
	int input1, input2;

	printf("�ؼ�: ");
	scanf_s("%d", &input1);
	printf("����: ");
	scanf_s("%d", &input2);

	printf("%d^%d = %d", input1, input2, power(input1, input2));

}

int power(int a, int b)
{
	if (b>=1)
	{
		result = a * a;
		b = b - 1;
		power(a, b);
	}
	else
	{
		return result;
	}
}