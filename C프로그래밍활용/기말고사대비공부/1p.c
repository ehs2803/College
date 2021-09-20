#include<stdio.h>

void MAM(int* ary, int size, int** maxptr, int** minptr);

int main(void)
{
	int ary[5];
	int i;
	int* maxp, * minp;
	int size;

	for (i = 0; i < 5; i++)
	{
		printf("input number : ");
		scanf("%d", &ary[i]);
	}

	size = sizeof(ary) / sizeof(ary[0]);

	MAM(ary, size, &maxp, &minp);

	printf("max:%d, min:%d\n", *maxp, *minp);

}

void MAM(int* ary, int size, int** maxptr, int** minptr)
{
	int i;
	*maxptr = &(ary[0]);
	*minptr = &(ary[0]);

	for (i = 0; i < size; i++)
	{
		if (ary[i] > ** maxptr)
		{
			*maxptr = &(ary[i]);
		}
	}

	for (i = 0; i < size; i++)
	{
		if (ary[i] < **minptr)
		{
			*minptr = &(ary[i]);
		}
	}
}
//20191130