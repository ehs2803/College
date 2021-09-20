#include<stdio.h>
#define _CRT_SECURE_NO_WARNINH

int main(void)
{
	FILE* fp1, * fp2;
	char file1[10];
	char buffer[100];

	printf("파일 이름: ");
	gets("%s",file1);
	fp1 = fopen(file1, "w");
	if (fp1 == NULL)
	{
		fprintf(stderr, "파일 %s을 열수없음\n", file1);
		exit(1);
	}
	else
	{
		printf("파일 열기 성공\n");
	}
    
	printf("입력할 내용을 입력하시오: ");
	gets(buffer);

	fputs(buffer, fp1);
	
	fclose(fp1);	
}
//20191130