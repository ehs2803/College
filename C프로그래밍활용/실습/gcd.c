#include<stdio.h>

int gcd(int x, int y);

int main(void)
{
	int input_x;
	int input_y;
	printf("x�� y�� �Է��Ͻÿ�(x>y) : ");
	scanf_s("%d %d", &input_x, &input_y);

	printf("�Է��� �� ���� �ִ������� %d�Դϴ�.\n", gcd(input_x, input_y));
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