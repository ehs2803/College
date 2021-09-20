#include<stdio.h>

struct person {
	char name[20];
	int year;
	int mon;
	int day;
};

struct person a[50];
struct person tempa;
int main(void)
{
	int num;
	int i, j, temp, least;

	printf("¸î¸í:");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		scanf("%s %d %d %d",a[i].name,&a[i].year,&a[i].mon,&a[i].day);
    }
	for (i = 0; i < num - 1; i++)
	{
		least = i;
		for (j = i + 1; j < num; j++)
		{
			if (a[j].day < a[least].day)
			{
				least = j;
			}
		}
		tempa = a[i];
		a[i] = a[least];
		a[least] = tempa;
	}
	for (i = 0; i < num - 1; i++)
	{
		least = i;
		for (j = i + 1; j < num; j++)
		{
			if (a[j].mon < a[least].mon)
			{
				least = j;
			}
		}
		tempa = a[i];
		a[i] = a[least];
		a[least] = tempa;
	}
	for (i = 0; i < num - 1; i++)
	{
		least = i;
		for (j = i + 1; j < num; j++)
		{
			if (a[j].year < a[least].year)
			{
				least = j;
			}
		}
		tempa = a[i];
		a[i] = a[least];
		a[least] = tempa;
	}
	for (i = 0; i < num; i++)
	{
		printf("%s\n", a[i].name);
	}

}
//3019 - 20191214 - success