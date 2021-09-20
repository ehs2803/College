#include<stdio.h>

int main(void)
{

	int i;
	int j;
	int a;
	int c=14;

	
		for (j = 5; j < 10; j++)
		{
			for (c=14;c>10;c=c-1)
			{
				for (a = 10; c > a; c = c - 1)
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


}