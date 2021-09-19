#include<iostream>
using namespace std;

void InputNumber(double array[], int size);
double GetAverage(double array[], int size);
void PrintArray(double array[], int size);

int main(void) {
	cout << "2019305059 이현수" << endl<<endl;
	double array[5];	double ave;

	InputNumber(array, 5);
	PrintArray(array, 5);
	cout << "의 평균 = " << GetAverage(array, 5) << endl;
}

void InputNumber(double array[], int size) {
	cout << "실수 " << size << "개 입력>>";
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
}

double GetAverage(double array[], int size) {
	double sum = 0;
	double avg;
	for (int i = 0; i < size; i++) {
		sum += array[i];
	}
	avg = sum / size;
	return avg;
}

void PrintArray(double array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
	}
}