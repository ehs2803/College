#include<stdio.h>
#define _CRT_SECURE_NO_WARNINH

int main(void)
{
	FILE* fp1, * fp2;
	char file1[10], file2[10];
	char buffer[100];

	printf("원본 파일 이름: ");
	scanf("%s", file1);
    fp1 = fopen(file1, "r");
    if (fp1 == NULL)
	{
		fprintf(stderr, "파일 %s을 열수없음\n", file1);
		exit(1);
	}

	printf("복사 파일 이름: ");
	scanf("%s", file2);
	fp2 = fopen(file2, "w");
	if (fp2 == NULL)
	{
		fprintf(stderr, "파일 %s을 열수없음\n", file2);
		exit(1);
	}

	while (fgets(buffer, 100, fp1) != NULL)
	{
		fputs(buffer, fp2);
	}
	fclose(fp1);
	fclose(fp2);
}
//20191130