#include<stdio.h>

int main(void)
{
	char a[20];
	char b[20];
	int i;

	gets(a);
	for (i = 0; a[i] != 0; i++)
	{
		b[i] = a[i];
	}
	b[i] = '\0';

	for (i = 0; b[i] != 0; i++)
	{
		printf("%c", b[i]);
	}
	printf("\n");
	puts(b);
}
//20191122