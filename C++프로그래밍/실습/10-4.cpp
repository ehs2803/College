#include<iostream>
using namespace std;

template<class T>
bool search(T k, T a[], int s) {
	for (int i = 0;i < s;i++)
	{
		if (a[i] == k) return true;
	}
	return false;
}
int main(void) {
	cout << "2019305059 ������" << endl << endl;

	int x[] = { 1,2,3,4,5 };
	if (search(1, x, 5))cout << "1�� �迭 x�� ���ԵǾ� �ִ�";
	else cout << "1�� �迭 x�� ���ԵǾ� ���� �ʴ�";
	cout << endl << endl;

	double y[] = { 1.1, 5.6, 9.5, 10.1, 15.1 };
	if (search(10.0, y, 5))cout << "10.0�� �迭 y�� ���ԵǾ� �ִ�";
	else cout << "10.0�� �迭 y�� ���ԵǾ� ���� �ʴ�";
}