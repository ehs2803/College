#include <stdio.h>

int main(void)
{

	int speed = 300000;
	int distance = 149600000;
	int min;
	int sec;
	int a;

	a = distance / speed;
	min = a / 60;
	sec= a% 60;

	printf("%dºĞ%dÃÊ", min,sec);





}