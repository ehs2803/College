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
	printf("1���� %d������ ���� %d�Դϴ�.", i, sum);
}