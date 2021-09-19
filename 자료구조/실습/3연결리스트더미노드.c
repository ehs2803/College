#include<stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct node
{
	int data;
	struct node* next;
}Node;

typedef struct linklist
{
	Node* head;
	Node* cur;
	Node* before;
	int numofdata;
	int (*comp)(int d1, int d2);
}List;

void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); //dummy node
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numofdata = 0;
}

void FInsert(List* plist, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	newnode->next = plist->head->next;
	plist->head->next = newnode;

	(plist->numofdata)++;
}

void SInsert(List* plist, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	Node* pred = plist->head;
	newnode->data = data;

	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}

	newnode->next = pred->next;
	pred->next = newnode;

	(plist->numofdata)++;
}

void LInsert(List* plist, int data)
{
	if (plist->comp == NULL)
	{
		FInsert(plist, data);
	}
	else
	{
		SInsert(plist, data);
	}
}

int LFirst(List* plist, int* pdata)
{
	if (plist->head->next==NULL)
	{
		return FALSE;
	}
	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, int* pdata)
{
	if (plist->cur->next == NULL)
	{
		return FALSE;
	}
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LRemove(List* plist)
{
	Node* rpos = plist->cur;
	int rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numofdata)--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numofdata;
}

void setsortrule(List* plist, int (*comp)(int d1, int d2))
{
	plist->comp = comp;
}

int Whoispreced(int d1, int d2)
{
	if (d1 < d2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main(void)
{
	List list;
	int data;
	ListInit(&list);

	setsortrule(&list, Whoispreced);
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);

	printf("currently data num: %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}
	printf("\n\n");

	if (LFirst(&list, &data))
	{
		if (data == 22)
		{
			LRemove(&list);
		}
		while(LNext(&list,&data))
		{
			if (data == 22)
			{
				LRemove(&list);
			}
		}
	}

	printf("currently data num: %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}
	printf("\n\n");
}
//20200109