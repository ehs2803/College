#include<stdio.h>

struct person {
	int cou;
	int name;
	int sco;
};

struct person a[20];
struct person tempa;

int main(void)
{
	int num, i, j, temp, least;
	printf("몇명입니까?");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		scanf("%d %d %d", &a[i].cou, &a[i].name, &a[i].sco);
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
	printf("%d %d\n", a[num-1].cou, a[num - 1].name);
	printf("%d %d\n", a[num - 2].cou, a[num - 2].name);
	if (a[num - 1].cou == a[num - 2].cou && a[num - 2].cou == a[num - 3].cou)
	{
		for (i = 3; i < num; i++)
		{
			if (a[num - 1].cou != a[num - 1-i].cou)
			{
				printf("%d %d\n", a[num - 1 - i].cou, a[num - 1 - i].name);
				break;
			}
		}
	}
	else
	{
		printf("%d %d\n", a[num - 3].cou, a[num - 3].name);
	}
}
//4751 - 20191213 - success