#include<stdio.h>

int main(void)
{
	char str1[6] = "seoul";
	char str2[3] = { 'i','s','\0' };
	char str3[] = "the capital city of korea.";

	char src[] = "the worst things to eat before you sleep";
	char dst[100];
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dst[i] = src[i];
	}
	dst[i] = '\0';
	
	i = 0;
	while(dst[i] != 0)//while(dst[i] != '\0') 가능.
	{
		i++;
	}
	printf("%s %s %s\n", str1, str2, str3);
	printf("%s", dst);
	printf("문자열\"%s\"의 길이는 %d입니다.", dst,i);
}
//20191104