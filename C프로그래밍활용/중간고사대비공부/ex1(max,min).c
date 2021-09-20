#include<stdio.h>

int max(int a, int b);
int min(int a, int b);

int main(void)
{
	int in1, in2, in3;

	printf("input three number : ");
	scanf_s("%d %d %d", &in1, &in2, &in3);

	printf("max = %d\n", max(max(in1, in2), in3));
	printf("min = %d", min(min(in1, in2), in3));
}

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
//20191009