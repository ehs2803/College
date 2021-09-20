#include<stdio.h>
#include<string.h>

int main(void)
{
	int i;
	char ch[10];
	char in[6] = "love";

	scanf_s("%s", ch,10);

	for (i = 0; ch[i] != 0; i++)
	{
		if ('A' <= ch[i] && ch[i] <= 'Z')
		{
			ch[i] = ch[i] + 32;
		}
	}

	if (strcmp(in, ch) == 0)
	{
		printf("I love you.");
	}
}
//20191122