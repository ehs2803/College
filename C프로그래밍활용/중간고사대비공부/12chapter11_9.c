#include<stdio.h>

int main(void)
{
	int data[10] = { 100,200,300,400,500,600,700,800,900,1000 };
	int index;
	index = search(data, 10, 200);
	printf("월급이 200만원인 사람 = %d\n", index);
}

int search(int* a, int size, int x)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (a[i] == x)
		{
			return i;
		}
	}
	return -1;

}
//20191018