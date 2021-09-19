#include<iostream>
#include<string>
using namespace std;

int main(void) {
	string name;
	cout << "이름은?";
	getline(cin, name);

	string address;
	cout << "주소는?";
	getline(cin, address);

	int age;
	cout << "나이는?";
	cin >> age;

	cout << name << ", " << address << ", " << age << "세" << endl;
}