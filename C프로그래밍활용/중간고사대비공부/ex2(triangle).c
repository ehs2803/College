#include<stdio.h>

int input_number();
void one(int a);
void two(int a);
void three(int a);

int main(void)
{
	int num; 
	for (;;)
	{ 
		num = input_number();
		if (num == 0)
		{
			break;
		}
		one(num);
	    two(num);
	    three(num);
		printf("\n");
	}
}

int input_number()
{
	int a=0;

	printf("exit=(0)\n");
	printf("input size: ");
	scanf_s("%d", &a);

	return a;
}

void one(int a)
{
	int i;

	for (i = 0; i < a + 1; i++)
	{
		printf(" ");
	}
	printf("*");
	printf("\n");
}

void two(int a)
{
	int i,j,k;
	
	for (i = 0; i < a; i++)
	{
		for (j=i;j<a;j++)
		{
			printf(" ");
		}
		printf("*");
		for (k = 0; k <2*(i+1)-1;k++)
		{
			printf(" ");
		}
		printf("*");
		printf("\n");
	}
	
}

void three(int a)
{
	int i;

	for (i = 0; i < 2 * a + 3; i++)
	{
		printf("*");
	}
}
//20191009