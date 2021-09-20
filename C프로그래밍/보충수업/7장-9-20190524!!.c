#include<stdio.h>

int main(void)
{
	int i, sum;

	sum = 0;

	for (;;)
	{

		for (i=1; sum < 10000;i++)
		{
			sum += i;
		}
		if (sum < 10000)
		{
			break;
		}

	}
	printf("1부터 %d까지의 합이 %d입니다.", i, sum);
}