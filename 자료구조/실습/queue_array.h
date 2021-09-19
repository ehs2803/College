#ifndef __QUEUE_ARRAY_H__
#define __QUEUE_ARRAY_H__
#define MAX 100
#include<stdbool.h>

typedef struct {
	int Front, Rear;
	int count;
	int Queue[MAX];
}Queue_array;

void Inint_queue_array(Queue_array* Qptr);

void Add_array(Queue_array* Qptr, int item);

int Remove_array(Queue_array* Qptr);

bool IsEmpty_queue_array(Queue_array* Qptr);

int Getsize_array(Queue_array* Qptr);

void getFront_array(Queue_array* Qptr, int* item);

#endif
//20200706-4