#include<stdio.h>

int main(void)
{
	int i;
	int j;
	int a;
	
	for (j = 5; j < 10; j++)
	{
			for (a=10;a>j;a=a-1 )
			{
				printf(" ");
			}
			for (i = 5; i <= j; i++)
			{
				printf("*");
			}
			printf("\n");
	}

}