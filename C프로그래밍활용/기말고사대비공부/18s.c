#include <stdio.h> 
#include <string.h> 
#define _CRT_SECURE_NO_WARNING

int main(void)               
{
	char arr[20];                 
	char* a = arr;                  
	int n, len;                 

	printf("���ڿ��� �Է����ּ���.");                  
	scanf("%s", arr);                  

	len = strlen(arr);                       
	a = a + (len - 1);

	for (n = 0; n < len; n++)                         
	{
		printf("%c", *a);                        
		a--;
	}
}
//20191129