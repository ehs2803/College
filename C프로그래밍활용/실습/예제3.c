#define _CRT_SECURE_NO_WARNING
#include<stdio.h>

int main(void)
{
	FILE *fp1, * fp2;
	char file1[100], file2[100];
	char buffer[100];

	printf("원본 파일 이름: ");
	scanf("%s", file1);
	printf("복사 파일 이름 : ");
	scanf("%s", file2);

	if ((fp1 = fopen(file1, "r")) == NULL)
	{
		fprintf(stderr, "원본 파일 %s을 열 수 없습니다.\n", file1);
		exit(1);//강제종료명령어
	}
	if ((fp2 = fopen(file2, "w")) == NULL)
	{
		fprintf(stderr, "복사 파일 %s을 열 수 없습니다.\n", file2);
		exit(1);
	}
	while (fgets(buffer, 100, fp1) != NULL)
	{
		fputs(buffer, fp2);
	}
	fclose(fp1);
	fclose(fp2);
}