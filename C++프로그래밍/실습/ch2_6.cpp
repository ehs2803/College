#include<iostream>
#include<string>
using namespace std;

int main(void) {
	string password;
	string password1;

	cout << "�� ��ȣ�� �Է��ϼ���>>";
	cin >> password;
	
	cout << "�� ��ȣ�� �ٽ� �� �� �Է��ϼ���>>";
	cin >> password1;
	if (password == password1) {
		cout << "�����ϴ�" << endl;
	}
	else {
		cout << "���� �ʽ��ϴ�" << endl;
	}
}