#include<iostream>
#include<iomanip>
#include<cctype>
using namespace std;

char Asscil(int n)
{
	if (isprint(n)) return n;
	else return '.';
}

int main(void)
{
	cout << "2019305059 이현수" << endl << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << setw(6) << left<<setfill(' ') << "dec";
		cout << setw(7) << "hexa";
		cout << setw(7) << "char";
	}
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << setw(6) << "___";
		cout << setw(7) << "____";
		cout << setw(7) << "____";
	}
	cout << endl;
	for (int i = 0; i < 16; i++)
	{
		cout << setw(6)<<dec << i * 4;
		cout << setw(7) << hex << i * 4;
		cout << setw(7) << dec << Asscil(i * 4);

		cout << setw(6) << dec << 1 + (i * 4);
		cout << setw(7) << hex << 1 + (i * 4);
		cout << setw(7) << Asscil(1 + (i * 4));

		cout << setw(6) << dec << 2 + (i * 4);
		cout << setw(7) << hex << 2 + (i * 4);
		cout << setw(7) << Asscil(2 + (i * 4));

		cout << setw(6) << dec << 3 + (i * 4);
		cout << setw(7) << hex << 3 + (i * 4);
		cout << setw(7) << Asscil(3 + (i * 4)) << endl;
	}
	cout << endl;
	cout << setw(35) << setfill('-') << '-';
	cout << "이하 생략";
	cout << setw(34) << setfill('-') << '-' << endl;
}