#include<stdio.h>

double area(struct circle c);
double perimeter(struct circle c);
struct point {
	int x, y;
};
struct circle {
	struct point center;
	double radius;
};

int main(void)
{
	struct circle a;

	printf("���� �߽���: ");
	scanf_s("%d %d", &a.center.x, &a.center.y);
	printf("���� ������: ");
	scanf_s("%lf", &a.radius);

	printf("���� ����=%lf, ���� �ѷ�=%lf",area(a),perimeter(a));

}

double area(struct circle c)
{
	return c.radius * c.radius * 3.14;
}

double perimeter(struct circle c)
{
	return 2 * 3.14 * c.radius;
}
//20191121