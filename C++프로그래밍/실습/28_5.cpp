#include<iostream>
using namespace std;

bool IsMultiple(int, int );

int main(void) {
	cout << "2019305059 ������" << endl<<endl;
	int num1, num2;
	cout << "�� ���� �Է�>>";
	cin >> num1 >> num2;

	bool judge = IsMultiple(num1, num2);
	if (judge == true) {
		cout << num2 << "�� " << num1 << "�� ����Դϴ�." << endl;
	}
	else {
		cout << num2 << "�� " << num1 << "�� ����� �ƴմϴ�." << endl;
	}
}

bool IsMultiple(int n1, int n2) {
	if (n2 % n1 == 0)return true;
	else return false;
}