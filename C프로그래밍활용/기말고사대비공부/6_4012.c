/*#include<stdio.h>

struct person {
	int sta;
	int sco;
	int seq;
};

struct person a[20];
struct person tempa;

int main(void)
{
	int num;
	int i, j, temp, least;

	printf("몇명?");
	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		a[i].sta = i;
	}
	for (i = 0; i < num; i++)
	{
		scanf("%d", &a[i].sco);
	}
	for (i = 0; i < num - 1; i++)
	{
		least = i;
		for (j = i + 1; j < num; j++)
		{
			if (a[j].sco < a[least].sco)
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
		a[i].seq = num - i;
	}
	for (i = 0; i < num - 1; i++)
	{
		least = i;
		for (j = i + 1; j < num; j++)
		{
			if (a[j].sta < a[least].sta)
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
		printf("%d %d\n", a[i].sco,a[i].seq);
	}

}
//4012 20191213 + 동점알고리즘 추가필요*/
#include<stdio.h>

struct person {
	int sco;
	int seq;
};

struct person a[20];
struct person tempa;

int main(void)
{
	int num;
	int i, j, temp, least;

	printf("몇명?");
	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%d", &a[i].sco);
		a[i].seq = 1;
	}

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (a[i].sco < a[j].sco)
			{
				++a[i].seq;
			}
		}
	}

	for (i = 0; i < num; i++)
	{
		printf("%d %d\n", a[i].sco, a[i].seq);
	}

}
//20191214 success