#include<stdio.h>

int main(void)
{
	int a;
	int b;
	int c;
	int d;

	printf("Â¦¼ö, È¦¼ö");
	scanf_s("%d", &d);

	for (;;)
	{
		if (d%2==0)
		{
			for (a = 1, c = 1; a < 10; a++, c++)
			{

				for (b = 2; b < 10; b=b+2)
				{
					printf("%d*%d=%2d\t", b, c, b*c);

				}
				printf("\n");

			}
		}
		else if (d&2==1)
		{
			for (a = 1, c = 1; a < 10; a++, c++)
			{

				for (b = 3; b < 10; b = b + 2)
				{
					printf("%d*%d=%2d\t", b, c, b*c);

				}
				printf("\n");

			}


		}
	}
}
//Â¦¼ö-Â¦¼ö´Ü, È¦¼ö-È¦¼ö´Ü