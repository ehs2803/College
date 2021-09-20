#include<stdio.h>
#define _CRT_SECURE_NO_WARNING

int main(void)
{
	int i;
	int buffer[5];
	FILE* fp;

	fp = fopen("binary.bin", "rb");
	if (fp == NULL)
	{
		fprintf(stderr, "binary.bin 파일을 열 수 없습니다.");
		return 1;
	}
	fread(buffer, sizeof(int), 5, fp);

	for (i = 0; i < 5; i++)
	{
		printf("%d ", buffer[i]);
	}
	
	fclose(fp);
}