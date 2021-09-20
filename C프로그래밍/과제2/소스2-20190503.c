#include<stdio.h>

int main(void)
{

	int i;
	int j;
	int a;

	for (j = 5; j < 10; j++)
	{
         for (a = 4; a>=0&&a < 5;a=a-1 )
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






