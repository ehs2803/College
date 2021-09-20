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
	printf("바이트별로 출력 (10진수)\n");
	printf("최상위바이트   : %d\n", cha);
	printf("2번째상위바이트: %d\n", chb);
	printf("3번째상위바이트: %d\n", chc);
	printf("최하위바이트   : %d\n", chd);
}
/*
input: 123456789
바이트별로 출력 (10진수)
최상위바이트   : 7
2번째상위바이트: 91
3번째상위바이트: 205
최하위바이트   : 21
*/
//20191124 am12:23 end