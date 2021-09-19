#include<iostream>
#include<string>
using namespace std;

void combine(string &t1, string &t2, string &t3);

int main(void) {
	cout << "2019305059 ÀÌÇö¼ö" << endl << endl;

	string text1("I love you"), text2("very much");
	string text3;
	combine(text1, text2, text3);
	cout << text3;
}

void combine(string &t1, string &t2, string &t3) {
	t3.append(t1);
	t3.append(" ");
	t3.append(t2);
}