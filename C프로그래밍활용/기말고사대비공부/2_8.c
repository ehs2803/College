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

	printf("원의 중심점: ");
	scanf_s("%d %d", &a.center.x, &a.center.y);
	printf("원의 반지름: ");
	scanf_s("%lf", &a.radius);

	printf("원의 면적=%lf, 원의 둘레=%lf",area(a),perimeter(a));

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