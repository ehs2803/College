#include<stdio.h>

int main(void)
{
	int score[10][3];
	int i, j = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 3; j++)
		{
			score[i][j] = rand()%10;
		}
	}
}