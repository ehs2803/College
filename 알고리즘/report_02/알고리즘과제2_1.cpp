#include<iostream>
#include<cstdlib>
#include<ctime>
#define SIZE 10000
using namespace std;

int sequential_search(int data[], int size, int target) //선형탐색 함수
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == target) return i; //찾고자하는 값이 발견되면 인덱스반환
	}
	return -1; //발견되지 않으면 -1 반환
}

int main(void) 
{
	srand((unsigned)time(NULL)); //난수를 생성하기 위한 코드

	int *data = new int[SIZE]; //배열 동적할당

	for (int i = 0; i < SIZE; i++) 
	{
		//반복문으로 배열에 0~49999난수생성
		data[i] = (int)(((long)rand() << 15) | rand()) % 50000;
	}

	cout << "[선형탐색]" << endl;
	cout << "탐색하고자 하는 값을 입력하세요 : ";
	int target; cin >> target;    //탐색하려는 값 입력
	
	//선형탐색 함수 호출. 변수i에 반환된 인덱스값 저장
	int i = sequential_search(data, SIZE, target);  

	if (i == -1)//반환받은 값이 -1이라면==찾으려는값이 없다면
	{
		cout << "발견되지 않음." << endl;
	}	
	else  //찾으려는 값이 있다면
	{
		cout << target << "이 " << "인덱스 " << i << " 에서 발견됨." << endl;
	}

	delete[]data; //배열 해체
}

/*
프로그램 2개 작성
- 정렬되지 않은 정수 10, 000개를 대상으로 원하는 값을 선형탐색하는 프로그램 작성
- 정수 10, 000개를 합병정렬로 정렬한 후 정렬된 값을 대상으로 이진탐색하는 프로그램 작성 < --분할정복 방법 적용

	프로그램 작성 지침
	- 정수 10, 000개는 난수를 이용하여 0 부터 49, 999 사이 값으로 만들 것
	- 난수들은 프로그램 실행 마다 다르게 생성되도록 할 것
	- 탐색하고자 하는 값을 입력받아 해당 값이 있다면 몇 번째 있는 것인가를 알려줄 것, 없다면 없다는 것을 알려줄 것
	- 찾아진 값이 중복된 값일 경우에는 찾아진 곳 해당 번째 하나만 알려줄 것
	- 적절한 위치에 적절한 내용으로 주석문 작성할 것(과도하게 주석문 작성하지 말 것)

	작성 언어 : C 혹은 C++
	제출물 구성 : 보고서 커버, 소스코드, 캡쳐한 실행화면(프로그램별 5회 실행한 결과 화면 : 3개는 찾아지는 경우, 2개는 찾아지지 않는 경우), 과제 수행 소감
	제출기한 : 10월 9일 23 : 59
*/