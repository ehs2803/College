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
	os.write((char*) &buffer, sizeof(buffer)); //����ü�� ���尡��!!
	os.close();
}
//20200121