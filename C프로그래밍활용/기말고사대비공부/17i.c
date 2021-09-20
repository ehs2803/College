#include<stdio.h>

int main(void)
{
	FILE* fp;
	char fname[10];
	char word[10];
	char buffer[256];
	char buffer1[256];
	char* token;
	char* list[100];
	char seq[] = " \n.";
	int line = 0;
	int count;
	int i;
	printf("파일 이름: ");
	scanf("%s", fname);
	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "파일%s 열기 실패\n");
	}
	else
	{
		printf("파일 열기 성공\n");
	}
	printf("탐색할 단어:");
	scanf("%s", word);
	while (fgets(buffer, 256, fp))
	{
		line++;
		for (i = 0; buffer[i] != 0; i++)
		{
			buffer1[i] = buffer[i];
		}
		buffer1[i] = '\0';
		token = strtok(buffer, seq);
		count = 0;
		while (token != NULL)
		{
			list[count] = token;
			token = strtok(NULL, seq);
			count++;
		}
		for (i = 0; i < count; i++)
		{
			if (strcmp(list[i], word) == 0)
			{
               printf("%s:%d %s\n", fname, line, buffer1);
			}
		}
	}
}//20191215 추가수정
/*#include<stdio.h>

int main(void)
{
	FILE* fp;
	char fname[10];
	char word[10];
	char buffer[256];
	int line = 0;
	printf("파일 이름: ");
	scanf("%s", fname);
	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "파일%s 열기 실패\n");
	}
	else
	{
		printf("파일 열기 성공\n");
	}
	printf("탐색할 단어:");
	scanf("%s", word);
	while (fgets(buffer, 256, fp))
	{
        line++;
		if (strstr(buffer, word))
		{
			printf("%s:%d %s", fname, line, buffer);
		}
	}
}
*/
//20191201 success