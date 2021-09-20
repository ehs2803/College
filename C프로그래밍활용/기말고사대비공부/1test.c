#define _CRT_SECURE_NO_WARNING
#include<stdio.h>

int main(void)
{
	int i;
	char a[100];
	char b[100];
	gets(a);
	i = strlen(a);
	scanf("%s", b);
	printf("%s %s", a, b);
	
}
//20191126