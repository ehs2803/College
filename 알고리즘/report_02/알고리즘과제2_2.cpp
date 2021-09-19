#include<iostream>
#include<cstdlib>
#include<ctime>
#define SIZE 10000
using namespace std;

int Binary_search(int data[], int first, int last, int target)
{
	if (first > last) //ã������ ���� ���ٸ�
	{ 
		return -1;  // -1 ��ȯ
	}

	int mid = (first + last) / 2; //�迭 �߰��ε��� ���ϱ�

	if (data[mid] == target) //�迭�߰��� ���� target�� ��ġ�ϸ�
	{
		return mid; //mid�ε��� ��ȯ
	}
	else if (target < data[mid])//ã������ ���� �迭�߰������� ������
	{
		return Binary_search(data, first, mid - 1, target);
	}
	else //ã������ ���� �迭�߰������� Ŭ�� 
	{
		return Binary_search(data, mid + 1, last, target);
	}
}

void MergeTwoArea(int data[], int left, int mid, int right)
{
	int fIdx = left;    //�պκ� �迭 �����ε���
	int rIdx = mid + 1; //�޺κ� �迭 �����ε���
	
	int* sortArr = new int[right + 1]; //data�迭 ũ�⸸ŭ �պ��迭 �����Ҵ�
	int sIdx = left;  //�պ��迭 �����ε���

    //�պκ�,�޺κй迭 �� �Ѱ��� �պ��迭�� �պ����� ������� ��ӹݺ� 
	while (fIdx <= mid && rIdx <= right)
	{
		if (data[fIdx] <= data[rIdx])//�պκй迭�� ���� �޺κй迭 ������ ���ų� �� ������
		{
			sortArr[sIdx] = data[fIdx++];//�պ��迭�� �պκй迭�� ���� �� �պκй迭�ε���+1
		}
		else //�޺κй迭�� ���� �պκй迭 ������ ���� ��
		{
			sortArr[sIdx] = data[rIdx++];//�պ��迭�� �޺κй迭�� ���� �� �޺κй迭�ε���+1
		}

		sIdx++;//�պ��迭 �ε���+1
	}

	if (fIdx > mid) //�պκ� �迭 �պ� �Ϸ�
	{
		for (int i = rIdx; i <= right; i++, sIdx++) 
		{
			sortArr[sIdx] = data[i]; //�޺κй迭 ������ �ű��
		}
	}
	else //�޺κ� �迭 �պ� �Ϸ�
	{
		for (int i = fIdx; i <= mid; i++, sIdx++)
		{
			sortArr[sIdx] = data[i];//�޺κй迭 ������ �ű��
		}
	}

	for (int i = left; i <= right; i++)
	{
		data[i] = sortArr[i]; //�����迭�� �պ��� ��� ����
	}
	
	delete []sortArr;//�迭 ��ü
}

void MergeSort(int data[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;    //�迭�� �߰� �ε��� ���ϱ�

		MergeSort(data, left, mid);      //�պκ� ���ȣ��
		MergeSort(data, mid + 1, right); //�޺κ� ���ȣ��

		MergeTwoArea(data, left, mid, right); //�պ��Լ�
	}
}

int main(void)
{
	srand((unsigned)time(NULL)); //���������� ���� ����

	int *data = new int[10000];//�迭 ���� �Ҵ�

	for (int i = 0; i < SIZE; i++)
	{
		//�ݺ������� �迭�� 0~49999��������
		data[i] = (int)(((long)rand() << 15) | rand()) % 50000; 
	}
	cout << "[�պ�����, ����Ž��]" << endl;
	cout << "Ž���ϰ��� �ϴ� ���� �Է��ϼ��� : ";
	int target; cin >> target; //ã������ �� �Է�

	MergeSort(data, 0, SIZE-1); //�պ������Լ�
	
	int i = Binary_search(data, 0, SIZE-1, target); //����Ž������ ����i�� �ε��� ��ȯ

	if (i == -1) //��ȯ���� ���� -1�̶��==ã�����°��� ���ٸ�
	{
		cout << "�߰ߵ��� ����." << endl;
	}
	else //ã������ ���� �ִٸ� 
	{
		cout << target << "�� " << "�ε��� " << i << " ���� �߰ߵ�." << endl;
	}

	delete[]data;//�迭 ��ü
}
