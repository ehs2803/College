#include<iostream>
using namespace std;

double GetAverage(double* pl, int size);

int main(void) {
	cout << "2019305059 이현수" << endl << endl;

	double list[5];
	cout << "실수 5개 입력>>";
	for (int i = 0;i < 5;i++) {
		cin >> *(list+i);
	}
	for (int i = 0;i < 5;i++) {
		cout << *(list+i)<<" ";
	}
	cout << "의 평균 = " << GetAverage(list, 5) << endl;
}

double GetAverage(double* pl, int size) {
	double sum = 0;
	for (int i = 0;i < 5;i++) {
		sum += *(pl + i);
	}
	double ave = sum / size;
	return ave;
}