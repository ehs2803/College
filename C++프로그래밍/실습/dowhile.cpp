#include<iostream>
using namespace std;

int main(void) {
	int n, m;

	cout << "���ۼ��� �Է��ϼ��� : ";
	cin >> n;

	cout << "������ �Է��ϼ��� : ";
	cin >> m;

	int sum = 0;
	int i = n;
	do {
		if (i % 3 == 0)sum += i;
		i++;
	} while (i <= m);

	cout << n << "���� " << m << "������ �� �߿��� 3�� ����� ���� ���� " << sum << endl;
}