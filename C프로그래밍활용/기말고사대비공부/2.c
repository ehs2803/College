#include<stdio.h>

int main(void)
{
	FILE* fp;
	char fname[20];
	int number, count = 0;
	char name[20];
	float score, total = 0;

	printf("���� ���� �̸��� �Է��Ͻÿ�: ");
	scanf("%s", fname);

	if ((fp = fopen(fname, "w")) == NULL)
	{
		fprintf(stderr, "���� ���� %s�� �� �� �����ϴ�.\n", fname);
		exit(1);
	}

	while (1)
	{
		printf("�й�, �̸�, ������ �Է��Ͻÿ�: (�����̸� ����)");
		scanf("%d", &number);
		if (number < 0)
		{
			break;
		}
		scanf("%s %f", name, &score);
		fprintf(fp, " %d %s %f", number, name, score);
	}
	fclose(fp);

	if ((fp = fopen(fname, "r")) == NULL)
	{
		fprintf(stderr, "���� ���� %s�� �� �� �����ϴ�.\n", fname);
		exit(1);
	}

	while (!feof(fp))
	{
		fscanf(fp, "%d %s %f", &number, name, &score);
		total = total + score;
		count++;
	}

	printf("��� =%f\n", total / count);
	fclose(fp);
}
//20191128