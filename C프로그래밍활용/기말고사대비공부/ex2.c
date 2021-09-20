#include<stdio.h>
#include<string.h>

struct movie {
	char* title;
	int attendance;
	char director[20];
};

int main(void)
{
	struct movie s[3];
	s[0].title = "dasd";
	s[0].attendance = 17613000;
	strcpy(s[0].director, "kimhanmin");

	s[1].title = "market";
	s[1].attendance = 14257000;
	strcpy(s[1].director, "yunjaegun");

	s[2].title = "batarang";
	s[2].attendance = 13383000;
	strcpy(s[2].director, "leesunghan");

	printf("      title          director          number\n");
	printf("==================================================\n");
	printf(" [       %s]     %s         %d\n", s[0].title, s[0].director, s[0].attendance);
	printf(" [     %s]     %s         %d\n", s[1].title, s[1].director, s[1].attendance);
	printf(" [   %s]     %s        %d\n", s[2].title, s[2].director, s[2].attendance);
}
//20191113