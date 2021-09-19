#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(void)
{
	priority_queue<int> pq; //디폴트로 값이크면 우선순위가 높다고 간주된다!!
	pq.push(100);
	pq.push(200);
	pq.push(300);
	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
}