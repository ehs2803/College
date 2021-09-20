#include<stdio.h>
float area();

int main(void)
{
	float a;

	printf("원의 반지름을 입력하시오: ");
	scanf_s("%f", &a);

	printf("원의 면적은 %f입니다. ", area(a));

}

float area(float i)
{
	return 3.14* i* i;
}