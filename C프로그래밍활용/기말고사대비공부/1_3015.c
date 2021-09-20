#include<stdio.h>
#include<string.h>
//#define _CRT_SECURE_NO_WARNINGS

struct person {
    int score;
	char name[20];
};

int main(void)
{
	
struct person a[100];
struct person tempa;

	int num1, num2;
	int i, j, temp, least;
	
AAA:
	printf("몇명의 데이터를 입력하시겠습니까?(3~100)");
	scanf("%d", &num1);
	getchar();
	if (num1 < 3 || num1>100)
	{
		printf("다시 입력하시오:");
		goto AAA;
	}
BBB:
	printf("상위 몇명의 데이터를 출력하시겠습니까?");
	scanf("%d", &num2);

	if (num2<1 || num2>num1)
	{
		printf("다시 입력하시오:");
		goto BBB;
	}
	for (i = 0; i < num1; i++)
	{
		scanf("%s %d", a[i].name, &a[i].score);
	}

	for (i = 0; i < num1-1; i++)
	{
		least = i;
		for (j = i + 1; j <num1; j++)
		{
			if (a[j].score < a[least].score)
			{
				least = j;
			}
		}
		tempa = a[i];
		a[i] = a[least];
		a[least] = tempa;
	}
	for (i = 0; i < num2;i++)
	{
		printf("%d %s\n",a[num1-1-i].score, a[num1 - 1-i].name);
	}
	
}
//코드업 구조체 3015 20191212 //20191213수정완료success