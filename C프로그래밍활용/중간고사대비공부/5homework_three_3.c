#include <stdio.h>
#include<stdlib.h>
void score_judge(int score[][3]);

int main(void)
{
	int i, k;
	int score[10][3];
	for (i = 0; i < 10; i++)
	{
		for (k = 0; k < 3; k++)
		{
			score[i][k] = rand() % 100 + 1;
		}
	}
	score_judge(score);
}

void score_judge(int score[][3])
{
	int i, k, min, max, sum;
	for (k = 0; k < 3; k++) {
		min = max = score[0][k];
		sum = 0;
		for (i = 0; i < 10; i++)
		{
			if (score[i][k] < min)
			{
				min = score[i][k];
			}
			if (score[i][k] > min)
			{
				max = score[i][k];
			}
			sum += score[i][k];
		}
		printf("시험 #%d의 최대점수=%d\n", k, max);
		printf("시험 #%d의 최저점수=%d\n", k, min);
	}
}
//20191017 chapter10_9