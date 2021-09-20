#include<stdio.h>

int apha_num(char* a, int size);
int sto_num(char* a, int size);
void big_alpha(char* a, char b[], int size);
void small_alpha(char* a, char b[], int size);
int num_num(char* a, int size);
void cba_str(char* a, int size);
int strnum_plus(char* a, int size);
void noblock(char* a, int size);
void count(char* a, char* b, int size);
void str_first(char* a, char* b, int size);
int count_gudo(char* a, int size);

int main(void)
{
	int len;
	char instr[30];
	char instr2[30];
	printf("문자열을 입력하시오: ");
	gets(instr);
	len = strlen(instr);
	//1알파벳개수, 2단어개수, 3모두 대문자로, 4모두 소문자로, 5숫자개수, 6문자열을 반대로
	printf("알파벳의 개수: %d\n", apha_num(instr, len));
	printf("단어의 개수: %d\n", sto_num(instr, len));
	big_alpha(instr, instr2, len);// printf("모두 대문자로 ");
	small_alpha(instr, instr2, len);// printf("모두 소문자로 ");
	printf("숫자개수: %d\n", num_num(instr, len));
	cba_str(instr, len);// printf("문자열을 반대로 ");
	printf("문자열 내 숫자의 합: %d\n", strnum_plus(instr,len));
	noblock(instr,len);
	count(instr, instr2, len);
	str_first(instr,instr2,len);
	printf("구두점 개수 : %d", count_gudo(instr,len));
}

int apha_num(char* a, int size)
{
	int i, count;
	count = 0;
	for (i = 0; i < size; i++)
	{
		if (('A' <= a[i]) && (a[i] <= 'z'))
		{
			count++;
		}
	}
	return count;
}

int sto_num(char* a, int size)
{
	char* token;
	int count = 1;
	token = strtok(a, " ");

	while (token != NULL)
	{
		token = strtok(NULL, " ");
		if (token != NULL)
		{
			count++;
		}
	}
	return count;
}

void big_alpha(char* a, char b[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		b[i] = a[i];
	}
	for (i = 0; i < size; i++)
	{
		if (('a' <= b[i]) && (b[i] <= 'z'))
		{
			b[i] = b[i] - 32;
		}
	}
	printf("모두 대문자로 ");
	for (i = 0; i < size; i++)
	{
		printf("%c", b[i]);
	}
	printf("\n");
}

void small_alpha(char* a, char b[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		b[i] = a[i];
	}
	for (i = 0; i < size; i++)
	{
		if (('A' <= b[i]) && (b[i] <= 'Z'))
		{
			b[i] = b[i] + 32;
		}
	}
	printf("모두 소문자로 ");
	for (i = 0; i < size; i++)
	{
		printf("%c", b[i]);
	}
	printf("\n");
}

int num_num(char* a, int size)
{
	int i;
	int count = 0;
	for (i = 0; i < size; i++)
	{
		if (('0' <= a[i]) && (a[i] <= '9'))
		{
			count++;
		}
	}
	return count;
}

void cba_str(char* a, int size)
{
	int i;
	printf("문자열을 반대로");
	for (i = size; i > -1; i--)
	{
		printf("%c", a[i]);
	}
	printf("\n");
}

int strnum_plus(char* a, int size)
{
	int i;
	int result = 0;
	for (i = 0; i < size; i++)
	{
		if (('0' <= a[i]) && (a[i] <= '9'))
		{
			result = (result + (a[i] - '0'));
		}
	}
	return result;
}

void noblock(char* a,  int size)//programming2
{
	int i,j;
	j = 0;
	char b[20];
	for (i = 0; i < size; i++)
	{
		if (a[i] != " ")
		{
			b[j] = a[i];
			j++;
		}
	}
	
	for (i = 0; i < size; i++)
	{
		printf("%c", b[i]);
	}
	printf("\n");
}

void count(char* a,char b[] ,int size)//programming4
{
	int i;
	int check;
	int count = 0;
	for (i = 0; i < size; i++)
	{
		b[i] = a[i];
	}
	for (i = 0; i < size; i++)
	{
		if (('A' <= b[i]) && (b[i] <= 'Z'))
		{
			b[i] = b[i] + 32;
		}
	}
	for (check = 'a'; check <= 'z'; check++)
	{
		count = 0;
		for (i = 0; i < size; i++)
		{
			if (b[i] == check)
			{
				count++;
			}
		}
		if (count > 0)
		{
			printf("%c : %d\n", check, count);
		}
	}
	printf("\n");
}

void str_first(char* a, char b[], int size)//programming9
{
	int i;
	for (i = 0; i < size; i++)
	{
		b[i] = a[i];
	}
	if (islower(b[0]))
	{
		b[0] = b[0] - 32;
		printf("맨 앞글자를 대문자로 ");
		for (i = 0; i < size; i++)
		{
			printf("%c", b[i]);
		}
		printf("\n");
	}
}

int count_gudo(char* a, int size)//programming13
{
	int i;
	int count = 0;
	for (i = 0; i < size; i++)
	{
		if (a[i] == '.')
		{
			count++;
		}
	}
	return count;
}
//20191115