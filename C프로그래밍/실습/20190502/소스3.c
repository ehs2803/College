#include<stdio.h>

int main(void)
{

	int a;
	int i;
BBB:
    a = 1;
    i = 1;
	printf("¸î´Ü?");
	scanf("%d", &a);
    
	if (a != 0)
	{
		
AAA:

	printf("%d*%d=%d\n", a, i, a*i);
	i++;
	if (i < 10)
	{
		goto AAA;
	}
	
	goto BBB;

	}
	else if(a==0)
	{
		
	}
	
}