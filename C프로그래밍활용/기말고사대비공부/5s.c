#include<stdio.h>
#include<string.h>

int main(void)
{
	char s[] = "language";
	char c = 'g';
	char* p = strchr(s, c);
	int loc;

	loc = (int)(p - s);

	if (p != NULL)
	{
		printf("%s���� ù��° %c�� %d���� �߰ߵ�.\n", s, c, loc);
	}
	else
	{
		printf("%c�� �߰ߵ��� �ʾ���.\n", c);
	}
}
//20191129