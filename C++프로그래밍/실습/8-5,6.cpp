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
	int size; // 현재 큐 안에 있는 데이터의 개수
public:
	MyQueue(int capacity);
	void enqueue(int n);
	int dequeue();
	int capacity();
	int length();
};

MyQueue::MyQueue(int capacity) : BaseArray(capacity) {
	head = 0; // 삽입할 위치는 head
	tail = -1;  // tail+1 위치에서 꺼내기
	size = 0; // 초기 개수는 0
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
	cout << "2019305059 이현수" << endl << endl;

	MyQueue mQ(100);
	int n;
	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0;i < 5;i++) {
		cin >> n;
		mQ.enqueue(n);
	}
	cout << "큐의 용량:" << mQ.capacity() << ", 큐의크기:" << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' ';
	}
	cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
}
//*/
/*
int main(void) {
	cout << "2019305059 이현수" << endl << endl;

	MyStack mStack(100);
	int n;
	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0;i < 5;i++) {
		cin >> n;
		mStack.push(n);
	}
	cout << "스택의 용량:" << mStack.capacity() << ", 스택의크기:" << mStack.lenght() << endl;
	cout << "스택의 원소를 순서대로 제거하여 출력한다>> ";
	while (mStack.lenght() != 0) {
		cout << mStack.pop() << ' ';
	}
	cout << endl << "스택의 현재 크기 : " << mStack.lenght() << endl;
}*/