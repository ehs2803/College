#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
using namespace std;

template<typename T>
void print(const T& v, const char* message = " ")
{
	typename T::const_iterator it;
	cout << message;
	cout << "(";
	for (it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << ")" << endl;
}

bool check(string s)
{
	if (s.find("kim") != string::npos) return true;
	else return false;
}
int main(void)
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}

	vector<int>::const_iterator it;
	it = vec.begin();
	cout << it[2] << " " << endl; //임의접근
	cout << *(it + 2) << " " << endl; 
	it = it + 5;
	it--;
	cout << *it << " " << endl<<endl;
	////////////////////////////////////////////////////////////
	string frutis[5] = { "apple", "tomato","bal","watermelon","kiwi" };
	vector<string> str(&frutis[0], &frutis[5]);
	vector<string>::iterator a;
	a = find(str.begin(), str.end(), "watermelon");
	if (a != str.end())
	{
		cout << "watermelon location " << distance(str.begin(), a) << endl << endl;
	}
	//////////////////////////////////////////////////////////// error
	string name[5] = { "kim","park","kan","king","lee" };
	vector<string> na(&name[0], &name[5]);
	vector<string>::iterator s;
	s = na.begin();
	while (true)
	{
		s = find_if(s, na.end(), check);
		if (s == na.end()) break;
		cout << "location" << distance(na.begin(), s) << *s << endl;
		s++;
	}
	cout << endl << endl;
	/////////////////////////////////////////////////////////////////
	vector<int> se1;
	for (int i = 0; i < 10; i++)
	{
		se1.push_back(i);
	}

	list<int> slist;
	for (int i = 3; i < 6; i++)
	{
		slist.push_back(i);
	}
	vector<int>::iterator sea;
	sea = search(se1.begin(), se1.end(), slist.begin(), slist.end());
	if (sea != se1.end())
	{
		cout << distance(se1.begin(), sea) << endl << endl;
	}
	//////////////////////////////////////////////////////////////////
    
}
//20200124
/*
역순반복자
vector<int>::reverse_iterator rit;
for(rit=vec.rbegin(); rit!=vec.rend(); rit++)
   cout<< *rit << " ";
*/