#include<stdio.h>

struct person {
	int number;
	char name[20];
	int korea; int kc;
	int math; int mc;
	int eng; int ec;
};

struct person a[20];
struct person temp;

int main(void)
{
	int num, i, j;
	int least;
	printf("���?");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		printf("�й�:"); scanf("%d", &a[i].number);
		printf("�̸�:"); scanf("%s", a[i].name);
		printf("��������:"); scanf("%d", &a[i].korea);
		printf("��������:"); scanf("%d", &a[i].math);
		printf("��������:"); scanf("%d", &a[i].eng);
		a[i].kc = 1; 
		a[i].mc = 1;	
        a[i].ec = 1;
	}
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (a[i].korea < a[j].korea)
			{
				++a[i].kc;
			}
		}
	}
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (a[i].math < a[j].math)
			{
				++a[i].mc;
			}
		}
	}
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (a[i].eng < a[j].eng)
			{
				++a[i].ec;
			}
		}
	}
	for (i = 0; i < num - 1; i++)
	{
		least = i;
		for (j = i + 1; j < num; j++)
		{
			if (a[j].korea > a[least].korea)
			{
				least = j;
			}
		}
		temp = a[i];
		a[i] = a[least];
		a[least] = temp;
	}
	printf("����?"); scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		printf("%s %d %d %d\n", a[i].name, a[i].kc, a[i].mc, a[i].ec);
	}

}
//20191217