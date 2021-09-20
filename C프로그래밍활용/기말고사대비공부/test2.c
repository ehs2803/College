#include<stdio.h>
#include<string.h>

int main(void)
{
	char a[20] = "abc def";
	char b[20] = "abc deff";

	if (strcmp(a, b) == 0)
	{
		printf("ok\n");
	}
}
//20191207