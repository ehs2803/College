#include <stdio.h>

int main(void)
{
	FILE* fp,* fpout;
	char buffer[1000];
	char name[1000];
	char fname[10], fname1[10];
	int korean, math, english;

	printf("���������� �̸� �Է�:");
	scanf("%s", fname);
	fp = fopen(fname, "r");
	if (fp == NULL) {
		printf("���� ���� ����\n");
		return 1;
	}

	printf("�Է����� �̸� �Է�:");
	scanf("%s", fname1);
	fpout = fopen(fname1, "w");
	if (fpout == NULL) {
		printf("���� ���� ����\n");
		return 1;
	}
	
	//fprintf(fpout,"�̸�    ���\n");

	//fgets(buffer, 1000, fp);
	//sscanf(buffer, "%s %d %d %d", name, &korean, &math, &english);
	while (fgets(buffer, 1000, fp) != NULL)
	{
		sscanf(buffer, "%s %d %d %d", name, &korean, &math, &english);
		fprintf(fpout, "%s", name);
		fprintf(fpout, "%10.2f\n", (korean + math + english) / 3.0);
	}
	fclose(fp);
	fclose(fpout);
}
//20191130
/*#include <stdio.h>

int main(void)
{
	FILE* fp = NULL;
	FILE* fpout = NULL;
	char buffer[1000] = { 0 };
	char name[1000] = { 0 };
	int korean, math, english;

	fp = fopen("sample.txt", "r");
	if (fp == NULL) {
		printf("���� ���� ����\n");
		return 0;
	}
	fpout = fopen("sample1.txt", "w");
	if (fpout == NULL) {
		printf("���� ���� ����\n");
		return 0;
	}
	while (fgets(buffer, 1000, fp) != NULL)
	{
		sscanf(buffer, "%s %d %d %d", name, &korean, &math, &english);
		fprintf(fpout, "%s", name);
		fprintf(fpout, "%10.2f\n", (korean + math + english) / 3.0);
	}
	fclose(fp);
	return 0;
}*/