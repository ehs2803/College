#include<iostream>
#include<string>
using namespace std;

int main(void) {
	string name;
	cout << "�̸���?";
	getline(cin, name);

	string address;
	cout << "�ּҴ�?";
	getline(cin, address);

	int age;
	cout << "���̴�?";
	cin >> age;

	cout << name << ", " << address << ", " << age << "��" << endl;
}