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
	printf("����2����Ʈ: %d%d\n", ab.a,ab.b);

	ab.a = (to.ibuf >> 8) & 0xFF;
	ab.b = (to.ibuf& 0xFF);
	printf("����2����Ʈ: %d%d\n", ab.a, ab.b);


	ab.a = (to.ibuf >> 24) & 0xFF;
	printf("����1����Ʈ�ƽ�Ű�ڵ�: %c\n", ab.a);

	ab.b = (to.ibuf & 0xFF);
	printf("����1����Ʈ�ƽ�Ű�ڵ�: %c\n",ab.b);
}
//20191124

/*
input: 123456789
����Ʈ���� ��� (10����)
�ֻ�������Ʈ   : 7
2��°��������Ʈ: 91
3��°��������Ʈ: 205
����������Ʈ   : 21
*/
