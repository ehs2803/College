#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int buffer[5] = { 10,20,30,40,50 };
	FILE* fp;

	fp = fopen("binary.bin", "wb");
	if (fp == NULL)
	{
		fprintf(stderr, "binary.bin 파일을 열 수 없습니다.");
		return 1;
	}

	fwrite(buffer, sizeof(int), 5, fp);
	fclose(fp);
}