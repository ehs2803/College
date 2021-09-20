#include<stdio.h>
#include<string.h>

int main(void)
{
	char s[] = "language";
	char c = 'g';
	char* p = strchr(s, c);
	int loc;

	loc = (int)(p - s);

	if (p != NULL)
	{
		printf("%s에서 첫번째 %c가 %d에서 발견됨.\n", s, c, loc);
	}
	else
	{
		printf("%c가 발견되지 않았음.\n", c);
	}
}
//20191129