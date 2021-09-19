#include <iostream>
#include<string>
using namespace std;

class Adder {
protected:
	int add(int a, int b) { return a + b; }
};

class Subtractor {
protected:
	int minus(int a, int b) { return a - b; }
};

class Multipul {
protected:
	int multi(int a, int b) { return a * b; }
};

class Divid {
protected:
	int divid(int a, int b) { return a / b; }
};

class Calculator : public Adder, public Subtractor, public Multipul, public Divid {
public:
	int calc(char op, int a, int b);
};

int Calculator::calc(char op, int a, int b) {
	int res = 0;
	switch (op) {
	case '+': res = add(a, b); break;
	case '-': res = minus(a, b); break;
	case '*': res = multi(a, b); break;
	case '/': res = divid(a, b); break;
	}
	return res;
}

int main() {
	cout << "2019305059 이현수" << endl << endl;
	Calculator handCalculator;
	
	
	while (true) {	
		cout << "연산을 입력하세요 : ";
		string oper;
		getline(cin, oper);
		int len = oper.length();
		int i;
		for (i = 0;i < len;i++) {
			if (oper[i] == ' ') {
				break;
			}
		}
		string num1 = oper.substr(0, i);
		int a = stoi(num1);

		char c = oper[i+1];

		string num2 = oper.substr(i+3);
		int b = stoi(num2);

		cout << oper << " = ";
		cout << handCalculator.calc(c, a, b) << endl;

		char an;
		cout << "연산을 다시할까요?(Y/N) ";
		cin >> an; getchar(); //getchar() 없으면 오류남!!!!!!!!!!!!!!!!!!!
		cout << endl;
		if (an == 'N')break;
	}
}