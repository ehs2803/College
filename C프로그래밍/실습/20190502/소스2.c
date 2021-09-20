#include<stdio.h>

int main(void)
{

	int a;
	int i;

BBB:
	
	i = 1;

	printf("¸î´Ü?");
	scanf("%d", &a);

AAA:

	printf("%d*%d=%d\n", a, i, a*i);
	i++;
	if (i < 10)
	{
		goto AAA;
	}

	goto BBB;


}