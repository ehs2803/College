#include<stdio.h>

void print_binary(int x);

int main(void)
{
	int num;
	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &num);

	printf("%d�� �������� =  ", num);
	print_binary(num);

}

void print_binary(int x)
{
	if (x > 0)
	{
		print_binary(x / 2);
		printf("%d", x % 2);
	}
}