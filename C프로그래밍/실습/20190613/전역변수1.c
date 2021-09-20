#include<stdio.h>
#include "addd.h"

int result = 0;

int main(void)
{

	int a, b;


	printf("input");
	scanf("%d", &a);
	printf("input");
	scanf("%d", &b);

	add(a, b);
	printf("%d", result);

}

