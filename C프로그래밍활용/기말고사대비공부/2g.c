#include<stdio.h>
#define SIZE 3
#define _CRT_SECURE_NO_WARNING
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

	printf("�л��� ������ �Է��ϼ���\n");

	for (i = 0; i < SIZE; i++)
	{
		printf("�й��� �Է��ϼ���: ");
		scanf("%d", &(list[i].num));
		printf("�̸��� �Է��ϼ���: ");
		scanf("%s", list[i].name, 10);
		printf("������ �Է��ϼ���: ");
		scanf("%lf", &(list[i].grade));
	}
	best = get_max_stu(list);
	printf("������ ���� ���� �л��� (�̸�: %s, �й�: %d, ����: %f)�Դϴ�\n", best.name, best.num, best.grade);
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
//20191129