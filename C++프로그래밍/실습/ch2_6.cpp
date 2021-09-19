#include<iostream>
#include<string>
using namespace std;

int main(void) {
	string password;
	string password1;

	cout << "새 암호를 입력하세요>>";
	cin >> password;
	
	cout << "새 암호를 다시 한 번 입력하세요>>";
	cin >> password1;
	if (password == password1) {
		cout << "같습니다" << endl;
	}
	else {
		cout << "같지 않습니다" << endl;
	}
}