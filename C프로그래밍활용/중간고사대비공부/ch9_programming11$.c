/*
#include <stdio.h>

int recursive(int n, int k)
{
	if (n == 1 || n == k) return 1;
	else return recursive(n - 1, k - 1) + recursive(n - 1, k);
}

int main(void)
{
	printf("n=");
	int n;
	scanf("%d", &n);
	printf("k=");
	int k;
	scanf("%d", &k);
	printf("%d\n", recursive(n, k));
	return 0;
}
*/