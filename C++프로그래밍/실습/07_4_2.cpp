#include<iostream>
#include<cstring>
using namespace std;

class book
{
private:
	char* title;
	char* isbn;
	int price;
public:
	book(const char* title, const char* isbn, int value)
		:price(value)
	{
		this->title = new char[strlen(title) + 1];
		this->isbn = new char[strlen(isbn) + 1];
		strcpy(this->title, title);
		strcpy(this->isbn, isbn);
	}
	void showbookinfo()
	{
		cout << "title: " << title << endl;
		cout << "isbn: " << isbn << endl;
		cout << "price: " << price << endl;
	}
	~book()
	{
		delete[]title;
		delete[]isbn;
	}
};

class ebook :public book
{
private:
	char* drmkey;
public:
	ebook(const char* title, const char* isbn, int value, const char* key)
		:book(title, isbn, value)
	{
		drmkey = new char[strlen(key) + 1];
		strcpy(drmkey, key);
	}
	void showebookinfo()
	{
		showbookinfo();
		cout << "인증키: " << drmkey << endl;
	}
	~ebook()
	{
		delete[]drmkey;
	}
};

int main(void)
{
	book book("좋은 C++", "555-12345-890-0", 20000);
	book.showbookinfo();
	cout << endl;
	ebook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.showebookinfo();
}
//20200109
