#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int a, b, c;
	int d, e, f;
	int ball, strike;

	ball = 0;
	strike = 0;
	srand(time(NULL));
	d=  1 + rand() % 9;
	e = 1 + rand() % 9;
	f = 1 + rand() % 9;

	
	for (;;)
	{
		printf("������ �Է��Ͻÿ�.");
		scanf("%d %d %d", &a, &b, &c);

        if (a==d)
	    {
			strike = strike + 1;

	    }
	    if (a==e)
	    {
			ball = ball + 1;
	    }
	    if (a==f)
	    {
			ball = ball + 1;
	    }

		if (b == d)
		{
			ball = ball + 1;
		}
		if (b == e)
		{
			strike = strike + 1;
		}
		if (b == f)
		{
			ball = ball + 1;
		}
	
		if (c == d)
		{
			ball = ball + 1;
		}
		if (c == e)
		{
			ball = ball + 1;
		}
	    if (c == f)
		{
			strike = strike + 1;
		}

		printf("��: %d, ��Ʈ����ũ: %d\n", ball, strike);

		if (strike == 3)
		{
			break;
		}
    }

}
	