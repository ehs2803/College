#include<stdio.h>

int main(void)
{
	FILE* fp;
	char fname[10];
	char buffer[256];
	int line_num = 0;
	printf("파일 이름: ");
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
	while (fgets(buffer, 256, fp))
	{
		line_num++;
		printf("%d: %s",line_num, buffer);
	}
	fclose(fp);
}
//20191201 success