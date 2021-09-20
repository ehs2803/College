#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	FILE* fp;
	int num;
	char buffer[10]="abcdefg";
	printf("input number: ");
	scanf("%d", &num);

	fp = fopen("ex2.txt", "wt");
	if (fp == NULL)
	{
		printf("error exit\n");
		return 1;
	}
	fprintf(fp, "examplefile.\n");
	fprintf(fp, "input number is %d", num);
	fprintf(fp, "%s", buffer);
	fclose(fp);

	printf("success\n");
}
//20191205