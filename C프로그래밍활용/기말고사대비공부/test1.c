#include<stdio.h>

int main(void)
{
	char a;
	int i;
	char b[10];

	scanf("%d", &i);
	getchar();
	
	scanf("%c", &a);
	getchar();

	gets(b);
	
	printf("%d %c %s", i, a, b);
}
//20191201 pm10:43