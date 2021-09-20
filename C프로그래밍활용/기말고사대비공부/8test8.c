#include<stdio.h>

int main(void)
{
	int i;
    char c;
	char numinput[10];
	char cinut[10];
	char in[20];
	

	/*printf("숫자입력\n");
	scanf_s("%d", &i);
	printf("문자입력\n");
	scanf_s("%c", &c);*/

	printf("숫자입력\n");
	i=atoi(gets(numinput));


    printf("문자입력\n");
	gets(cinut);

	printf("문자열입력\n");
	gets(in, 20);


	printf("%d\n", i);
	printf("%s\n", in);
	printf("%s", cinut);
	
}
//20191123