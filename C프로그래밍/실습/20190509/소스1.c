#include<stdio.h>

int main(void)
{
	int a;
	int b;
	int c;

	for (a = 1,c=1; a < 10; a++,c++)
	{
		
		for (b =2;b<10;b++)
		{
			printf("%d*%d=%2d\t", b,c,b*c);

		}
		printf("\n");

	}

}