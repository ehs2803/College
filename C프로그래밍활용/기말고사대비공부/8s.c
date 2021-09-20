#define _CRT_SECURE_NO_WARNING
#include<stdio.h>

int main(void)
{
	char s[] = "100";
	int value;

	sscanf(s, "%d", &value);
	printf("%d\n", value);

	value++;

	sprintf(s, "%d", value);
	printf("%s", s);
}
//20191129