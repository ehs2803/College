#include<iostream>
using namespace std;

class Account {
	string name;
	int id;
	int balance;
public:
	Account(string na, int n, int money);
	string getOwner();
	void deposit(int n);
	int withdraw(int n);
	int inquiry();
};

Account::Account(string na, int n, int money) :name(na), id(n), balance(money){}

string Account::getOwner() {
	return name;
}
void Account::deposit(int n) {
	balance += n;
}

int Account::withdraw(int n) {
	balance -= n;
	return balance;
}

int Account::inquiry() {
	return balance;
}

int main(void) {
	cout << "2019305059 이현수" << endl<<endl;
	Account a("kitae", 1, 5000);
	a.deposit(50000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
}