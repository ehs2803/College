#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNING

int main(void)
{
	FILE* fp1, * fp2;
	char file1[100], file2[100];
	int c1, c2;
	int cn1=0, cn2=0;

	printf("첫번쨰 파일 이름:  ");
	scanf("%s", file1);

	printf("두번째 파일 이름:  ");
	scanf("%s", file2);

	fp1 = fopen(file1, "r");
	if (fp1 == NULL)
	{
		fprintf(stderr, "원본 파일 %s을 열 수 없습니다.\n", file1);
		exit(1);
	}

	fp2 = fopen(file2, "r");
	if (fp2 == NULL)
	{
		fprintf(stderr, "복사 파일 %s을 열 수 없습니다.\n", file2);
		exit(1);
	}

	while (c1 = fgetc(fp1) != EOF)
	{
		cn1++;
	}
	while (c2 = fgetc(fp2) != EOF)
	{
		cn2++;
	}
	if (cn1 != cn2)
	{
		printf("두 파일은 서로 다릅니다.\n");
		return 0;
	}
	fseek(fp1, 0, SEEK_SET);
	fseek(fp2, 0, SEEK_SET);
	while (1)
	{
		c1 = fgetc(fp1);
		c2 = fgetc(fp2);

		if (c1 == EOF || c2 == EOF)
		{
			break;
		}	
		if (c1 != c2)
		{
			printf("두 파일은 서로 다릅니다.\n");
			return 0;
		}
	}
	printf("두 파일은 서로 같습니다.\n");
	
	fclose(fp1);
	fclose(fp2);
}
//20191130 success-20191207
/*
	while (1) {
		int c1 = fgetc(fp1);
		int c2 = fgetc(fp2);
		if (c1 == EOF || c2 == EOF)
			break;
		if (c1 != c2) {
			printf("두 파일은 서로 다릅니다.\n");
			return 0;
		}
	}
	printf("두 파일은 서로 같습니다.\n");
	*///한줄만 비교가능