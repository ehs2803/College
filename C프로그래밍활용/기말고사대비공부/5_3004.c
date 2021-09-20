#include<stdio.h>

struct person {
	int num;
	int sco;
	int seq;
};

struct person list[50];
struct person tempa;

int main(void)
{
	int num;
	int i, j, least, temp;
	printf("¸î¸í:");
	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%d", &list[i].sco);
		list[i].num = i;
	}
	for (i = 0; i < num - 1; i++)
	{
		least = i;
		for (j = i + 1; j < num; j++)
		{
			if (list[j].sco < list[least].sco)
			{
				least = j;
			}
		}
		tempa = list[i];
		list[i] = list[least];
		list[least] = tempa;
	}

	for (i = 0; i < num; i++)
	{
		list[i].seq = i;
	}

	for (i = 0; i < num - 1; i++)
	{
		least = i;
		for (j = i + 1; j < num; j++)
		{
			if (list[j].num < list[least].num)
			{
				least = j;
			}
		}
		tempa = list[i];
		list[i] = list[least];
		list[least] = tempa;
	}
	for (i = 0; i < num; i++)
	{
		printf("%d ", list[i].seq);
	}
}
//3004 - 20191213 success