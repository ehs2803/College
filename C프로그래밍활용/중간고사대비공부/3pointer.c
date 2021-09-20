#include<stdio.h>

int main(void)
{
	int i = 10;
	int* pi = &i;

	printf("i = %d, pi = %u", i, pi);
	(*pi)++;
	printf("i = %d, pi = %u", i, pi);
	*pi++;
	printf("i = %d, pi = %u", i, pi);
}
//20191010