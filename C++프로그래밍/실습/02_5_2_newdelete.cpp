#include<iostream>
#include<string.h>
using namespace std;

char* makestr(int len)
{
	char* str = new char[len];
	return str;
}

int main(void)
{
	char* str = makestr(20);
	strcpy(str, "I am so happy~");
	cout << str << endl;
	delete[]str;
}
//20191228