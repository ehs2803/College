#include<stdio.h>

struct mem {

	unsigned short a;
	unsigned short b;
};

union abc {
	
	int ibuf;
	
};

int main(void)
{
	union abc to;
    struct mem ab;
    printf("input number: ");
	scanf_s("%d", &to.ibuf);

	ab.a=(to.ibuf >> 24) & 0xFF;
	ab.b = (to.ibuf >> 16) & 0xFF;
	printf("상위2바이트: %d%d\n", ab.a,ab.b);

	ab.a = (to.ibuf >> 8) & 0xFF;
	ab.b = (to.ibuf& 0xFF);
	printf("하위2바이트: %d%d\n", ab.a, ab.b);


	ab.a = (to.ibuf >> 24) & 0xFF;
	printf("상위1바이트아스키코드: %c\n", ab.a);

	ab.b = (to.ibuf & 0xFF);
	printf("하위1바이트아스키코드: %c\n",ab.b);
}
//20191124

/*
input: 123456789
바이트별로 출력 (10진수)
최상위바이트   : 7
2번째상위바이트: 91
3번째상위바이트: 205
최하위바이트   : 21
*/
