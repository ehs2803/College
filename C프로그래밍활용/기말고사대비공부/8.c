#include<stdio.h>

struct person {
	int num;
	char name[20];
};

struct person a[10];
struct person tempa;

int main(void)
{
	int i, j, temp, least;
	
	for (i = 0; i < 10; i++)
	{
		scanf("%d %s", &a[i].num, a[i].name);
	}
	for (i = 0; i < 9; i++)
	{
		least = i;
		for (j = i + 1; j < 10; j++)
		{
			if (strcmp(a[j].name, a[least].name) < 0)
			{
				least = j;
			}
		}
		tempa = a[i];
		a[i] = a[least];
		a[least] = tempa;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d %s\n", a[i].num, a[i].name);
	}
}
//20191213