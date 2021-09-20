#include<stdio.h>
#define ROWS 3
#define COLS 5

int main(void)
{
	int a[ROWS][COLS] = {
		{87,98,80,76,3},
	{99,89,90,90,0},
	{65,68,50,49,0}

	};
	double final_scores[3];
	int i;
	int m, n, temp, least;
	static int b=1;

	for (i = 0; i < ROWS; i++)
	{
	    final_scores[i] = a[i][0] * 0.3 + a[i][1] * 0.4 + a[i][2] * 0.2 + a[i][3] * 0.1 - a[i][4];
		printf("학생 #%d의 최종성적=%10.2f \n", i + 1, final_scores[i]);
	}
    
	for (m = 0; m< 2; m++)
	{
		least = m;
		for (n = m + 1; n < 3; n++)
			if (final_scores[n] < final_scores[least])
				least = n;
		temp = final_scores[m];
		final_scores[m] = final_scores[least];
		final_scores[least] = temp;
	}
	for (i = 2; i >-1; i--)
	{   
		printf("순위%d :%lf \n", b,final_scores[i]);
		b++;
	}
}