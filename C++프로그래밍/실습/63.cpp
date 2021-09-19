#include<iostream>
#include<fstream>
using namespace std;

int main(void)
{
	int buffer[] = { 10,20,30 };
	ofstream os;
	os.open("test.dat", ofstream::binary);
	if (os.fail())
	{
		cout << "fail" << endl;
		exit(1);
	}
	os.write((char*) &buffer, sizeof(buffer)); //구조체도 저장가능!!
	os.close();
}
//20200121