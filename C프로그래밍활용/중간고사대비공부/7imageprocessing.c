#include<stdio.h>

#define SIZE 5

void print_image(int a[]);
void brighten_image(int a[][SIZE]);

int main(void)
{
	int image[SIZE][SIZE] = {
		{10,20,30,40,50},
		{10,20,30,40,50},
		{10,20,30,40,50},
		{10,20,30,40,50},
		{10,20,30,40,50}
	};

	print_image(image);
	brighten_image(image);
	print_image(image);

}

void print_image(int a[][SIZE])
{
	int i, j;
	for (i = 0; i < SIZE;i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			printf("%3d ",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void brighten_image(int a[SIZE][SIZE])
{
	int i, j;
	int* p;
	p = &a[0][0];
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			*p = *p + 10;
			p++;
		}
	}
}
//20191015