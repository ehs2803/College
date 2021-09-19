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
		cout << "����: ";
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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void makeaccout(void)
{
	int id;
	char name[name_len];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
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
	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < num; i++)
	{
		if (a[i].accid == id)
		{
			a[i].balance += money;
			cout << "�ԱݿϷ�" << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void withdrawmoney()
{
	int id;
	int moeny;
	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> moeny;

	for (int i = 0; i < num; i++)
	{
		if (a[i].accid == id)
		{
			if(a[i].balance<moeny)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}
			a[i].balance -= moeny;
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void show()
{
	for (int i = 0; i < num; i++)
	{
		cout << "����ID: " << a[i].accid << endl;
		cout << "�� ��: " << a[i].cusname << endl;
		cout << "�� ��: " << a[i].balance << endl << endl;
	}
}
//20191224