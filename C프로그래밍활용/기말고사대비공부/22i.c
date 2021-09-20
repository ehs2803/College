#include <stdio.h>
#define SIZE 100

int main(void)
{
	int buffer[SIZE];
	FILE* fp = NULL;
	FILE* fp1 = NULL;
	int i;
	int count;
	char file1[100], file2[100];

	printf("원본 파일 이름:  ");
	scanf("%s", file1);

	printf("복사 파일 이름:  ");
	scanf("%s", file2);

	fp = fopen(file1, "rb");       // ①
	if (fp == NULL)
	{
		fprintf(stderr, "파일을 열 수 없습니다.");
		return 1;
	}
	fp1 = fopen(file2, "wb");       // ①
	if (fp1 == NULL)
	{
		fprintf(stderr, "파일을 열 수 없습니다.");
		return 1;
	}

	while ((count = fread(buffer, sizeof(char), SIZE, fp)) != 0) {
		fwrite(buffer, sizeof(char), count, fp1);
	}
	fclose(fp);
	fclose(fp1);
	return 0;
}
//20191205