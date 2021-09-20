#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<conio.h>

int main(void)
{
	char* p = "Hello world";
    int ch;

	printf("%s\n", p);

	p = "Welcome to C world";
	printf("%s\n", p);

	p = "Goodbye";
	printf("%s\n", p);

	
	while ((ch = _getch()) != 'q')//q가 입력되면 엔터역활,엔터시 오류
	{
		_putch(ch);
	}


}
//20191129