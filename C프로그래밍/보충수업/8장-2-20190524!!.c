#include<stdio.h>
void check_alpha();

int main(void)
{
	char ch;

	printf("문자를 입력하시오: ");
	ch = getchar();

	void check_alpha(ch);

}

void check_alpha(char i)
{
	if (i == 'a'|| i == 'b' || i == 'c' || i == 'd' || i == 'e' || i == 'f' || i == 'g' || i == 'h' || i == 'i' || i == 'j' || i == 'k' || 
		i == 'l' || i == 'm' || i == 'n' || i == 'o' || i == 'p' || i == 'q' || i == 'r' || i == 's' || i == 't' || i == 'u' || i == 'v' || 
		i == 'w' || i == 'x' || i == 'y' ||i=='z' )
	{
       printf("%c는 알파벳 문자입니다. ", i);
	}
}