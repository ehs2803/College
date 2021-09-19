#include<iostream>
using namespace std;

class student
{
private:
	char* name;
	char* telephone;
public:
	student(const char* fname, const char* num)
	{
		name = new char[strlen(fname) + 1];
		strcpy(this->name, fname);

		telephone = new char[strlen(num) + 1];
		strcpy(this->telephone, num);
	}
	char* getnumber() const
	{
		return telephone;
	}
	void setnumber(const char* num)
	{
		delete[]telephone;
		telephone = new char[strlen(num) + 1];
		strcpy(telephone, num);
	}
	char* getname() const
	{
		return name;
	}
	void setname(const char* name)
	{
		delete[]name;
		name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
};

class lab
{
	char* name;
	student* chief;
	student* manager;
public:
	lab(const char* n)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		chief = NULL;
		manager = NULL;
	}
	void setchief(student* p)
	{
		chief = p;
	}
	void setmanager(student* p)
	{
		manager = p;
	}
	void print() const
	{
		cout << name << "labortary" << endl;
		if (chief != NULL)
		{
			cout << "chief is " << chief->getname() << endl;
		}
		else
		{
			cout << "currently no chief" << endl;
		}
		if (manager != NULL)
		{
			cout << "manager is " << manager->getname() << endl;
		}
		else
		{
			cout << "currently no manager" << endl;
		}
	}
};

int main(void)
{
	lab lab("c++");
	student* p = new student("lee", "010-1111-1111");

	lab.setchief(p);
	lab.setmanager(p);
	lab.print();

	delete p;
}
//20200118