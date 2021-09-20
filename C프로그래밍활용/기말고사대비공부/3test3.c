#include<stdio.h>

int main(void)
{
	char s[] = "ab, c, d";

	char seps[] = ", ";

	char* tok;

	tok = strtok(s, seps);

	while (tok != NULL)
	{
		printf("ÅäÅ«: %s\n", tok);
		tok = strtok(NULL, seps);
	}
}
//20191120