#include<stdio.h>

void convert(double* grade, double* scores, int size);
void print(double* a, int size);

int main(void)
{
	double grades[10] = { 0,0.5,1.0,1.5,2.0,2.5,3.0,3.5,4.0,4.3 };
	double score[10] = { 0 };

	print(grades, 10);
	convert(grades, score, 10);
	print(score, 10);
}

void convert(double* grade, double* scores, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		scores[i] = 100.0 * (grade[i] / 4.3);
	}
}

void print(double* a, int size)
{
	int i;
	printf("%d ", a);
	for (i = 0; i < size; i++)
	{
		printf("%.1lf ", a[i]);
	}
	printf("\n");
}
//20191018