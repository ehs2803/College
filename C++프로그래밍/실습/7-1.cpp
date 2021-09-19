#include<iostream>
#include<string>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
	}
	string getTitle() { return title; }
	/*Book& operator +=(int price){
		this->price += price;
		return *this;
	}
	Book& operator -=(int price) {
		this->price -= price;
		return *this;
	}*/
	friend Book& operator +=(Book& book, int price);
	friend Book& operator -=(Book& book, int price);
	/*bool operator==(int n) {
		if (price == n)return true;
		else return false;
	}
	bool operator==(string str) {
		if (title == str)return true;
		else return false;
	}
	bool operator==(Book a) {
		if (title == a.title) {
			if (price == a.price) {
				if (pages == a.pages) {
					return true;
				}
			}
		}
		return false;
	}*/
	friend bool operator==(Book a, int n);
	friend bool operator==(Book a, string str);
	friend bool operator==(Book a, Book b);
	bool operator!() {
		if (price == 0)return true;
		else return false;
	}
	
};
Book& operator +=(Book& book, int price) {
	book.price += price;
	return book;
}

Book& operator -=(Book& book, int price) {
	book.price -= price;
	return book;
}
bool operator==(Book a, int n) {
	if (a.price == n)return true;
	else return false;
}
bool operator==(Book a, string str) {
	if (a.title == str)return true;
	else return false;
}
bool operator==(Book a, Book b) {
	if (a.title == b.title) {
		if (a.price == b.price) {
			if (a.pages == b.pages) {
				return true;
			}
		}
	}
	return false;
}
bool operator<(string str, Book a) {
	if (str < a.getTitle()) return true;
	else return false;
}
/* 1-1, 1-2
int main(void) {
	cout<<"2019305059 ������"<<endl<<endl;
	Book a("û��", 20000, 300), b("�̷�", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();
}
*/
/* 2-1, 2-2
int main(void) {
	cout<<"2019305059 ������"<<endl<<endl;
	Book a("��ǰ C++", 30000, 500), b("��ǰ C++", 30000, 500);
	if(a==30000) cout<<"���� 30000��"<<endl;
	if(a=="��ǰ C++") cout<<"��ǰ C++ �Դϴ�."<<endl;
	if(a==b) cout<<"�� å�� ���� å�Դϴ�."<<endl;
}
*/
/* 3
int main(void) {
	cout<<"2019305059 ������"<<endl<<endl;
    Book book("�������", 0, 50);
	if(!book) cout<<"��¥��"<<endl;
}
*/
///* 4
int main(void) {
	cout<<"2019305059 ������"<<endl<<endl;
	Book a("û��", 20000, 300);
	string b;
	cout<<"å �̸��� �Է��ϼ���>>";
	getline(cin,b);
	if(b<a){
	   cout<<a.getTitle()<<"�� "<<b<<"���� �ڿ� �ֱ���!"<<endl;
	}
}
//*/