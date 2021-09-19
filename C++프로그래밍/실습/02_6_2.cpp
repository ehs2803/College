#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		printf("random number #%d: %d\n", i, rand() % 100);
	}
}
//20191228