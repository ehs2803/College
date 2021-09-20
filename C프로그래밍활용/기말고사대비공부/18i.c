#include<stdio.h>

int main(void)
{
	FILE* fp1,*fp2;
	char fname[10];
	char fname1[10];
	char buffer1[256];
	char buffer2[256];
	printf("첫번째 파일 이름: ");
	scanf("%s", fname);
	fp1 = fopen(fname, "r");
	if (fp1 == NULL)
	{
		fprintf(stderr, "파일 %s을 열수 없음\n", fname);
	}
	else
	{
		printf("파일 열기 성공\n");
	}
	printf("두번째 파일 이름: ");
	scanf("%s", fname1);
	fp2 = fopen(fname1, "r");
	if (fp2 == NULL)
	{
		fprintf(stderr, "파일 %s을 열수 없음\n", fname1);
	}
	else
	{
		printf("파일 열기 성공\n");
	}
	while (fgets(buffer1,256,fp1))
	{
		fgets(buffer2, 256, fp2);
		if (strcmp(buffer1,buffer2)!=0)
		{
			printf("<< %s\n", buffer1);
			printf(">> %s\n", buffer2);
			return 0;
		}
	}
	printf("파일은 서로 일치함");
}
//20191201 success + 여러줄 출력 플러스수정하기