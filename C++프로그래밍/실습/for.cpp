#include<iostream>
using namespace std;

int main(void) {
	int n, m;
	
	cout << "시작수를 입력하세요 : ";
	cin >> n;

	cout << "끝수를 입력하세요 : ";
	cin >> m;

    int sum = 0;

	for (int i = n; i <= m;i++) {
		if (i % 3 == 0) sum += i;
	}
	cout << n << "부터 " << m << "까지의 수 중에서 3의 배수인 수의 합은 " << sum << endl;
}