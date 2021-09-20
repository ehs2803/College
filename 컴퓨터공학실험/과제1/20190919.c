#include<stdio.h>

int main(void)
{
	for (;;)
	{
		int input;
		int i;
		int j;
		int k;
		int m;
		int n;

		printf("exit=(0)\n");
		printf("input size : ");
		scanf_s("%d", &input);

		if (input == 0)
		{
			break;
		}
		else
		{
			for (i = 0; i < input + 1; i++)
			{
				printf(" ");
			}
			printf("*\n");

			for (k = 0; k < input; k++)
			{
				for (m=3; k < m+1; m=m-1)
				{
					printf(" ");
				}
				printf("*");
				for (n=3;n<k;n++)
				{
					printf(" ");
				}
				printf("*");
				printf("\n");
			}
			
			for (j = 0; j < input * 2 + 3; j++)
			{
				printf("*");
			}
		}
		printf("\n");
	}

}