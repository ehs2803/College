#include<stdio.h>

struct phone {
	char name[10];
	char home[10];
	char cell[10];
};

int main(void)
{
	struct phone s[3];

	int i, j;

	char find[10];

	for (i = 0; i < 3; i++)
	{
		printf("이름을 입력하시오: ");
		gets(s[i].name);

		printf("집전화번호를 입력하시오: ");
		gets(s[i].home);

		printf("휴대폰번호를 입력하시오: ");
		gets(s[i].cell);
	}

	printf("이름을 입력하시오: ");
	gets(find);

	for (i = 0; i < 3; i++)
	{
		if (strcmp(s[i].name, find) == 0)
		{
			j = i;
		}
	}

	printf("이름:%s\n",s[j].name);
	printf("집전화번호: %s\n",s[j].home);
	printf("휴대폰번호: %s\n",s[j].cell);
}