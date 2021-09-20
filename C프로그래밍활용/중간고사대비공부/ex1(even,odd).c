#include<stdio.h>

int input_number();
int num_judge(int a);

int main(void)
{
	int num = input_number();
	int a = num_judge(num);
	if (a == 1)
	{
		printf("%d is odd", num);
	}
	else
	{
		printf("%d is even", num);
	}
}

int input_number()
{
	int a = 0;

	printf("input number : ");
	scanf_s("%d", &a);
	return a;
}

int num_judge(int a)
{
	if(a%2==1)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
//20191009