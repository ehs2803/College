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
		printf("�й�:");
		scanf("%d", &a[i].num);
		printf("�̸�: ");
		scanf("%s", a[i].name);
		printf("����:");
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
	printf("���� ���� ������ �л��� �й�%d �̸�%s ����%.2lf�Դϴ�.\n", a[best].num, a[best].name, a[best].grade);
}