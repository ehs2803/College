#include<stdio.h>

int add(int* a, int* b);
int sub(int* a, int* b);

int main(void)
{
	int in1, in2;

	printf("3�ڸ� ������ �Է��Ͻÿ�: ");
	scanf("%d %d", &in1, &in2);

	printf("���ҵ����� = %d\n", add(&in1, &in2));
	printf("���ҵ����� = %d\n", sub(&in1, &in2));

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

