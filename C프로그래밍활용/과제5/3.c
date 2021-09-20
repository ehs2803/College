#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
struct student {
	int number;
	char name[20];
	double gpa;
};

int main(void)
{
	struct student table[3] = {
		{1,"kim",3.99},
		{2,"Min",2.68},
		{3,"Lee",4.01}
	};
	struct student s;
	FILE* fp;
	int i;

	fp = fopen("student.dat", "wb");
	if (fp == NULL)
	{
		fprintf(stderr, "출력을 위한 파일을 열 수 없습니다.\n");
		exit(1);
	}
	fwrite(table, sizeof(struct student), 3, fp);
	fclose(fp);

	fp = fopen("student.dat", "rb");
	if (fp == NULL)
	{
		fprintf(stderr, "입력을 위한 파일을 열 수 없습니다.\n");
		exit(1);
	}

	for (i = 0; i < 3; i++)
	{
		fread(&s, sizeof(struct student), 1, fp);
		printf("학번=%d, 이름=%s, 평점=%f\n", s.number, s.name, s.gpa);
	}
	fclose(fp);
}