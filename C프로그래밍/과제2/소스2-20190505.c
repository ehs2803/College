#include<stdio.h>

int main(void)
{

	int i;
	int j;
	int a;
	int b;

	for (b = 5; b < 10; b++)
	{
	    for (j = 5; j < 10; j++)
	    {
		    for (a = 10; b<a; b++ )
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