#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE* fp1, * fp2;
	char file1[100], file2[100];
	char buffer[100];

	printf("파일 이름:  ");
	scanf("%s", file1);

	printf("파일 이름:  ");
	scanf("%s", file2);

	fp1 = fopen(file1, "r");
	if (fp1 == NULL)
	{
		fprintf(stderr, "파일 %s을 열 수 없습니다.\n", file1);
		exit(1);
	}

	fp2 = fopen(file2, "w");
	if (fp2== NULL)
	{
		fprintf(stderr, "파일 %s을 열 수 없습니다.\n", file2);
		exit(1);
	}

	// 첫번째 파일을 두번째 파일로 복사한다.
	while (fgets(buffer, 100, fp1) != NULL)
	{
		char* pos = strtok(buffer, " ");
		while (pos != NULL) {
			if (strcmp("Android", pos) == 0)
				fprintf(fp2, "안드로이드 ");
			else
				fprintf(fp2, "%s ", pos);
			pos = strtok(NULL, " ");
		}
	}
	fclose(fp1);
	fclose(fp2);
}
//20191130 suceess
