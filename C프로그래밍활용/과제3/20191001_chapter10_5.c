#include<stdio.h>

int main(void)
{
	int input[100];
	int save[10];
	int i;
	int max;

	for (i = 0; i < 100; i++)
	{
		input[i] = rand() % 10;
	}

	for (i = 0; i < 100; i++)
	{
		if (input[i] == 0)
		{
			save[0]++;
		}
		else if (input[i] == 1)
		{
			save[1]++;
		}
		else if (input[i] == 2)
		{
			save[2]++;
		}
		else if (input[i] == 3)
		{
			save[3]++;
		}
		else if (input[i] == 4)
		{
			save[4]++;
		}
		else if (input[i] == 5)
		{
			save[5]++;
		}
		else if (input[i] == 6)
		{
			save[6]++;
		}
		else if (input[i] == 7)
		{
			save[7]++;
		}
		else if (input[i] == 8)
		{
			save[8]++;
		}
		else if (input[i] == 9)
		{
			save[9]++;
		}
	}
	max = 0;
	for (i = 1; i < 10; i++)
	{  
		if (save[i] > max)
		{
			max = i;
		}
	}
	printf("가장 많이 나온수=%d");

}