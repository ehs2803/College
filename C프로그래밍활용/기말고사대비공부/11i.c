#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp1, * fp2, * fp3;
	char file1[100], file2[100], file3[100];
	char buffer[100];

	printf("���� �̸� �Է�:");
	scanf("%s", file1);
	printf("���� �̸� �Է�:");
	scanf("%s", file2);
	printf("��ģ ���� �̸� �Է�:");
	scanf("%s", file3);

	printf("%s ����+ %s������ %s���Ϸ� �����մϴ�.\n", file1, file2, file3);
	// ù��° ������ �б� ���� ����.
	if ((fp1 = fopen(file1, "r")) == NULL)
	{
		fprintf(stderr, "���� ���� %s�� �� �� �����ϴ�.\n", file1);
		exit(1);
	}

	// �ι�° ������ �б� ���� ����.
	if ((fp2 = fopen(file2, "r")) == NULL)
	{
		fprintf(stderr, "���� ���� %s�� �� �� �����ϴ�.\n", file2);
		exit(1);
	}
	// �ι�° ������ �б� ���� ����.
	if ((fp3 = fopen(file3, "w")) == NULL)
	{
		fprintf(stderr, "��� ���� %s�� �� �� �����ϴ�.\n", file3);
		exit(1);
	}

	// ù��° ������ �ι�° ���Ϸ� �����Ѵ�.
	while (fgets(buffer, 100, fp1) != NULL)
		fputs(buffer, fp3);

	fprintf(fp3, "\n");
	// ù��° ������ �ι�° ���Ϸ� �����Ѵ�.
	while (fgets(buffer, 100, fp2) != NULL)
		fputs(buffer, fp3);

	fclose(fp1);
	fclose(fp2);
	fclose(fp3);

}
//20191130 success