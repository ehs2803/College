#include <stdio.h>

int main(void)
{
	int a;
	printf("input: ");
	scanf_s("%d", &a);
	unsigned char cha = (a >> 24) & 0xFF;
	unsigned char chb = (a >> 16) & 0xFF;
	unsigned char chc = (a >> 8) & 0xFF;
	unsigned char chd = (a & 0xFF);
	printf("����Ʈ���� ��� (10����)\n");
	printf("�ֻ�������Ʈ   : %d\n", cha);
	printf("2��°��������Ʈ: %d\n", chb);
	printf("3��°��������Ʈ: %d\n", chc);
	printf("����������Ʈ   : %d\n", chd);
}
/*
input: 123456789
����Ʈ���� ��� (10����)
�ֻ�������Ʈ   : 7
2��°��������Ʈ: 91
3��°��������Ʈ: 205
����������Ʈ   : 21
*/
//20191124 am12:23 end