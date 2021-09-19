#include<iostream>
using namespace std;

double GetAve(int list[], int size);

int main(void) {
	cout << "2019305059 이현수" << endl << endl;
	int list[5];
	cout << "정수 5개 입력>>";
	for (int i = 0;i < 5;i++) {
		cin >> list[i];
	}
	cout << "평균 " << GetAve(list, 5);
}

double GetAve(int list[], int size) {
	double sum = 0;
	for (int i = 0;i < size;i++) {
		sum += list[i];
	}
	double ave = sum / size;
	return ave;
}