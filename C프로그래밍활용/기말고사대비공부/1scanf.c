#include<stdio.h>

int main(void)
{
	char s[20];

	printf("���ڿ��� �Է��Ͻÿ�: ");
	scanf_s("%[abc]s", s, 20);

	printf("%s", s);

}
//20191128