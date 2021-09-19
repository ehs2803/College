#include<iostream>
#include<cstring>

using namespace std;
const int name_len = 20;

void menu(void);
void makeaccout(void);
void depositmoney();
void withdrawmoney();
void show();

enum {make=1, deposit, withdraw, inquire, exi};

typedef struct {
	int accid;
	int balance;
	char cusname[name_len];
}Account;

Account a[100];
int num = 0;

int main(void)
{
	int choice;

	while (1)
	{
		menu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case make:
			makeaccout();
			break;
		case deposit:
			depositmoney();
			break;
		case withdraw:
			withdrawmoney();
			break;
		case inquire:
			show();
			break;
		case exi:
			return 0;
		default:
			cout << "illegal selection.." << endl;
		}
	}
}

void menu(void)
{
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void makeaccout(void)
{
	int id;
	char name[name_len];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << endl;

	a[num].accid = id;
	a[num].balance = balance;
	strcpy_s(a[num].cusname, name);
	num++;
}

void depositmoney()
{
	int money;
	int id;
	cout << "[입 금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < num; i++)
	{
		if (a[i].accid == id)
		{
			a[i].balance += money;
			cout << "입금완료" << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void withdrawmoney()
{
	int id;
	int moeny;
	cout << "[출 금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> moeny;

	for (int i = 0; i < num; i++)
	{
		if (a[i].accid == id)
		{
			if(a[i].balance<moeny)
			{
				cout << "잔액부족" << endl << endl;
				return;
			}
			a[i].balance -= moeny;
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void show()
{
	for (int i = 0; i < num; i++)
	{
		cout << "계좌ID: " << a[i].accid << endl;
		cout << "이 름: " << a[i].cusname << endl;
		cout << "잔 액: " << a[i].balance << endl << endl;
	}
}
//20191224