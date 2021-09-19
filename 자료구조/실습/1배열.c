#include<stdio.h>

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100

typedef struct arraylist
{
	int arr[LIST_LEN];
	int numofdata;
	int curposition;
}List;

void ListInit(List* plist)
{
	(plist->numofdata) = 0;
	(plist->curposition) = -1;
}

void LInsert(List* plist, int data)
{
	if (plist->numofdata > LIST_LEN)
	{
		printf("save can not!!\n");
		return;
	}

	plist->arr[plist->numofdata] = data;
	(plist->numofdata)++;
}

int LFirst(List* plist, int* pdata)
{
	if (plist->numofdata == 0)
	{
		return FALSE;
	}

	(plist->curposition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List* plist, int* pdata)
{
	if (plist->curposition >= (plist->numofdata) - 1)
	{
		return FALSE;
	}

	(plist->curposition)++;
	*pdata = plist->arr[plist->curposition];
	return TRUE;
}

int LRemove(List* plist)
{
	int rpos = plist->curposition;
	int num = plist->numofdata;
	int i;
	int rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++)
	{
		plist->arr[i] = plist->arr[i + 1];
	}

	(plist->numofdata)--;
	(plist->curposition)--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numofdata;
}

int main(void)
{
	List list;
	int data;
	ListInit(&list);

	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);

	printf("currently data num: \n", LCount(&list));

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

		while (LNext(&list, &data))
		{
			if (data == 22)
			{
				LRemove(&list);
			}
		}
	}

	printf("currently data num: \n", LCount(&list));

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