#define _NO_SECURE_NO_WARNING
#include<stdio.h>

struct student {
	int age;
	char name[10];
}a;

int main(void)
{
	char search[10];
	int i;

	
		printf("나이를 입력하시오: ");
		scanf("%d", &a.age);

		printf("이름을 입력하시오: ");
		scanf("%s", a.name);
	
	printf("찾을 이름: ");
	scanf("%s", search);
	for (i = 0; a.name[i]!=NULL; i++)
	{
		if (a.name[i] == search[i])
		{

		}
		else
		{
			printf("다르다");
			return 0;
		}
	}
	printf("같다");
}
//20191127