#include<stdio.h>
#include<string.h>

typedef struct {
	char name[10];
	char phone_num[10];
	char home_num[10];
} phone_info;

int main(void)
{
	phone_info info[3];
	char search[10];
	int i;

	for (i = 0; i < 3; i++)
	{
		printf("이름 : ");
		gets(info[i].name);//scanf_s("%s",info[i].name,10);
		printf("휴대전화 번호 : ");
		gets(info[i].phone_num);
		printf("집 전화 번호 : ");
		gets(info[i].home_num);
	}
	printf("찾을 이름 : ");
	gets(search);
	for (i = 0; i < 3; i++)
	{
		if (strcmp(info[i].name, search) == 0)
		{
			printf("휴대전화 번호 : %s\n", info[i].phone_num);
			printf("집 전화 번호: %s\n", info[i].home_num);
			return 0;
		}
	}
	printf("실패\n");
	return 0;
}
//20191129