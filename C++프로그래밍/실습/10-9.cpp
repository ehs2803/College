#include<iostream>
#include<vector>
using namespace std; 

int main(void) {
	cout << "2019305059 ������" << endl << endl;

	vector<int> v;
	double sum = 0;

	while (true) {
		int inputnum;
		cout << "������ �Է��ϼ���(0�� �Է��ϸ� ����)>>";
		cin >> inputnum;

		if (inputnum == 0) break;

		v.push_back(inputnum);
		sum += inputnum;

		for (int i = 0;i < v.size();i++) {
			cout << v[i] << ' ';
		}
		cout << endl;
		cout << "��� = ";
		cout << sum / v.size() << endl;
	}
}