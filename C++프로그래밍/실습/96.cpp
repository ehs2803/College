#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(void)
{
	map<string, string> dic;
	dic["boy"] = "소년";
	dic["school"] = "학교";
	dic["office"] = "직장";

	cout << "boy mean " << dic["boy"] << endl;

	map<string, int> table;
	string s;

	cout << "input sentence: ";
	while (1)
	{
		cin >> s;
		table[s]++;
		if (cin.eof()) break;
	}

	map<string, int>::iterator iter;
	for (iter = table.begin(); iter != table.end(); iter++)
	{
		cout << iter->first << " : " << iter->second << endl;
	}
}
//20200123