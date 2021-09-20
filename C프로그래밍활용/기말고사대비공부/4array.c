#include<stdio.h>

struct student {
	int number;
	char name[10];
	double grade;
};

int main(void)
{
	struct student list[3];
	int i;

	list[0].number = 2019101010;
	strcpy(list[0].name, "홍길동");
	list[0].grade = 4.3;

	printf("학번: %d\n", list[0].number);
	printf("이름: %s\n", list[0].name);
	printf("학점: %lf\n", list[0].grade);

}
//20191105