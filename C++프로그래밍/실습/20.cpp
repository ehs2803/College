#include<iostream>
#include<string>
using namespace std;

class car
{
private:
	const int id;
	string color;
	static int code;
	static const int company = 123456789; //static const형은 바로 초기화가능
public:
	static int numberofcar;
	car() :id(0)
	{
		color = "white";
	}
	car(int id, string s) :id(id), color(s)
	{
		numberofcar++;
	}
	void print() const //const를 붙인 이러한 상수화된함수에서 상수화되지 않은 함수를 호출못함.
	{
		cout << id << " " << color << " " << company << endl;
	}
	void a() const //const가 있냐 없냐는 함수오버로딩 조건으로 가능!!
	{
		cout << "a" << endl;
	}
	void a()
	{
		cout << "b" << endl;
	}
	static void first() //정적함수는 정적변수, 정적함수만을 호출가능!!
	{
		two();
	}
	static void two() 
	{
		cout << numberofcar <<" "<<company<<endl;
	}
	~car()
	{
		cout << "delete car class" << endl;
		numberofcar--;
	}

};
int car::numberofcar = 0;
int car::code = 1234;

int main(void)
{
	cout << car::numberofcar << endl;
	car::first();

	cout << endl << endl;

	car array[2] = {
		car(1,"white"), car(2, "red")
	};
	for(int i = 0; i < 2; i++)
	{
		(array + i)->print();   //array[i].print(); 
	}

	cout << endl << endl;

	car::first();
}
//20200118