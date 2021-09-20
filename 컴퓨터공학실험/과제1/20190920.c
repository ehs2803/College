#include<stdio.h>

int main(void)
{
	for (;;)
	{
		int input;
		int i, j, k, m, n;

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

			for (k = 1; k < input+1; k++)
			{
				for (m=k; m < input+1;m++)
				{
					printf(" ");
				}
				printf("*");
				for (n = 0; n < 2*k-1; n++)
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