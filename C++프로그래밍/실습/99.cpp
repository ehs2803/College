#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(void)
{
	priority_queue<int> pq; //����Ʈ�� ����ũ�� �켱������ ���ٰ� ���ֵȴ�!!
	pq.push(100);
	pq.push(200);
	pq.push(300);
	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
}