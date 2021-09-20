#include<stdio.h>

int gcd(int x, int y);

int main(void)
{
	int input_x;
	int input_y;
	printf("x와 y를 입력하시오(x>y) : ");
	scanf_s("%d %d", &input_x, &input_y);

	printf("입력한 두 수의 최대공약수는 %d입니다.\n", gcd(input_x, input_y));
}

int gcd(int x, int y)
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		return gcd(y, x % y);
	}

}