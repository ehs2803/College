#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNING

int main(void)
{
	FILE* fp;

	char fname[10];
	char buffer[256];
	char word[256];
	int line_num = 0;

	printf("파일 이름을 입력하시오: ");
	scanf("%s", fname);

	printf("탐색할 단어를 입력하시오: ");
	scanf("%s", word);

	fp = fopen(fname, "r");
	
	if (fp == NULL)
	{
		fprintf(stderr,"파일 %s을 열 수 없다.\n", fname);
		exit(1);
	}
	else
	{
		printf("파일 열기 성공\n");
	}

	while (fgets(buffer, 256, fp))
	{
		line_num++;
		if (strstr(buffer, word))
		{
			printf("%s: %d 단어 %s이 발견됨\n", fname, line_num, word);
		}
	}
	fclose(fp);
}
//20191130