#include<iostream>
using namespace std;

double GetAve(int list[], int size);

int main(void) {
	cout << "2019305059 ������" << endl << endl;
	int list[5];
	cout << "���� 5�� �Է�>>";
	for (int i = 0;i < 5;i++) {
		cin >> list[i];
	}
	cout << "��� " << GetAve(list, 5);
}

double GetAve(int list[], int size) {
	double sum = 0;
	for (int i = 0;i < size;i++) {
		sum += list[i];
	}
	double ave = sum / size;
	return ave;
}