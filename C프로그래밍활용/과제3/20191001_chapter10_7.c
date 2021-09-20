#include<stdio.h>

int main(void)
{
	int input;
	int i, j=0;
	int a[10][3] = {
		{1,1,1},
		{2,4,8},
		{3,9,27},
		{4,16,64},
		{5,25,125},
		{6,36,216},
		{7,49,343},
		{8,64,512},
		{9,81,729},
		{10,100,1000}
	};

	printf("정수를 입력하시오: ");
	scanf_s("%d", &input);

	for (i = 0; i < 10; i++)
	{
		if (a[i][2] == input)
		{
			i = j;
		}	
	}
	printf("%d의 세제곱근은 %d",input,a[j][1]);
}