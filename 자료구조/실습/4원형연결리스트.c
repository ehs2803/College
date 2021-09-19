#include<stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct node
{
	int data;
	struct node* next;
}Node;

typedef struct CLL
{
	Node* tail;
	Node* cur;
	Node* before;
	int numofdata;
}Clist;

void ClistInit(Clist* plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numofdata = 0;
}

void Cinsert(Clist* plist, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newnode;
		newnode->next = newnode;
	}
	else
	{
		newnode->next = plist->tail->next;
		plist->tail->next = newnode;
		plist->tail = newnode;
	}
	(plist->numofdata)++;
}

void Cinsertfront(Clist* plist, int data)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newnode;
		newnode->next = newnode;
	}
	else
	{
		newnode->next = plist->tail->next;
		plist->tail->next = newnode;
	}
	(plist->numofdata)++;
}

int Clfirst(Clist* plist, int* pdata)
{
	if (plist->tail == NULL)
	{
		return FALSE;
	}

	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int Clnext(Clist* plist, int* pdata)
{
	if (plist->tail == NULL)
	{
		return FALSE;
	}

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LRemove(Clist* plist)
{
	Node* rpos = plist->cur;
	int rdata = rpos->data;

	if (rpos == plist->tail)
	{
		if (plist->tail == plist->tail->next)
		{
			plist->tail = NULL;
		}
		else
		{
			plist->tail = plist->before;
		}
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numofdata)--;
	return rdata;
}

int LCount(Clist* plist)
{
	return plist->numofdata;
}

int main(void)
{
	Clist list;
	int data, i, nodenum;
	ClistInit(&list);

	Cinsert(&list, 3);
	Cinsert(&list, 4);
	Cinsert(&list, 5);
	Cinsertfront(&list, 2);
	Cinsertfront(&list, 1);

	if (Clfirst(&list, &data))
	{
		printf("%d ", data);
		for (i = 0; i < LCount(&list) * 3 - 1; i++)
		{
			if (Clnext(&list, &data))
			{
				printf("%d ", data);
			}
		}
	}
	printf("\n\n");

	nodenum = LCount(&list);

	if (nodenum != 0)
	{
		Clfirst(&list, &data);
		if (data %2 == 0)
		{
			LRemove(&list);
		}

		for (i = 0; i < nodenum - 1; i++)
		{
			Clnext(&list, &data);
			if (data %2 == 0)
			{
				LRemove(&list);
			}
		}
	}

	if (Clfirst(&list, &data))
	{
		printf("%d ", data);
		for (i = 0; i < LCount(&list)- 1; i++)
		{
			if (Clnext(&list, &data))
			{
				printf("%d ", data);
			}
		}
	}
}
//20200109