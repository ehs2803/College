#include<stdio.h>
#include<stdlib.h>

struct account {
	int number;
	char name[20];
	int balance;
};

int main(void)
{
	struct account s1;

	s1.number = 1;
	strcpy(s1.name, "�ٶ��� �Բ� �������");
	s1.balance = 100000;
	printf("{ %d, %s, %d }", s1.number, s1.name, s1.balance);
}