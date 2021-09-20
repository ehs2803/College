#include<stdio.h>

int apha_num(char* a, int size);
int sto_num(char* a, int size);
void big_alpha(char* a, char b[], int size);
void small_alpha(char* a, char b[], int size);
int num_num(char* a, int size);
void cba_str(char* a, int size);

int main(void)
{
	int len;
	char instr[30];
	char instr2[30];
	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets(instr);
	len = strlen(instr);
	//1���ĺ�����, 2�ܾ��, 3��� �빮�ڷ�, 4��� �ҹ��ڷ�, 5���ڰ���, 6���ڿ��� �ݴ��
	printf("���ĺ��� ����: %d\n",apha_num(instr,len));             
	printf("�ܾ��� ����: %d\n",sto_num(instr,len));            
	big_alpha(instr,instr2,len);// printf("��� �빮�ڷ� ");
	small_alpha(instr,instr2,len);// printf("��� �ҹ��ڷ� ");
	printf("���ڰ���: %d\n",num_num(instr,len));
	cba_str(instr,len);// printf("���ڿ��� �ݴ�� ");	
}

int apha_num(char* a,int size)
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

void big_alpha(char* a,char b[], int size)
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
	printf("��� �빮�ڷ� ");
	for (i = 0; i < size; i++)
	{
		printf("%c", b[i]);
	}
	printf("\n");
}

void small_alpha(char* a,char b[], int size)
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
	printf("��� �ҹ��ڷ� ");
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
	printf("���ڿ��� �ݴ��");
	for (i = size; i > -1;i--)
	{
		printf("%c", a[i]);
	}
}
//20191115