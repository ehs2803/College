#include<iostream>
using namespace std;

#include "Calculator.h"
#include "Adder.h"

void Calculator::run() {
	cout << "2019305059 ������" << endl << endl;

	cout << "�� ���� ���� �Է��ϼ���>>";
	int a, b;
	cin >> a >> b;
	Adder adder(a, b);
	cout << adder.process();
}