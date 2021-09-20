#include<stdio.h>

int main(void)
{
	char a[20];
	int i;
	int len;
	gets(a);
	len = strlen(a);
	for (i = len-1; i > -1; i--)
	{
		printf("%c", a[i]);
	}
}
//20191122