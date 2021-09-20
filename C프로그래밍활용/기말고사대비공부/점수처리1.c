#include<stdio.h>

int main(void)
{
	FILE* fp;
	char fname[20];
	int number, count;
	char name[20];
	float score, total=0;

	printf("성적파일 이름:"); scanf("%s", fname);
	fp = fopen("fname.txt", "w");

	while (1)
	{
		printf("학번, 이름, 성적을 입력하시오:"); scanf("%d", &number);
		if (number < 0)
		{
			break;
		}
		scanf("%s %f", name, &score);
		fprintf(fp, " %d %s %f", number, name, score);//\n을 붙이면 숫자가 약간 이상해짐
	}
	fclose(fp);
	count = 0;
	fp = fopen("fname.txt", "r");
	while (!feof(fp))
	{
		fscanf(fp, "%d %s %f", &number, name, &score);
		total = total + score;
		count++;
	}
	printf("평균 = %f\n", total / count);
	fclose(fp);
}
//20191215