#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	FILE* fp1, * fp2;

	float txt[100];
	float bin[100];
	int i;

	for (i = 0; i < 100; i++)
	{
		txt[i]=rand() % 100;
		bin[i] = rand() % 100;
	}
	fp1 = fopen("ex8.txt", "w");
	fp2 = fopen("ex8.bin", "w");

	fprintf(fp1, "%d", txt);
	fwrite(bin, sizeof(float), 100, fp2);

	fclose(fp1);
	fclose(fp2);
}
//20191205