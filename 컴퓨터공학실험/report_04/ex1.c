#include<stdio.h>

struct sho {
	unsigned short a;
	unsigned short b;
};

union in {
	int ibuf;
	struct sho mem;
};

union in in1, in2;
int main(void)
{
	printf("input number: ");
	scanf_s("%d", &in1.ibuf);

	in2.mem.a = in1.ibuf & 0xFFFF;
	in2.mem.b = (in1.ibuf>>16) & 0xFFFF;
	printf("high 2byte: %d\n", in2.mem.a);
    printf("low 2byte: %d\n", in2.mem.b);

	in2.mem.a = in1.ibuf & 0xFF;
	in2.mem.b = (in1.ibuf >> 24) & 0xFF;
	printf("high 1byte ascii: %c\n", in2.mem.a);
	printf("low 1byte ascii: %c\n", in2.mem.b);
}
//20191126

