#ifndef __LIST_ARRAY_H__
#define __LIST_ARRAY_H__
#include<stdbool.h>
#define MAX 100

typedef struct {
	int count;
	int Data[MAX];
}listType_array;

void Inint_array(listType_array* Lptr);

int Length_array(listType_array* Lptr);

void Insert_array(listType_array* Lptr, int position, int item);

bool IsEmpty_array(listType_array* Lptr);

void Delete_array(listType_array* Lptr, int position);

void Update_array(listType_array* Lptr, int position, int item);

void Retrieve_array(listType_array* Lptr, int position, int* item);

#endif
//20200706-3