#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>
using namespace std;

class Book {
	char* title; 
	int price; 
public:
	Book(const char* title, int price);
	Book(Book& b); 
	~Book();
	void set(const char* title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(const char* title, int price) { 
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
	this->price = price;
}

Book::~Book() {
	if (title)
		delete[] title;
}

void Book::set(const char* title, int price) { 
	if (this->title)
		delete[] this->title; 
	int len = strlen(title);
	this->title = new char[len + 1]; 
	strcpy(this->title, title);
	this->price = price;
}

///*
Book::Book(Book& b) { // (3) 정답. 깊은 복사 복사 생성자 작성
	int len = strlen(b.title);
	title = new char[len + 1];
	strcpy(title, b.title);
	price = b.price;
}
//*/

int main() {
	cout << "2019305059 이현수" << endl << endl;

	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}