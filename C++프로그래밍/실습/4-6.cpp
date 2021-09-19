#include<iostream>
#include<string>
using namespace std;

int main(void) {
	cout << "2019305059 이현수" << endl << endl;
	string str;
	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl;
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