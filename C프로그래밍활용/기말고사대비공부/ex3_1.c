#include<stdio.h>
#include<string.h>

void array(char* a, int b);

int main(void)
{
	int size;
	char in[50];
	printf("input : ");
	gets(in,50);

	size = strlen(in);
	array(in, size);

}

void array(char* a, int b)
{
	int i;
	for (i = b; i > -1; i--)
	{
		printf("%c", a[i]);
	}
}
//20191106
