#include<iostream>
#include<vector>
using namespace std; 

int main(void) {
	cout << "2019305059 이현수" << endl << endl;

	vector<int> v;
	double sum = 0;

	while (true) {
		int inputnum;
		cout << "정수를 입력하세요(0을 입력하면 종료)>>";
		cin >> inputnum;

		if (inputnum == 0) break;

		v.push_back(inputnum);
		sum += inputnum;

		for (int i = 0;i < v.size();i++) {
			cout << v[i] << ' ';
		}
		cout << endl;
		cout << "평균 = ";
		cout << sum / v.size() << endl;
	}
}