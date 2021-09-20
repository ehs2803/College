#include<stdio.h>
//#include<ctype.h>

int main(void)
{
	FILE* fp;
	char fname[10];
	int count = 0;
	int c;
	printf("파일 이름을 입력하시오: ");
	scanf("%s", fname);
	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "파일 %s을 열수 없음\n", fname);
	}
	else
	{
		printf("파일 열기 성공\n");
	}
	while ((c = fgetc(fp)) != EOF)
	{
		if (isprint(c))
		{
			count++;
		}
	}
	fclose(fp);
	printf("문자의 개수는 %d", count);

}
//20191201 success