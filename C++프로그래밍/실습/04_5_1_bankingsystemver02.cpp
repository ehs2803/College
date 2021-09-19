#include<iostream>
#include<cstring>

using namespace std;
void showmenu();
void makeaccount();
void depositmoney();
void withdraw();
void show();

class Account
{
private:
	int accid;
	int balance;
	char* cusname;
public:
	Account(int id, int money, char* name)
		:accid(id), balance(money)
	{
		cusname = new char[strlen(name) + 1];
		strcpy(cusname, name);
	}
	int getaccid()
	{
		return accid;
	}
	void deposit(int money)
	{
		balance += money;
	}
	int withdraw(int money)
	{
		if (balance < money)
		{
			return 0;
		}
		balance -= money;
		return money;
	}
	void show()
	{
		cout << "account id: " << accid << endl;
		cout << "name: " << cusname << endl;
		cout << "balance: " << balance << endl;
	}
	~Account()
	{
		delete []cusname; 
	}
};

Account* accarr[100];
int accnum = 0;

int main(void)
{
	int choice;

	while (1)
	{
		showmenu();
		cout << "select ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			makeaccount();
			break;
		case 2:
			depositmoney();
			break;
		case 3:
			withdraw();
			break;
		case 4:
			show();
			break;
		case 5:
			for (int i = 0; i < accnum; i++)
			{
				delete accarr[i];
			}
			return 0;
		default:
			cout << "illegal selection.." << endl;
		}
	}
}

void showmenu()
{
	cout << "-----Menu------" << endl;
	cout << "1. account make" << endl;
	cout << "2. deposit" << endl;
	cout << "3. withdraw" << endl;
	cout << "4. account info" << endl;
	cout << "5. exit" << endl;
}

void makeaccount()
{
	int id;
	char name[20];
	int balance;

	cout << "[account make]" << endl;
	cout << "account id: "; cin >> id;
	cout << "name: "; cin >> name;
	cout << "depoit money: "; cin >> balance;

	accarr[accnum++] = new Account(id, balance, name);
}

void depositmoney()
{
	int money;
	int id;
	cout << "[deposit]" << endl;
	cout << "account id: "; cin >> id;
	cout << "depoit money: "; cin >> money;

	for (int i = 0; i < accnum; i++)
	{
		if (accarr[i]->getaccid() == id)
		{
			accarr[i]->deposit(money);
			cout << "deposit success" << endl << endl;
			return;
		}
	}
	cout << "not found id" << endl << endl;
}

void withdraw()
{
	int money;
	int id;
	cout << "[withdraw]" << endl;
	cout << "account id: "; cin >> id;
	cout << "withdraw money: "; cin >> money;

	for (int i = 0; i < accnum; i++)
	{
		if (accarr[i]->getaccid() == id)
		{
			if (accarr[i]->withdraw(money) == 0)
			{
				cout << "money lack" << endl << endl;
				return;
			}
			cout << "witdraw success" << endl<< endl;
			return;
		}
	}
	cout << "not found id" << endl << endl;
}

void show()
{
	for (int i = 0; i < accnum; i++)
	{
		accarr[i]->show();
		cout << endl;
	}
}
//20200102