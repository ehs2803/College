#include<stdio.h>

double tri();
int rect();
double circle();
struct shape {
	int type;
	union {
		struct { int base, height; }tri;
		struct { int width, height; }rect;
		struct { int radius; }circ;
	}data;
};

struct shape a;
int main(void)
{
	printf("������ Ÿ���� �Է��Ͻÿ�(0, 1, 2): ");
	scanf_s("%d", &a.type);

	
	if (a.type == 0)
	{
		printf("������ %lf", tri());
	}
	else if (a.type == 1)
	{
		printf("������ %d", rect());
	}
	else if (a.type == 2)
	{
		printf("������ %lf", circle());
	}
}

double tri()
{
	double result;
	printf("�غ��� ���̸� �Է��ϼ���: ");
	scanf_s("%d %d", &a.data.tri.base, &a.data.tri.height);
	result = 0.5 * (double)(a.data.tri.base) * (double)(a.data.tri.height);
	return result;
}

int rect()
{
	int result;
	printf("���ο� ������ ���̸� �Է��Ͻÿ�(���� �� 100 200): ");
	scanf_s("%d %d", &a.data.rect.width, &a.data.rect.height);
	result = a.data.rect.width * a.data.rect.height;
	return result;
}

double circle()
{
	double result;
	printf("�������� �Է��ϼ���: ");
	scanf_s("%d", &a.data.circ.radius);
	result = 3.14 * (double)(a.data.circ.radius) * (double)(a.data.circ.radius);
	return result;
}
//20191122
