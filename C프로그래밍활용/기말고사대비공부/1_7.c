#include<stdio.h>

int get_response(char* a);

int main(void)
{
	char in[10];
	int reponse;
	scanf_s("%s", in, 10);
	reponse = get_response(in);
	if (reponse == 1)
	{
		printf("긍정적인 답변");
	}
	else
	{
		printf("부정적인 답변");
	}
}

int get_response(char* a)
{
	char b[5] = "yes";
	char c[5] = "ok";
	char d[5] = "no";

	if (strcmp(a, b)||strcmp(a,c))
	{
	   return 1;
	}
	else if (strcmp(a, d))
	{
		return 0;
	}
}
//20191120