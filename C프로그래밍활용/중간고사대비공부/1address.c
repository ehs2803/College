#include<stdio.h>

int main(void)
{
	int i = 10;
	char c = 69;
	double f = 12.3;

	int* a;
	int* b;
	int* d;

	a = &i;
	b = &c;
	d = &f;

	printf("i의 주소: %u %u\n", &i,a);
	printf("c의 주소: %u %u\n", &c,b);
	printf("f의 주소: %u %u\n", &f,d);

	printf("%d", *a);//간접 참조 연산자
	
}
//20191010