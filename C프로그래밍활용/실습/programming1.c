#include<stdio.h>
#include<stdlib.h>
struct book {
	int id;
	char title[100];
	char author[20];
};

int main(void)
{
	struct book s1;

	s1.id = 1;
	strcpy(s1.title, "�ٶ��� �Բ� �������");
	strcpy(s1.author, "������ ��ÿ");
	printf("{ %d, %s, %s }", s1.id, s1.title, s1.author);
}