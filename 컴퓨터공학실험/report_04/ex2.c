#include<stdio.h>

enum sing { doe, re, mi, fa, so, la, ti };

char* song[] = { "a deer, a female deer","a drop of gollen sun",
"a name i call myself","a long long way to run","a needle pulling thread",
"a note to follow sew","a drink woth jam on bread" };

int main(void)
{
	char c[4];
	enum sing d;

	while (1)
	{
		scanf_s("%s", c,4);

		if (strcmp(c, "doe") == 0)
		{
			printf("<Doe>, %s\n", song[0]);
		}
		else if (strcmp(c, "re") == 0)
		{
			printf("<Ray>, %s\n", song[1]);
		}
		else if (strcmp(c, "mi") == 0)
		{
			printf("<Me>, %s\n", song[2]);
		}
		else if (strcmp(c, "fa") == 0)
		{
			printf("<Far>, %s\n", song[3]);
		}
		else if (strcmp(c, "so") == 0)
		{
			printf("<Sew>, %s\n", song[4]);
		}
		else if (strcmp(c, "la") == 0)
		{
			printf(", %s\n", song[5]);
		}
		else if (strcmp(c, "ti") == 0)
		{
			printf("<Tea>, %s\n", song[6]);
			printf("That will bring us back to doe(oh~oh~oh)");
		}
	}
}
//20191126