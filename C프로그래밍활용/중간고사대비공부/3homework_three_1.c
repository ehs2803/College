#include <stdio.h>
#include<stdlib.h>

int main(void)
{
	int freq[10] = { 0 };
	int i, max;
	max = 0;

	for (i = 0; i < 100; i++)
	{
		++freq[rand() % 10];
	}

	for (i = 1; i < 10; i++)
	{
		if (freq[i] > freq[max])
		{
			max = i;
		}
	}

	printf("가장 많이 나온수=%d\n", max);
}
//20191017 chapter10_5