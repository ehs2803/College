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
	strcpy(s1.title, "바람과 함께 사라지다");
	strcpy(s1.author, "마가렛 미첼");
	printf("{ %d, %s, %s }", s1.id, s1.title, s1.author);
}