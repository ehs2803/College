#include<stdio.h>

int input_number();
void draw_rect(int w, int h);

int in1, in2;

int main(void)
{   
	input_number();
	draw_rect(in1, in2);
}

int input_number()
{
	int a, b;

	printf("input w, h : ");
	scanf_s("%d %d", &a, &b);

	in1 = a;
	in2 = b;
}

void draw_rect(int w, int h)
{
	int i, j;

	for (i=1;i<h+1;i++)
	{
		for (j = 0; j < w;j++)
		{
			if (i % 2 == 1)
			{
				printf("*");
			}
			else
			{
				printf("#");
			}
		}
		printf("\n");
	}
}
//20191009