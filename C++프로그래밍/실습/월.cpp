#include<iostream>
using namespace std;

void GetDays(int month[]);

int main(void) {
	cout << "2019305059 ������" << endl<<endl;
	int month[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	string an;

	do {
		GetDays(month);
		cout << "��� �˾ƺ��ðڽ��ϱ�?(yes �Է½� ���, �� �� ����)";
		cin >> an;
	} while (an == "yes");

	cout << "�����մϴ�." << endl;
}

void GetDays(int month[]) {
	int mon;
	cout << "�� ��??";
	cin >> mon;		
	cout << mon << "���� �ϼ��� " << month[mon-1] << endl << endl;
}