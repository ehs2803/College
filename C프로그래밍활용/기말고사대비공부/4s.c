#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<ctype.h>

int count_word(char* s);

int main(void)
{
	char ins[100];
	printf("���ڿ��� �Է��Ͻÿ� : ");
	gets(ins);//gets_s(ins,100); ok
	
	int wc = count_word(ins);
	printf("�ܾ��� ���� : %d\n", wc);
}

int count_word(char* s)
{
	int i, wc = 0;
	int waiting = 1;

	for (i = 0; s[i] != NULL; i++)
	{
		if (isalpha(s[i]))
		{
			if (waiting)
			{
				wc++;
				waiting = 0;
			}
		}
		else
		{
			waiting = 1;
		}
	}
	return wc;
}
//20191129