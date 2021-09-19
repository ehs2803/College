#include<stdio.h>

int main(void) 
{
	int a = 10, b = 20;
	b = ++a;
	printf("(1) a = %d, b = %d\n", a, b);

	a = 10, b = 20;
	a = (a > b) ? 3 : -3;
	printf("(2) a = %d, b = %d\n", a, b);

	a = 10, b = 20;
	a = a + b % 3 + 4; 
	printf("(3) a = %d, b = %d\n", a, b);

	a = 10, b = 20;
	b >>= 2; 
	printf("(4) a = %d, b = %d\n", a, b);
}