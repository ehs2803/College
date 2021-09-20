/*
#include <stdio.h>
#include <stdlib.h>
int check()
{
	static int call_count = 0;
	call_count++;
	if( call_count >3 ){
		printf("로그인 시도횟수 초과\n ");
		return 0;
	}
	printf("비밀번호: ");
	int n;
	scanf("%d", &n);
	if( n == 1234 ){
		printf("로그인 성공!!\n ");
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