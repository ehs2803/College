#include<iostream>
using namespace std;

class BaseArray {
private:
	int capacity;
	int* mem;
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity; mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyQueue : public BaseArray {
	int head, tail;
	int size; // ���� ť �ȿ� �ִ� �������� ����
public:
	MyQueue(int capacity);
	void enqueue(int n);
	int dequeue();
	int capacity();
	int length();
};

MyQueue::MyQueue(int capacity) : BaseArray(capacity) {
	head = 0; // ������ ��ġ�� head
	tail = -1;  // tail+1 ��ġ���� ������
	size = 0; // �ʱ� ������ 0
}

void MyQueue::enqueue(int n) {
	if (size == capacity())
		return; // queue full error
	put(head, n);
	head++;
	head = head % capacity();
	size++;
}

int MyQueue::dequeue() {
	if (size == 0)
		return -1; // queue empty error
	size--;
	tail++;
	tail = tail % capacity();
	return get(tail);
}

int MyQueue::capacity() {
	return getCapacity();
}

int MyQueue::length() {
	return size;
}

class MyStack :public BaseArray {
	int size;
public:
	MyStack(int n) :BaseArray(n) { size = 0; }
	void push(int n);
	int pop();
	int lenght();
	int capacity();
};

void MyStack::push(int n) {
	if (size == capacity()) return;
	put(size, n);
	size++;
}

int MyStack::pop() {
	if (size == 0)return -1;
	size--;
	return get(size);
}

int MyStack::lenght() {
	return size;
}

int MyStack::capacity() {
	return getCapacity();
}
///*
int main(void) {
	cout << "2019305059 ������" << endl << endl;

	MyQueue mQ(100);
	int n;
	cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0;i < 5;i++) {
		cin >> n;
		mQ.enqueue(n);
	}
	cout << "ť�� �뷮:" << mQ.capacity() << ", ť��ũ��:" << mQ.length() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' ';
	}
	cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
}
//*/
/*
int main(void) {
	cout << "2019305059 ������" << endl << endl;

	MyStack mStack(100);
	int n;
	cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0;i < 5;i++) {
		cin >> n;
		mStack.push(n);
	}
	cout << "������ �뷮:" << mStack.capacity() << ", ������ũ��:" << mStack.lenght() << endl;
	cout << "������ ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mStack.lenght() != 0) {
		cout << mStack.pop() << ' ';
	}
	cout << endl << "������ ���� ũ�� : " << mStack.lenght() << endl;
}*/