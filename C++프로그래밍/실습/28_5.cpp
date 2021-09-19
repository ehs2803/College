#include<iostream>
using namespace std;

bool IsMultiple(int, int );

int main(void) {
	cout << "2019305059 이현수" << endl<<endl;
	int num1, num2;
	cout << "두 정수 입력>>";
	cin >> num1 >> num2;

	bool judge = IsMultiple(num1, num2);
	if (judge == true) {
		cout << num2 << "은 " << num1 << "의 배수입니다." << endl;
	}
	else {
		cout << num2 << "은 " << num1 << "의 배수가 아닙니다." << endl;
	}
}

bool IsMultiple(int n1, int n2) {
	if (n2 % n1 == 0)return true;
	else return false;
}