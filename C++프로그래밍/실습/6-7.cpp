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
	cout << "2019305059 ������" << endl << endl;

	cout << "1���� 100���� ������ ���� 10���� ����մϴ�" << endl;
	for (int i = 0; i < 10; i++) { cout << random::nextint(1, 100) << ' '; }
	cout << endl;

	cout << "���ĺ��� �����ϰ� 10���� ����մϴ�" << endl;
	for (int i = 0; i < 10; i++) { cout << random::nextalphabet() << ' '; }
	cout << endl;

	cout << "������ �Ǽ��� 10���� ����մϴ�";
	for (int i = 0; i < 10; i++)
	{
		if (i % 5 == 0) cout << endl;
		cout << random::nextdouble() << ' ';
	}
	cout << endl;
}