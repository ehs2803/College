#include<stdio.h>

struct stuent {
	
	struct { int num;  int a; }name1;
	struct { int b;  int c; }name2;
	union {
		char ch;
		int ina;
		struct { int cin; char cha; }name4;
	}name3;

};

struct stuent list[2];
int main(void)
{
	strcpy(list[0].name3.ch,'a');
	list[0].name1.num = 12;
	list[0].name3.name4.cin = 50;
	printf("%c %d", list[0].name3.ch, list[0].name1.num);
}
//20191124