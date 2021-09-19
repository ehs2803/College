#include<iostream>
using namespace std;

void Swap_Value(int m, int n);
void Swap_Address(int* pm, int* pn);
void Swap_Reference(int& rm, int& rn);

int main(void) {
cout << "2019305059 이현수" << endl <<endl;
int m, n;
cout << "두개 정수 입력>>";	cin >> m >> n;
Swap_Value(m, n);     cout << "swap_value" << endl;     cout<<"m = "<<m<<' '<<"n = "<<n<< endl<<endl;
Swap_Address(&m, &n); cout << "swap_Address" << endl;   cout<<"m = "<<m<<' '<<"n = "<<n<< endl<<endl;
Swap_Reference(m, n); cout << "swap_Refernece" << endl; cout<<"m = "<<m<<' '<<"n = "<<n<< endl<<endl;
}

void Swap_Value(int m, int n) {
	int tmp;
	tmp = m;
	m = n;
	n = tmp;
}

void Swap_Address(int* pm, int* pn) {
	int tmp;
	tmp = *pm;
	*pm = *pn;
	*pn = tmp;
}

void Swap_Reference(int& rm, int& rn) {
	int tmp;
	tmp = rm;
	rm = rn;
	rn = tmp;
}