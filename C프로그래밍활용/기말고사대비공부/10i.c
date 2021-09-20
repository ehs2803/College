#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp1;
	char file1[100];
	char buffer[1000];
	char* p;

	printf("파일 이름을 입력하시오:  ");
	scanf("%s", file1);
	getchar();
	fp1 = fopen(file1, "w");
	if (fp1 == NULL)
	{
		fprintf(stderr, "파일 %s을 열 수 없습니다.\n", file1);
		exit(1);
	}

	while (1) 
	{
		p = gets(buffer);
		if (p == NULL)
		{
           break;
		}	
		fprintf(fp1, "%s\n", buffer);
	}
	fclose(fp1);
}
//20191130 success