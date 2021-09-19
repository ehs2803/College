#include<iostream>
#include<string>
using namespace std;

class Phone {
	string name;
	string telnum;
	string address;
public:
	Phone(string name = "", string telnum = "", string address = "") {
		this->name = name;
		this->telnum = telnum;
		this->address = address;
	}
	friend ostream& operator << (ostream& outs, Phone c);
	friend istream& operator >> (istream& ins, Phone& c);
};

ostream& operator << (ostream& outs, Phone c) {
	outs << "(" << c.name << ","<<c.telnum<<","<<c.address<< ")";
	return outs;
}

istream& operator >> (istream& ins, Phone& c) {
	cout << "이름:";
	string name;
	getline(ins,name);
	c.name = name;
	cout << "전화번호:";
	string telnum;
	getline(ins, telnum);
	c.telnum = telnum;
	cout << "주소:";
	string address;
	getline(ins, address);
	c.address = address;
	return ins;
}

int main(void) {
	cout << "2019305059 이현수" << endl << endl;
	Phone girl, boy;
	cin >> girl >> boy;
	cout << girl << endl << boy << endl;
}