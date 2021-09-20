#include<stdio.h>

int main(void)
{
	int x, y, z;

	x = 10;
	y = 20;

	printf("x=%d y=%d\n", x, y);

	z = x;
	x = y;
	y = z;

	printf("x=%d y=%d", x, y);


}