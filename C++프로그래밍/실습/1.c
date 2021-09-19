#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<process.h>

int combi(int n, int r); //nCr��� �Լ�
int fact(int n);        //n!��� �Լ�
void output(int r, int c, int** data);//����Լ�
void copy(int r, int c, int** be_data, int** data);//data�� be_data�� ����

int main(void) {
	int element, i, j, k, **data, **be_data, be_row, col, r, c;//��������
	system("cls");
	element = 4;//{1, 2, 3, 4}�� ������ ���ϱ�
    //���� ���� ���
	printf("\n### Set = {");
	for (i = 1; i < element; i++)
	{
		printf("%d,", i);
	}
	printf("%d}\n\n", i);
	printf("### ? �� ������ ǥ���Դϴ�.\n\n");
	printf("### ������ = {");
	printf("%c%c,", 237, 44); //? ���

	i = element / 2;
	j = combi(element, i);
	data = (int**)malloc(sizeof(int) * j);
	for (i = 0;i < j;i++)
	{
		*(data + i) = (int*)malloc(sizeof(int) * element);
	}
	be_data = (int**)malloc(sizeof(int) * j);
	for (i = 0;i < j;i++)
	{
		*(be_data + i) = (int*)malloc(sizeof(int) * element);
	}

	c = 1;
	r = combi(element, c);
	for (i = 0;i < r;i++)
	{
		for (j = 0;j < c;j++)
		{
			be_data[i][j] = i + 1;
		}
	}
	output(r, c, be_data);

	for (col = 2;col < element;col++)
	{
		be_row = combi(element, col - 1);
		r = 0;
		for (i = 0;i < be_row;i++)
		{
			if (i < be_data[i][col - 2] < element)
			{
				for (j = be_data[i][col - 2] + 1;j <= element;j++)
				{
					for (k = 0;k < col - 1;k++)
					{
						data[r][k] = be_data[i][k];
					}
					data[r++][k] = j;
				}
			}
		}
		output(r, col, data);

		k = combi(element, element / 2);
		for (i = 0;i < k;i++)
		{
			for (j = 0;j < element;j++)
			{
				be_data[i][j] = 0;
			}
		}
		copy(r, col, be_data, data);
		for (i = 0;i < k;i++)
		{
			for (j = 0;j < element;j++)
			{
				data[i][j] = 0;
			}
		}
	}

    //������ �� �������ִ� �������
	printf("{");
	for (i = 1;i < element;i++)
	{
		printf("%d,", i);
	}
	printf("%d", i);
	printf("}}\n");
	system("pause");
}

int combi(int n, int r) //nCr��� �Լ�
{
	return fact(n) / (fact(r) * fact(n - r));
}

int fact(int n) //n!��� �Լ�
{
	if (n == 0)return 1;
	else return (fact(n - 1) * n);
}

void output(int r, int c, int** data)//����Լ�
{
	int i, j;
	for (i = 0;i < r;i++)
	{
		printf("{");
		for (j = 0;j < c-1;j++)
		{
			printf("%d,", data[i][j]);
		}
		printf("%d},", data[i][j]);
	}
}

void copy(int r, int c, int** be_data, int** data)//�����Լ�
{
	int i, j;
	for (i = 0;i < r;i++)
	{
		for (j = 0;j < c;j++)
		{
			be_data[i][j] = data[i][j];
		}
	}
}