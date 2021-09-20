#include<stdio.h>

void input_number();
void draw_rect(int w, int h);



int main(void)
{  
	int in1, in2;
	input_number(&in1,&in2);
	draw_rect(in1, in2);
}

void input_number(int *a, int *b)
{

	printf("input w, h : ");
	scanf_s("%d %d", &*a, &*b);

}

void draw_rect(int w, int h)
{
	int i, j;

	for (i = 1; i < h + 1; i++)
	{
		for (j = 0; j < w; j++)
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
//20191028