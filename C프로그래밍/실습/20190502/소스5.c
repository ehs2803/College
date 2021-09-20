#include<stdio.h>

int main(void)
{

	int a;
	int i;

	for (;;)
	{

		printf("몇단?");
		scanf("%d", &a);
		if (a == 0)            //if문은 break 열외
		{
			break;
		}
		else
		{
		    for (i = 1; i < 10; i++)
		    {
			printf("%d*%d=%d\n", a, i, a*i);

		    }

		}
		
	}
}