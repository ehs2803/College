#include<stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct node
{
	int data;
	struct node* next;
}Node;

typedef struct Queue
{
	Node* front;
	Node* rear;
}Queue;

void Queueinit(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

int Qisempty(Queue* pq)
{
	if (pq->front == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void enqueue(Queue* pq, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->next = NULL;
	newnode->data = data;

	if (Qisempty(pq))
	{
		pq->front = newnode;
		pq->rear = newnode;
	}
	else
	{
		pq->rear->next = newnode;
		pq->rear = newnode;
	}
}

int dequeue(Queue* pq)
{
	Node* delnode;
	int rdata;

	if (Qisempty(pq))
	{
		printf("Queue memory error!");
		exit(-1);
	}

	delnode = pq->front;
	rdata = delnode->data;
	pq->front = pq->front->next;

	free(delnode);
	return rdata;
}

int Qpeek(Queue* pq)
{
	if (Qisempty(pq))
	{
		printf("Queue memory error!");
		exit(-1);
	}

	return pq->front->data;
}

int main(void)
{
	Queue q;
	Queueinit(&q);

	enqueue(&q, 1); enqueue(&q, 2);
	enqueue(&q, 3); enqueue(&q, 4);
	enqueue(&q, 5);

	while (!Qisempty(&q))
	{
		printf("%d ", dequeue(&q));
	}
	return 0;
}
//20200115