#include<iostream>
#include<fstream>
using namespace std;

int main(void)
{
	ifstream is;
	is.open("score.txt");
	if(is.fail())    //if (!a) //!������ �ߺ� ����
	{
		cerr << "���� ���¿� ����!!" << endl;
		exit(1);
	}

	int number;
	char name[20];
	int score;
	is >> number >> name >> score;

	ofstream b;
	b.open("result.txt", ios::app); //ios::app�� ���̰ԵǸ� ������ �ִ� ���Ͽ� �ڷᰡ �߰���. ���ָ� �ڷ��߰� �ȵǰ� �����ʱ�ȭ�� �Է�!!
	b << number << " " << name << " " << score << endl;

    is.close();
	b.close();
}
//20200121