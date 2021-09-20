#define _CRT_SECURE_NO_WARNUNG
#include<stdio.h>

int main(void)
{
	char a[100];

	fgets(a, 100, stdin);
	printf("%s", a);
}
//20191127