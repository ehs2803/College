#include<stdio.h>

struct person {
	char ju;
    int sco;
	char name[20];	
};

struct person a[20];
struct person tempa;
struct person b[20];
int number[5];
int main(void)
{
	int num, i, j, temp,least;
	printf("¸î¸í?");
	scanf("%d", &num);
	getchar();

	for (i = 0; i < num; i++)
	{
		scanf("%c", &a[i].ju);getchar();
		scanf("%d", &a[i].sco);getchar();	
		scanf("%s", a[i].name);getchar();	
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
	
	j = 0;
	for (i = 0; i < num; i++)
	{
		if (a[i].ju == 'D')
		{

		}
		else if (a[i].ju == 'I')
		{
			b[j] = a[i];
			j++;
		}
	}

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &number[i]);
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d %s\n", b[number[i]-1].sco, b[number[i]-1].name);
	}
	
}
//20191213 success
