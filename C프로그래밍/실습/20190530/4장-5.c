#include<stdio.h>
#define SQMETER_PER_PYEONG 3.3058

int main(void)
{
	int a;
	float b;

	printf("���� �Է��ϼ���: ");
	scanf_s("%d", &a);

	b = SQMETER_PER_PYEONG * a;

	printf("%f�������Դϴ�.", b);
}