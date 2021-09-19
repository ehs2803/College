#include<iostream>
#include<string>
using namespace std;

class fullstack
{

};

class emptystack
{

};

template<typename T>
class stack
{
private:
	T* s;
	int size;
	int top;
public:
	stack(int n = 100) :size(n), top(-1)
	{
		s = new T[size];
	}
	~stack() { delete[] s; }
	void push(T v)
	{
		if (isfull()) throw fullstack();
		s[++top] = v;
	}
	T pop()
	{
		if (isempty()) throw emptystack();
		return s[top--];
	}
	bool isempty() const { return top == -1; }
	bool isfull() const { return top == size - 1; }
};

int main(void)
{
	stack<int> s;
	s.push(100);
	s.push(200);
	s.push(300);
	s.push(400);
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	cout << endl << endl;

	stack<char> c;
	string str = "madam";

	for (int i = 0; i < str.length(); i++)
	{
		c.push(str[i]);
	}

	for (int i = 0; i < str.length(); i++)
	{
		if (s.pop() != str[i])
		{
			cout << "not palindrome" << endl;
			return 0;
		}
	}
	cout << "palindrone" << endl;
}
//20200122 error