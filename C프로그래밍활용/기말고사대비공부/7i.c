#include<stdio.h>
#define _CTR_SECURE_NO_WARNING

int main(void)
{
	FILE* fp;

	char fname[10];
	char name[10];
	int number, count = 0;
	float score, total = 0;

	printf("성적파일 이름을 입력하시오:");
	scanf("%s", fname);

	fp = fopen(fname, "w");
	if (fp == NULL)
	{
		fprintf(stderr, "성적파일 %s을 열 수 없습니다.\n", fname);
		exit(1);
	}
	else
	{
		printf("파일 열기 성공\n");
	}

	while (1)
	{
		printf("학번, 이름, 성적을 입력하시오: (음수이면 종료)");
		scanf("%d", &number);
		if (number < 0)
		{
			break;
		}
		scanf("%s %f", name, &score);
		fprintf(fp, " %d %s %f", number, name, score);
	}
	fclose(fp);

	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		fprintf(stderr,"성적 파일 %s을 열 수 없습니다.\n",fname);
		exit(1);
	}
	else
	{
		printf("파일 열기 성공\n");
	}

	while (!feof(fp))
	{
		fscanf(fp, " %d %s %f", &number, name, &score);
		total = total + score;
		count++;
	}
	fclose(fp);
	printf("평균 = %f\n", total / count);
	
}
//20191130