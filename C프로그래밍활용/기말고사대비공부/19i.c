
/*
텍스트파일 그대로 출력하기1
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
int main(void)
{
	char a[10];
	int c;

	FILE* fp = NULL;
	printf("파일이름:");
	scanf("%s", a);

	fp = fopen(a, "r");
	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}
	fclose(fp);//출력
}
텍스트파일 그대로 출력하기2
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
int main(void)
{
	char a[10];
	char buffer[256];

	FILE* fp = NULL;
	printf("파일이름:");
	scanf("%s", a);

	fp = fopen(a, "r");
	while (fgets(buffer,256,fp))
	{
		printf("%s", buffer);
	}
	fclose(fp);//출력
}
텍스트파일에 입력하기1
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
int main(void)
{
	char a[10];
	int c;

	FILE* fp = NULL;
	printf("파일이름:");
	scanf("%s", a);
	getchar();//이게 없어도 되지만 없으면 텍스트파일에 한줄띄고 입력됨.
	fp = fopen(a, "w");
	while ((c = getchar()) != '.')
	{
		fputc(c, fp);
	}
	fclose(fp);//출력
}
텍스트파일에 입력하기2
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp1;
	char file1[100];
	char buffer[1000];
	char* p;

	printf("파일 이름을 입력하시오:  ");
	scanf("%s", file1);
	getchar();
	fp1 = fopen(file1, "w");
	if (fp1 == NULL)
	{
		fprintf(stderr, "파일 %s을 열 수 없습니다.\n", file1);
		exit(1);
	}
	while (1)
	{
		p = gets(buffer);
		if (p == NULL)
		{
			break;
		}
		//fputs(buffer, fp1); 이거 사용시 줄바꿈이 안됨.
		fprintf(fp1, "%s\n", buffer);  //\n이 있어서 줄바꿈 가능.
	}
	fclose(fp1);
}
*/
//20191203
