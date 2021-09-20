#include<stdio.h>

typedef struct employee {
	int num;
	char name[10];
	char phone[20];
	int age;
}emp;

int main(void)
{
	emp a[10];
	int i;

	a[0].num = 1;
	strcpy(a[0].name, "a");
	strcpy(a[0].phone, "010-45");
	a[0].age = 15;

	a[1].num = 2;
	strcpy(a[1].name, "b");
	strcpy(a[1].phone, "00-45");
	a[1].age = 18;

	a[2].num = 3;
	strcpy(a[2].name, "c");
	strcpy(a[2].phone, "010-5");
	a[2].age = 20;

	a[3].num = 4;
	strcpy(a[3].name, "d");
	strcpy(a[3].phone, "010-4365");
	a[3].age = 22;

	a[4].num = 5;
	strcpy(a[4].name, "e");
	strcpy(a[4].phone, "010-4355");
	a[4].age = 30;

	a[5].num = 6;
	strcpy(a[5].name, "f");
	strcpy(a[5].phone, "010-4285");
	a[5].age = 40;

	a[6].num = 7;
	strcpy(a[6].name, "g");
	strcpy(a[6].phone, "010-45567");
	a[6].age = 50;

	a[7].num = 8;
	strcpy(a[7].name, "h");
	strcpy(a[7].phone, "010-4533");
	a[7].age = 40;

	a[8].num = 9;
	strcpy(a[8].name, "i");
	strcpy(a[8].phone, "010-4524");
	a[8].age = 25;

	a[9].num = 10;
	strcpy(a[9].name, "j");
	strcpy(a[9].phone, "010-45642");
	a[9].age = 27;

	for (i = 0; i < 10; i++)
	{
		if (20 <= a[i].age && a[i].age <= 30)
		{
			printf("사번:%d 이름:%s 전화번호:%s 나이:%d\n", a[i].num,a[i].name,a[i].phone,a[i].age);	
		}
	}
}
//20191121