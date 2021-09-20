#include<stdio.h>
#include "add.h"

int main(void)
{

	int a, b, c;
	int result;

	printf("input");
	scanf("%d", &a);
	printf("input");
	scanf("%d", &b);
	printf("input");
	scanf("%d", &c);
	result = add(add(a, b),c);
	printf("%d", result);

}