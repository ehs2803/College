#include <stdio.h>

int main(void)
{
	FILE* fp = NULL;
	FILE* fpout = NULL;
	char buffer[1000];
	char name[1000];
	int korean, math, english;

	fp = fopen("sample.txt", "r");
	fpout = fopen("sample2.txt", "w");
	
	fprintf(fpout,"name  average\n");//�ѱ� �Է½� ���ڿ��� �̻��Ѱ�������. ���� or ���ڷθ�!!
	fgets(buffer, 1000, fp);
	while (fgets(buffer, 1000, fp) != NULL)
	{
		sscanf(buffer, "%s %d %d %d", name, &korean, &math, &english);
		fprintf(fpout, "%s %10.2f\n", name, (korean + math + english) / 3.0);
	}
	fclose(fp);
	fclose(fpout);
	return 0;
}
//20191215
