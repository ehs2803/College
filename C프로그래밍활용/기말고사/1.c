#include<stdio.h>

int add(int* a, int* b);
int sub(int* a, int* b);

int main(void)
{
	int in1, in2;

	printf("3자리 정수를 입력하시오: ");
	scanf("%d %d", &in1, &in2);

	printf("원소들의합 = %d\n", add(&in1, &in2));
	printf("원소들의차 = %d\n", sub(&in1, &in2));

}

int add(int* a, int* b)
{
	return *a + *b;
}
int sub(int* a, int* b)
{
	if (*a > * b)
	{
        return *a - *b;
	}
	else
	{
		return *b - *a;
	}	
}

