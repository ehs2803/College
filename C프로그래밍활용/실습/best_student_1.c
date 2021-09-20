#include<stdio.h>
#define SIZE 3
struct student {
	int num;
	char name[20];
	double grade;
};

struct student get_max_stu(struct student list[]);

struct student list[SIZE];

int main(void)
{
	struct student best;
	int i;

	printf("학생의 정보를 입력하세요\n");

	for (i = 0; i < SIZE; i++)
	{
		printf("학번을 입력하세요: ");
		scanf_s("%d", &(list[i].num));
		printf("이름을 입력하세오: ");
		scanf_s("%s", list[i].name, 10);
		printf("평점을 입력하세요: ");
		scanf_s("%lf", &(list[i].grade));
	}
	best = get_max_stu(list);
	printf("평점이 가장 높은 학생은 (이름: %s, 학번: %d, 평점: %f)입니다\n", best.name, best.num, best.grade);
}
struct student get_max_stu(struct student list[])
{
	struct student super;
	int i;
	super = list[0];
	for (i = 0; i < SIZE; i++)
	{
		if (list[i].grade > super.grade)
		{
			super = list[i];
		}
	}
	return super;
}