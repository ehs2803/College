#include<stdio.h>

struct student {
	char name[10];
	double grade;
};

int main(void)
{
	struct student a[3], b[3];
	struct student best;
	int i;
	double avea, aveb;
	char c;
	printf("a반\n");
	for (i = 0; i < 3; i++)
	{
		printf("이름을 입력하시오: ");
		scanf_s("%s", a[i].name, 10);
		printf("점수를 입력하시오: ");
		scanf_s("%lf", &a[i].grade);
	}
	printf("b반\n");
	for (i = 0; i < 3; i++)
	{
		printf("이름을 입력하시오: ");
		scanf_s("%s", b[i].name, 10);
		printf("점수를 입력하시오: ");
		scanf_s("%lf", &b[i].grade);
	}
	best = a[i];
	for (i = 0; i < 3; i++)
	{
		if (a[i].grade > best.grade)
		{
			best = a[i];
		}
	}
	printf("a반에서 가장 높은 점수를 가진 학생 이름:%s, 점수: %lf\n", best.name, best.grade);
	best = b[i];
	for (i = 0; i < 3; i++)
	{
		if (b[i].grade > best.grade)
		{
			best = b[i];
		}
	}
	printf("b반에서 가장 높은 점수를 가진 학생 이름:%s, 점수: %lf\n", best.name, best.grade);
	avea = (a[0].grade + a[1].grade + a[2].grade) / 3;
	aveb = (b[0].grade + b[1].grade + b[2].grade) / 3;
	if (avea > aveb)
	{
		c = 'a';
	}
	else
	{
		c = 'b';
	}
	printf("a반의 평균은 %lf, b반의 평균은 %lf, 더 평균이 높은 반은 %c반이다.\n", avea, aveb, c);
}
//20191123