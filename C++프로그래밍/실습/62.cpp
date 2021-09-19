#include<iostream>
#include<fstream>
using namespace std;

int main(void)
{
	ofstream os;
	char c;
	os.open("text.txt");
	while (cin.get(c))
	{
		os.put(c);
	}
	os.close();
}
//20200121