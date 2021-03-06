#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	FILE* fp;
	char fname[100];
	int number, count = 0;
	char name[20];
	float score, total = 0.0;

	printf("성적 파일 입력 : ");
	scanf("%s", fname);

	if ((fp = fopen(fname, "w"))==NULL)
	{
		fprintf(stderr, "성적 파일 %s을 열 수 없다.\n", fname);
		exit(1);
	}
	while (1)
	{
		printf("학번, 이름, 성적 입력 : (음수면 종료) ");
		scanf("%d", &number);
		if (number < 0)
		{
			break;
		}
		scanf("%s %f", name, &score);
		fprintf(fp, "%d %s %f\n", number, name, score);
	}
	fclose(fp);

	if ((fp = fopen(fname, "r")) == NULL)
	{
		fprintf(stderr, "성적 파일 %s을 열 수 없다.\n", fname);
	}
	while (!feof(fp))
	{
		fscanf(fp, "%d %s %f", &number, name, &score);
		total += score;
		count++;
	}
	printf("평균 = %f\n", total / count);
	fclose(fp);

}