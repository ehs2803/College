#include<iostream>
#include<cstring>
using namespace std;

class Person {
	char* name;
	int id;
public:
	Person(int id, const char* name);
	Person(const Person& person);
	~Person();
	void changeName(const char* name);
	void show() { cout << id << ',' << name << endl; }
};

Person::Person(int id, const char* name) {
	this->id = id;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
}

Person::Person(const Person& person) {
	this->id = person.id;
	int len = strlen(person.name);
	this->name = new char[len + 1];
	strcpy(this->name, person.name);
	cout << "복사 생성자 실행. 원본 객체의 이름" << this->name << endl;
}

Person::~Person() {
	if (name) delete[]name;
}

void Person::changeName(const char* name) {
	if (strlen(name) > strlen(this->name)) {
		delete[] this->name;
		int len = strlen(name);
		this->name = new char[len + 1];
		strcpy(this->name, name);
	}
	else {
	   strcpy(this->name, name);
	}
}

int main(void) {
	cout << "2019305059 이현수" << endl << endl;
	Person father(1, "Kitae");
	Person daughter(father);

	cout << "daughter 객체 생성 직후 ----" << endl;
	father.show();
	daughter.show();

	daughter.changeName("aaaaaaaaaa");
	cout << "daughter 이름을 aaaaaaaaaa로 변경한 후 ----" << endl;
	father.show();
	daughter.show();

	return 0;
}