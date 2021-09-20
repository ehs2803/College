#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int a, b, c;
	int i, j, k;
	int s, d;

	s = 0;
	d = 0;

	srand((unsigned)time(NULL));

	i= (rand() % 9) + 1;
	j= (rand() % 9) + 1;
	k= (rand() % 9) + 1;

	for (;;)
	{
		
		printf("세수를 입력하시오.");
		scanf_s("%d %d %d", &a, &b, &c);
	

		if (a == i)
		{
			s = s + 1;
		}
		else if (a == j)
		{
			d = d + 1;
		}
		else if (a == k)
		{
			d = d + 1;
		}
		else
		{

		}
		
		if (b == j)
		{
			s = s + 1;
		}
		else if (b == k)
		{
			d = d + 1;
		}
		else if (b == i)
		{
			d = d + 1;
		}
		else
		{

		}

		if (c == k)
		{
			s = s + 1;
		}
		else if (c == j)
		{
			d = d + 1;
		}
		else if (c == i)
		{
			d = d + 1;
		}
		else
		{

		}

		printf("%d볼 %d스트라이크\n", d, s);
		
		if (s == 3)
		{
			break;
		}

	}
	

}