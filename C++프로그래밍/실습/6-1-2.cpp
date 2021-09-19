#include <iostream>
using namespace std;

int add(int x[], int size, int y[] = NULL);

int main() {
	cout << "2019305059 ÀÌÇö¼ö" << endl << endl;
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int c = add(a, 5); 
	int d = add(a, 5, b); 
	cout << c << endl; 
	cout << d << endl; 
}

int add(int x[], int size, int y[]) {
	int sum = 0;

	for (int i = 0; i < size; i++) sum += x[i];	

	if (y == NULL) return sum;

	for (int i = 0; i < size; i++) sum += y[i];
		
	return sum;
}