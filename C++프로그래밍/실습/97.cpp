#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(void)
{
	stack<string> st;
	string sayings[3] = { "the grass is greener on the other side of the fence",
	"even the greatest make mistakes", "to see is to believe" };

	for (int i = 0; i < 3; i++)
	{
		st.push(sayings[i]);
	}
	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
}
//20200123