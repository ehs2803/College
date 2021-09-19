#include<iostream>
#include<string>
using namespace std;

int main() {
	cout << "2019305059 이현수" << endl << endl;
	string s;
	cout << "7+23+5+100+25와 같이 덧셈 문자열을 입력하세요." << endl;
	getline(cin, s, '\n'); 
	int result = 0;
	int startIndex = 0; 
	int sw = 0;//sw가 1이면 더하기, 0이면 빼기
	//처음 숫자의 부호결정
	if (s[0] == '-') {
		sw = 0;
		startIndex = 1;
	}
	else {
		sw = 1;
	}
	while (true) {
		int PfIndex = s.find('+', startIndex);//'+'부호 찾기
		int MfIndex = s.find('-', startIndex);//'-'부호 찾기

		if (PfIndex == -1 && MfIndex==-1) { // '+', '-' 문자 발견할 수 없음
			string part = s.substr(startIndex);
			if (part == "") break;
			if (sw == 1) {
				cout << "+" << part << endl;
				result += stoi(part);
			}
			else {//sw=0 일때
				cout << "-" << part << endl;
				result -= stoi(part);
			}
			break;
		}

		if (PfIndex < MfIndex && PfIndex != -1) {//'+'가 '-'보다 먼저있고 '+','-'모두존재
			int count = PfIndex - startIndex;
			string part = s.substr(startIndex, count);
			if (sw == 1) {
				cout << "+" << part << endl;
				result += stoi(part);
			}
			else {//sw=0 일때
				cout << "-" << part << endl;
				result -= stoi(part);
			}
			startIndex = PfIndex + 1;
			if (s[PfIndex] == '+') sw = 1;
			else if (s[PfIndex] == '-') sw = 0;
		}
		else if (MfIndex < PfIndex && MfIndex != -1) {//'-'가 '+'보다 먼저있고 '+','-'모두존재
			int count = MfIndex - startIndex;
			string part = s.substr(startIndex, count);
			if (sw == 1) {
				cout << "+"<<part << endl;
				result += stoi(part);
			}
			else {//sw=0 일때
				cout <<"-"<< part << endl;
				result -= stoi(part);
			}
			startIndex = MfIndex + 1;
			if (s[MfIndex] == '+') sw = 1;
			else if (s[MfIndex] == '-') sw = 0;
		}
		else if (MfIndex == -1 && PfIndex != -1) {//'-'부호는 없고 '+'부호만 있을때
			int count = PfIndex - startIndex;
			string part = s.substr(startIndex, count);
			if (sw == 1) {
				cout << "+" << part << endl;
				result += stoi(part);
			}
			else {//sw=0 일때
				cout << "-" << part << endl;
				result -= stoi(part);
			}
			startIndex = PfIndex + 1;
			sw = 1;
		}
		else if (PfIndex == -1 && MfIndex != -1) {//'+'부호는 없고 '-'부호만 있을때
			int count = MfIndex - startIndex;
			string part = s.substr(startIndex, count);
			if (sw == 1) {
				cout << "+" << part << endl;
				result += stoi(part);
			}
			else {//sw=0 일때
				cout << "-" << part << endl;
				result -= stoi(part);
			}
			startIndex = MfIndex + 1;
			sw = 0;
		}
	}
	cout << "숫자들의 결과값 " << result;
}










/*
int main(void) {
	cout << "2019305059 이현수" << endl << endl;
	string s;
	cout << "7+23+5+100+25와 같이 문자열을 입력하세요." << endl;
	getline(cin, s, '\n');
	int sum = 0;
	int startIndex = 0;
	while (true) {
		int PfIndex = s.find('+', startIndex);
		int MfIndex = s.find('-', startIndex);
		if (PfIndex == -1 && MfIndex == -1) {
			string part = s.substr(startIndex);
			if (part == "")break;
			cout << part << endl;
			sum += stoi(part);
			break;
		}

	
		if (PfIndex < MfIndex || MfIndex==-1) {
			int count = PfIndex - startIndex;
			string part = s.substr(startIndex, count);

			cout << part << endl;
			sum += stoi(part);
			startIndex = PfIndex + 1;
		}
		else if(MfIndex < PfIndex || PfIndex == -1){
			int count = MfIndex - startIndex;
			string part = s.substr(startIndex, count);

			cout << part << endl;
			sum -= stoi(part);
			startIndex = PfIndex + 1;
		}
	}
	cout << "계산식 결과 = " << sum << endl;
}*/
/*
int main(void) {
	cout << "2019305059 이현수" << endl << endl;
	string s;
	int len = s.length();

	int m;
	int sum = 0;
	int count;
	string part;

	if (s[0] == '+') {
		for (int i = 0;i < len;i++) {
			if (s[i] == '+' || s[i]=='-') {
				part = s.substr(1, i - 1);		m = i;
			}
		}
		cout << "+" << part << endl;
		sum += stoi(part);

	}
	else if (s[0] == '-') {
		for (int i = 0;i < len;i++) {
			if (s[i] == '+' || s[i] == '-') {
				part = s.substr(1, i - 1);		m = i;
			}
		}
		cout << "-" << part << endl;
		sum -= stoi(part);

	}
	else {
		for (int i = 0;i < len;i++) {
			if (s[i] == '+' || s[i] == '-') {
				part = s.substr(0, i - 1);		m = i;
			}
		}
		cout << "+" << part << endl;
		sum += stoi(part);
	}
	int startIndex =m+1;

	for (int i = m; i < len;i++) {
		if (s[i] == '+') {
			for (int j = i + 1;j < len;j++) {
				if (s[j] == '+' || s[j] == '-') {
					count = j - i;
					part = s.substr(startIndex, count);
					cout << "+" << part << endl;
					sum += stoi(part);
					startIndex = j + 1;
				}
			}
		}
		else if (s[i] == '-') {
			for (int j = i + 1;j < len;j++) {
				if (s[j] == '+' || s[j] == '-') {
					count = j - i;
					part = s.substr(startIndex, count);
					cout << "-" << part << endl;
					sum -= stoi(part);
					startIndex = j + 1;
				}
			}
		}
	}
	
	cout << "숫자들의 결과는 " << sum;
}
*/