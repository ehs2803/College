/*
#include <stdio.h>
#include <stdlib.h>
int check()
{
	static int call_count = 0;
	call_count++;
	if( call_count >3 ){
		printf("�α��� �õ�Ƚ�� �ʰ�\n ");
		return 0;
	}
	printf("��й�ȣ: ");
	int n;
	scanf("%d", &n);
	if( n == 1234 ){
		printf("�α��� ����!!\n ");
		return 1;
	}
	return 0;
}
int main(void)
{
	check();
	check();
	check();
	check();
	return 0;
}
*/