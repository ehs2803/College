#include<iostream>
#include<string>
using namespace std;

int main(void) {
	cout << "2019305059 ������" << endl << endl;
	string str;
	cout << "�Ʒ��� �� ���� �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�)" << endl;
	while (true) {
		cout << ">>";
		getline(cin, str);
		if (str == "exit") break;
		int len = str.length();
		for (int i = len - 1;i > -1;i--) {
			cout << str[i];
		}
		cout << endl;
	}
}