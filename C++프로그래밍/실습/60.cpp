#include<iostream>
#include<fstream>
using namespace std;

int main(void)
{
	ifstream is;
	is.open("score.txt");
	if(is.fail())    //if (!a) //!연산자 중복 정의
	{
		cerr << "파일 오픈에 실패!!" << endl;
		exit(1);
	}

	int number;
	char name[20];
	int score;
	is >> number >> name >> score;

	ofstream b;
	b.open("result.txt", ios::app); //ios::app을 붙이게되면 기존에 있던 파일에 자료가 추가됨. 없애면 자료추가 안되고 파일초기화후 입력!!
	b << number << " " << name << " " << score << endl;

    is.close();
	b.close();
}
//20200121