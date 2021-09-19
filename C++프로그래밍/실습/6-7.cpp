#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class random
{
public:
	static void seed() { srand((unsigned)time(0)); }
	static int nextint(int min = 0, int max = 32767);
	static char nextalphabet();
	static double nextdouble();
};
int random::nextint(int min, int max)
{
	int n = rand() % (max - min) + min;
	return n;
}/*
char random::nextalphabet()
{
	char c;
	c = rand() % 26 + 65; //26+97;
	return c;
}*/
char random::nextalphabet()
{
	int n = rand();
	char a;
	if (n % 2 == 0)
	{
		a = rand() % 26 + 'a';
	}
	else

		a = rand() % 26 + 'A';
	return a;
}
double random::nextdouble()
{
	double a;
	a = (double)rand() / 32767;
	return a;
}
int main(void){
	cout << "2019305059 이현수" << endl << endl;

	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) { cout << random::nextint(1, 100) << ' '; }
	cout << endl;

	cout << "알파벳을 랜덤하게 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) { cout << random::nextalphabet() << ' '; }
	cout << endl;

	cout << "랜덤한 실수를 10개를 출력합니다";
	for (int i = 0; i < 10; i++)
	{
		if (i % 5 == 0) cout << endl;
		cout << random::nextdouble() << ' ';
	}
	cout << endl;
}