#include<stdio.h>

int main(void)
{
	char s[] = "100";
	int value;

	sscanf_s(s, "%d", &value);
	printf("%d\n", value);

	value++;

	sprintf_s(s, "%d", value);
	printf("%s", s);
}
//20191107 error