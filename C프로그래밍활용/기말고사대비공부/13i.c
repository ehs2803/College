#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE* fp1, * fp2;
	char file1[100], file2[100];
	char buffer[100];

	printf("���� �̸�:  ");
	scanf("%s", file1);

	printf("���� �̸�:  ");
	scanf("%s", file2);

	fp1 = fopen(file1, "r");
	if (fp1 == NULL)
	{
		fprintf(stderr, "���� %s�� �� �� �����ϴ�.\n", file1);
		exit(1);
	}

	fp2 = fopen(file2, "w");
	if (fp2== NULL)
	{
		fprintf(stderr, "���� %s�� �� �� �����ϴ�.\n", file2);
		exit(1);
	}

	// ù��° ������ �ι�° ���Ϸ� �����Ѵ�.
	while (fgets(buffer, 100, fp1) != NULL)
	{
		char* pos = strtok(buffer, " ");
		while (pos != NULL) {
			if (strcmp("Android", pos) == 0)
				fprintf(fp2, "�ȵ���̵� ");
			else
				fprintf(fp2, "%s ", pos);
			pos = strtok(NULL, " ");
		}
	}
	fclose(fp1);
	fclose(fp2);
}
//20191130 suceess
