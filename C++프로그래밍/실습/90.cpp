#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	vector<double> score(10);

	for (int i = 0; i < score.size(); i++)
	{
		cout << "input score: ";
		cin >> score[i];
	}

	double highest = score[0];
	for (int i = 0; i < score.size(); i++)
	{
		if (score[i] > highest)
		{
			highest = score[i];
		}
	}
	cout << "highest score: " << highest << endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cout << endl << endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	vector<double> scores;
	vector<double>::iterator go;
	while (true)
	{
		double value = 0;
		cout << "input socre(exit:=-1): ";
		cin >> value;
		if (value < 0) break;
		scores.push_back(value);
	}

	highest = scores[0];
	for (go = scores.begin(); go != scores.end(); go++)
	{
		if (*go > highest)
		{
			highest = *go;
		}
	}
	for (go = scores.begin(); go != scores.end(); go++)
	{
		cout << *go << " ";
	}
	cout << endl;
	cout << "highest score: " << highest << endl;
}
//20200123
/*
vector<int> array1;                  //ũ�Ⱑ 0�� ���ͻ���
vector<int> array2(10);          //10���ǿ�Ҹ� ������ ���ͻ���. ��� �ʱⰪ�� 0.
vector<int> array3(10, 1);      //10���� ��Ҹ� 1�� �ʱ�ȭ
vector<int> array4(array3);    //array3�� �Ȱ��� ��Ҹ� ������ ���� ����

int data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
vector<int> array5(data, data+5); //data�迭�� 5����Ҹ� ������ ���� ���� 
*/