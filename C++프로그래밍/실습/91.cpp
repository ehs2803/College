#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(void)
{
	vector<string> vec;

	vec.push_back("milk");
	vec.push_back("bread");
	vec.push_back("butter");

	vector<string>::iterator it;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;

	vec.insert(vec.begin() + 1, "apple");
	vec.pop_back();
	vec.erase(vec.begin());
    for (it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//20200123
/*
vector<int> v1;
vector<int> v2;
v2=v1;

==, !=연산자를 사용할 수 있다.
*/