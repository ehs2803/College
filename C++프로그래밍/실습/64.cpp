#include<iostream>
#include<fstream>
using namespace std;

const int SIZE=1000;
void init_table(int table[], int size);

int main(void)
{
	int table[SIZE];
	int data;
	long pos;

	init_table(table, SIZE);

	ofstream os;
	os.open("test.dat", ofstream::binary);
	if (os.fail())
	{
		cout << "test.dat file not open" << endl;
		exit(1);
	}

	os.write((char*)&table, sizeof(table));
	os.close();

	ifstream is;
	is.open("test.dat", ofstream::binary);
	if (is.fail())
	{
		cout << "test.dat file not open" << endl;
		exit(1);
	}
	
	while (1)
	{
		cout << "input file location(0~999, exit:-1): ";
		cin >> pos;
		if (pos == -1) break;
		is.seekg(pos * sizeof(int), ios::beg);
		is.read((char*)&data, sizeof(int));
		cout << pos << "location value" << data << "!!" << endl;
	}
	is.close();
}

void init_table(int table[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		table[i] = i * i;
	}
}
//20200121