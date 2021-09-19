#include<iostream>
#include<fstream>
using namespace std;

int main(void)
{
	ifstream a;
	a.open("score.txt");
	if (!a)
	{
		cerr << "file open fail" << endl;
		exit(1);
	}
	char c;
	a.get(c);
	while (! a.eof())
	{
		cout << c;
		a.get(c);
	}
	a.close();
}
//20200121 error