#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

struct person {
	int num;
	char name[20];
	double grade;
};

struct person a[5];

int main(void)
{
	int i;
	int best;

	for (i = 0; i < 5; i++)
	{
		printf("학번:");
		scanf("%d", &a[i].num);
		printf("이름: ");
		scanf("%s", a[i].name);
		printf("평점:");
		scanf("%lf", &a[i].grade);
	}
	best = 0;
	for (i = 0; i < 5; i++)
	{
		if (a[best].grade < a[i].grade)
		{
			best = i;
		}
	}
	printf("가장 높은 평점인 학생은 학번%d 이름%s 평점%.2lf입니다.\n", a[best].num, a[best].name, a[best].grade);
}