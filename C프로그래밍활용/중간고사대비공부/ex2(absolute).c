#include<stdio.h>

int input_number();

int main(void)
{
	int num = input_number();

	printf("%d >> %d", num, absolute(num));

}

int input_number()
{
	int a = 0;

	printf("input number : ");
	scanf_s("%d", &a);
	return a;
}

int absolute(int a)
{
	if (a > 0)
	{
		return a;
	}
	else
	{
		return -a;
	}
}
//20191009