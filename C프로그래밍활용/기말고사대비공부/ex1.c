#include<stdio.h>

struct employee {
	char name[10];
	int num;
	int salary;
};

int main(void)
{
	struct employee s[3];
	int i;
	for (i = 0; i < 3; i++)
	{
		printf("input name: ");
		scanf("%s", s[i].name);
		printf("input number: ");
		scanf("%d", &s[i].num);
		printf("input salary: ");
		scanf("%d", &s[i].salary);
	}
	printf("\n\n");
	for (i = 0; i < 3; i++)
	{
		printf("name:%s\n", s[i].name);
		printf("number: %d\n", s[i].num);
		printf("salary: %d\n", s[i].salary);
		printf("\n\n");
	}

}
//20191113