#include<iostream>
using namespace std;

namespace AAA
{
	namespace BBB
	{
		namespace CCC
		{
			int num1;
			int num2;
		}
	}
}

int main(void)
{
	AAA::BBB::CCC::num1 = 20;
	AAA::BBB::CCC::num2 = 30;

	namespace ABC = AAA::BBB::CCC;
	cout << ABC::num1 << endl;
	cout << ABC::num2 << endl;
}
/*
int a=100;         //전역변수

int simple(void)
{
   int a=20;       //지역변수
   a+=3;           //지역변수 a의값이 3 증가
   ::a+=7;         //전역변수 a의값이 7 증가
}
*/
//20191224