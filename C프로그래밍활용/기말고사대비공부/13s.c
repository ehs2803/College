#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNING

int get_response(char* a);

int main(void)
{
	char in[10];
	int reponse;
	scanf("%s", in);
	reponse = get_response(in);
	if (reponse == 1)
	{
		printf("긍정적인 답변");
	}
	else if(reponse==0)
	{
		printf("부정적인 답변");
	}
	else
	{
		printf("판단할 수 없습니다.");
	}
}

int get_response(char* a)
{
	char b[5] = "yes";
	char c[5] = "ok";
	char d[5] = "no";

	if (strcmp(a, b)==0 || strcmp(a, c)==0)
	{
		return 1;
	}
	else if (strcmp(a, d)==0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
//20191129