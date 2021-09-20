#define _CRT_SECURE_NO_WARNING
#include<stdio.h>

int main(void)
{
	FILE* fp;
	char fname[128];
	char buffer[256];
	char word[256];
	int line_num = 0;

	printf("입력 파일 이름 입력: ");
	scanf("%s", fname);

	printf("탐색 단어 입력: ");
	scanf("%s", word);

	if ((fp = fopen(fname, "r")) == NULL)
	{
		fprintf(stderr, "파일 %s을 열 수 없습니다.\n", fname);
		exit(1);
	}
	while (fgets(buffer, 256, fp))//fgets는 한줄씩
	{
		line_num++;
		if (strstr(buffer, word))
		{
			printf("%s : %d 단어 %s이 발견되었습니다\n", fname, line_num, word);
		}
	}
	fclose(fp);
}