#include<iostream>
#include<string>
#include<vector>
using namespace std;

class movie
{
private:
	string title;
	double rating;
public:
	movie(string t, double r = 0)
	{
		title = t;
		rating = r;
	}
	void print()
	{
		cout << title << ": " << rating << endl;
	}
};

int main(void)
{
	vector<movie> movies;

	movie m("titinic", 9.9);
	movies.push_back(m);
	movies.push_back(movie("gone with the wind", 9.6));
	movies.push_back(movie("terminator", 9.7));

	vector<movie>::iterator it;
	for (it = movies.begin(); it != movies.end(); it++)
	{
		it->print();
	}
}
//20200123