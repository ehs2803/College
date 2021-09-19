#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define QUE_LEN 100

typedef struct Q
{
	int front;
	int rear;
	int quearr[QUE_LEN];
}Queue;

void Qinit(Queue* pq)
{
	pq->front = 0;
	pq->rear = 0;
}

int Qisempty(Queue* pq)
{
	if (pq->front == pq->rear)
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
	if (nextposidx(pq->rear) == pq->front)
	{
		printf("Queue memory error!");
		exit(-1);
	}

	pq->rear = nextposidx(pq->rear);
	pq->quearr[pq->rear] = data;
}

int dequeue(Queue* pq)
{
	if (Qisempty(pq))
	{
		printf("Queue memory error!");
		exit(-1);
	}

	pq->front = nextposidx(pq->front);
	return pq->quearr[pq->front];
}

int qpeek(Queue* pq)
{
	if (Qisempty(pq))
	{
		printf("Queue memory error!");
		exit(-1);
	}

	return pq->quearr[nextposidx(pq->front)];
}

int nextposidx(int pos)
{
	if (pos == QUE_LEN - 1)
	{
		return 0;
	}
	else
	{
		return pos + 1;
	}
}
int main(void)
{
	Queue q;
	Qinit(&q);

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