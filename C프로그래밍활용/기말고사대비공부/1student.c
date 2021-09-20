#include<stdio.h>

struct student {
	int number;
	char name[10];
	double grade;
};

int main(void)
{
	struct student s;

	s.number = 2019101010;
	strcpy(s.name, "홍길동");
	s.grade = 4.3;

	printf("학번: %d\n", s.number);
	printf("이름: %s\n", s.name);
	printf("학점: %f", s.grade);
}
//20191105