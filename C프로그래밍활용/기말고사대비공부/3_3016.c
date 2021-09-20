#include<stdio.h>

struct person {
	char name[20];
	int a; int ac;
	int b; int bc;
	int c; int cc;
};

int main(void)
{
	struct person in[100];
	struct person tempa;
	int num;
	int i, j, temp, least;

	printf("¸î¸í?");
	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%s %d %d %d", in[i].name, &in[i].a, &in[i].b, &in[i].c);
	}

	for (i = 0; i < num - 1; i++)
	{
		least = i;
		for (j = i + 1; j < num; j++)
		{
			if (in[j].a < in[least].a)
			{
				least = j;
			}
		}
		tempa = in[i];
		in[i] = in[least];
		in[least] = tempa;
	}
	for (i = 0; i < num; i++)
	{
		in[i].ac = num - i;
	}
	for (i = 0; i < num - 1; i++)
	{
		least = i;
		for (j = i + 1; j < num; j++)
		{
			if (in[j].b < in[least].b)
			{
				least = j;
			}
		}
		tempa = in[i];
		in[i] = in[least];
		in[least] = tempa;
	}
	for (i = 0; i < num; i++)
	{
		in[i].bc = num - i;
	}
	for (i = 0; i < num - 1; i++)
	{
		least = i;
		for (j = i + 1; j < num; j++)
		{
			if (in[j].c < in[least].c)
			{
				least = j;
			}
		}
		tempa = in[i];
		in[i] = in[least];
		in[least] = tempa;
	}
	for (i = 0; i < num; i++)
	{
		in[i].cc = num - i;
	}
	for (i = 0; i < num - 1; i++)
	{
		least = i;
		for (j = i + 1; j < num; j++)
		{
			if (in[j].a < in[least].a)
			{
				least = j;
			}
		}
		tempa = in[i];
		in[i] = in[least];
		in[least] = tempa;
	}
	printf("%s %d %d\n", in[num-1].name, in[num - 1].bc, in[num - 1].cc);
}
//3016 - 20191213 success