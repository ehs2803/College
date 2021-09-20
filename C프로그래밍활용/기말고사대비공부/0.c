#include<stdio.h>

int main(void)
{
	FILE* fp;

	int c;
	fp = fopen("a.txt", "w");
	while ((c = getchar()) != EOF)
	{
		putchar(c);
		fputc(c, fp);
	}
	fclose(fp);
}//20191214 pm10:36