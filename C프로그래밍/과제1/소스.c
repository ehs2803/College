#include <stdio.h>

int main(void)
{

	float speed = 30;
	float distance = 14960;
	float min;
	float a;
	int b;

	min = distance / speed / 60;
	a = min - 8.0;
	b = a * 1000000;

	printf("%f\b\b\b\b\b\b\bºĞ%dÃÊ", min,b);



}