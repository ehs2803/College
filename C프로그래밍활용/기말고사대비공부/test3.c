#include<stdio.h>

int main(void)
{
	FILE* fp;
	char buffer[100];

	fp = fopen("testfile.txt", "r");

	while (fgets(buffer, 100, fp)!=NULL)//while (fgets(buffer, 100, fp)) °¡´É
	{
		printf("%s", buffer);
	}
}
//20191207