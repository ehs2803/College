#include<stdio.h>
int max(int i, int j);

int main(void)
{
	int a, b;

	printf("정수를 입력하시오: ");
	scanf("%d", &a);
	printf("정수를 입력하시오: ");
	scanf("%d", &b);

	printf("두개의 정수중 큰값은: %d", max(a, b));

}
int max(int i, int j)
{
	return i > j ? i: j;
}
