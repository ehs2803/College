#include<stdio.h>
#define _CRT_SECURE_NO_WARNING
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
	printf("a��\n");
	for (i = 0; i < 3; i++)
	{
		printf("�̸��� �Է��Ͻÿ�: ");
		scanf("%s", a[i].name);
		printf("������ �Է��Ͻÿ�: ");
		scanf("%lf", &a[i].grade);
	}
	printf("b��\n");
	for (i = 0; i < 3; i++)
	{
		printf("�̸��� �Է��Ͻÿ�: ");
		scanf("%s", b[i].name);
		printf("������ �Է��Ͻÿ�: ");
		scanf("%lf", &b[i].grade);
	}
	best = a[i];
	for (i = 0; i < 3; i++)
	{
		if (a[i].grade > best.grade)
		{
			best = a[i];
		}
	}
	printf("a�ݿ��� ���� ���� ������ ���� �л� �̸�:%s, ����: %lf\n", best.name, best.grade);
	best = b[i];
	for (i = 0; i < 3; i++)
	{
		if (b[i].grade > best.grade)
		{
			best = b[i];
		}
	}
	printf("b�ݿ��� ���� ���� ������ ���� �л� �̸�:%s, ����: %lf\n", best.name, best.grade);
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
	printf("a���� ����� %lf, b���� ����� %lf, �� ����� ���� ���� %c���̴�.\n", avea, aveb, c);
}
//20191129