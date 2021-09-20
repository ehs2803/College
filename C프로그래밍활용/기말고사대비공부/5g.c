#include<stdio.h>
#define _CRT_SECURE_NO_WARNING
int equal(struct point* s1, struct point* s2);
struct point {
	int x;
	int y;
};

int main(void)
{
	struct point p1, p2;
	int in;

	printf("입력하시오: ");
	scanf("%d %d", &p1.x, &p1.y);
	printf("입력하시오: ");
	scanf("%d %d", &p2.x, &p2.y);
	in = equal(&p1, &p2);
	if (in == 1)
	{
		printf("(%d, %d) = (%d, %d)", p1.x, p1.y, p2.x, p2.y);
	}
	else
	{
		printf("(%d, %d) != (%d, %d)", p1.x, p1.y, p2.x, p2.y);
	}

}

int equal(struct point* s1, struct point* s2)
{
	if (s1->x == s2->x)
	{
		if (s1->y == s2->y)
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}
//20191129