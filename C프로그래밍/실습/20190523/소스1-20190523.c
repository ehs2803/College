#include<stdio.h>
int max(int i, int j);

int main(void)
{
	int a, b;

	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &a);
	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &b);

	printf("�ΰ��� ������ ū����: %d", max(a, b));

}
int max(int i, int j)
{
	return i > j ? i: j;
}
