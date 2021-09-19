#include<iostream>
using namespace std;

void GetDays(int month[]);

int main(void) {
	cout << "2019305059 이현수" << endl<<endl;
	int month[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	string an;

	do {
		GetDays(month);
		cout << "계속 알아보시겠습니까?(yes 입력시 계속, 그 외 종료)";
		cin >> an;
	} while (an == "yes");

	cout << "종료합니다." << endl;
}

void GetDays(int month[]) {
	int mon;
	cout << "몇 월??";
	cin >> mon;		
	cout << mon << "월의 일수는 " << month[mon-1] << endl << endl;
}