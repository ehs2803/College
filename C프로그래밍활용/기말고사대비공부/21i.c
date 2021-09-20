#include<stdio.h>

int main(void)
{
	FILE* fp1, * fp2;
	int c;

	fp1 = fopen("21i.c", "r");
	if (fp1 == NULL)
	{
		printf("error\n");
		return 1;
	}
	fp2 = fopen("char_convert.c", "w");
	if (fp2 == NULL)
	{
		printf("error\n");
	}

	while ((c = fgetc(fp1)) != EOF)
	{
		if ('a' <= c && c <= 'z')
		{
			c = c - 32;
		}
		fputc(c, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	printf("success\n");
}
//20191205