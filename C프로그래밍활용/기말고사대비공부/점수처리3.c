#include<stdio.h>

int main(void)
{
	FILE* fp;
	char fname[20];
	int number, count;
	char name[20];
	float score, total = 0;
	char buffer[100];
	printf("�������� �̸�:"); scanf("%s", fname);
	fp = fopen(fname, "w");

	while (1)
	{
		printf("�й�, �̸�, ������ �Է��Ͻÿ�:"); scanf("%d", &number);
		if (number < 0)
		{
			break;
		}
		scanf("%s %f", name, &score);
		fprintf(fp, " %d %s %f\n", number, name, score);//\n�� ���̸� ���ڰ� �ణ �̻�����
	}
	fclose(fp);
	count = 0;
	fp = fopen("fname.txt", "r");
	while (fgets(buffer,100,fp))
	{
		sscanf(buffer, "%d %s %f", &number, name, &score);
		//fscanf(fp, "%d %s %f", &number, name, &score);
		total = total + score;
		count++;
	}
	printf("��� = %f\n", total / count);
	fclose(fp);
}
//20191216