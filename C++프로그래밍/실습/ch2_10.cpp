#include<iostream>
#include<cstring>
using namespace std;

int main(void) {
	char str[20];
	cout << "���ڿ� �Է�>>";
	cin >> str;

	int n = strlen(str);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j<=i; j++) {
			cout << str[j];
		}
		cout << endl;
	}
}