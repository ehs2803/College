#include<iostream>
#include<cstdlib>
#include<ctime>
#define SIZE 10000
using namespace std;

int Binary_search(int data[], int first, int last, int target)
{
	if (first > last) //찾으려는 값이 없다면
	{ 
		return -1;  // -1 반환
	}

	int mid = (first + last) / 2; //배열 중간인덱스 구하기

	if (data[mid] == target) //배열중간의 값과 target이 일치하면
	{
		return mid; //mid인덱스 반환
	}
	else if (target < data[mid])//찾으려는 값이 배열중간값보다 작을때
	{
		return Binary_search(data, first, mid - 1, target);
	}
	else //찾으려는 값이 배열중간값보다 클때 
	{
		return Binary_search(data, mid + 1, last, target);
	}
}

void MergeTwoArea(int data[], int left, int mid, int right)
{
	int fIdx = left;    //앞부분 배열 시작인덱스
	int rIdx = mid + 1; //뒷부분 배열 시작인덱스
	
	int* sortArr = new int[right + 1]; //data배열 크기만큼 합병배열 동적할당
	int sIdx = left;  //합병배열 시작인덱스

    //앞부분,뒷부분배열 중 한개라도 합병배열에 합병되지 않은경우 계속반복 
	while (fIdx <= mid && rIdx <= right)
	{
		if (data[fIdx] <= data[rIdx])//앞부분배열의 값이 뒷부분배열 값보다 같거나 더 작을때
		{
			sortArr[sIdx] = data[fIdx++];//합병배열에 앞부분배열값 저장 후 앞부분배열인덱스+1
		}
		else //뒷부분배열의 값이 앞부분배열 값보다 작을 때
		{
			sortArr[sIdx] = data[rIdx++];//합병배열에 뒷부분배열값 저장 후 뒷부분배열인덱스+1
		}

		sIdx++;//합병배열 인덱스+1
	}

	if (fIdx > mid) //앞부분 배열 합병 완료
	{
		for (int i = rIdx; i <= right; i++, sIdx++) 
		{
			sortArr[sIdx] = data[i]; //뒷부분배열 나머지 옮기기
		}
	}
	else //뒷부분 배열 합병 완료
	{
		for (int i = fIdx; i <= mid; i++, sIdx++)
		{
			sortArr[sIdx] = data[i];//뒷부분배열 나머지 옮기기
		}
	}

	for (int i = left; i <= right; i++)
	{
		data[i] = sortArr[i]; //원본배열에 합병한 결과 저장
	}
	
	delete []sortArr;//배열 해체
}

void MergeSort(int data[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;    //배열의 중간 인덱스 구하기

		MergeSort(data, left, mid);      //앞부분 재귀호출
		MergeSort(data, mid + 1, right); //뒷부분 재귀호출

		MergeTwoArea(data, left, mid, right); //합병함수
	}
}

int main(void)
{
	srand((unsigned)time(NULL)); //난수생성을 위한 선언

	int *data = new int[10000];//배열 동적 할당

	for (int i = 0; i < SIZE; i++)
	{
		//반복문으로 배열에 0~49999난수생성
		data[i] = (int)(((long)rand() << 15) | rand()) % 50000; 
	}
	cout << "[합병정렬, 이진탐색]" << endl;
	cout << "탐색하고자 하는 값을 입력하세요 : ";
	int target; cin >> target; //찾으려는 값 입력

	MergeSort(data, 0, SIZE-1); //합병정렬함수
	
	int i = Binary_search(data, 0, SIZE-1, target); //이진탐색으로 변수i에 인덱스 반환

	if (i == -1) //반환받은 값이 -1이라면==찾으려는값이 없다면
	{
		cout << "발견되지 않음." << endl;
	}
	else //찾으려는 값이 있다면 
	{
		cout << target << "이 " << "인덱스 " << i << " 에서 발견됨." << endl;
	}

	delete[]data;//배열 해체
}
