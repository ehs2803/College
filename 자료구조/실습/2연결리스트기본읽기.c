#include<stdio.h>

typedef struct node
{
	int data;
	struct node* next;
}Node;

int main(void)
{
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;

	Node* newnode = NULL;
	int readdata;

	while (1)
	{
		printf("input number: ");
		scanf_s("%d", &readdata);
		if (readdata < 1)
		{
			break;
		}

		newnode = (Node*)malloc(sizeof(Node));
		newnode->data = readdata;
		newnode->next = NULL;

		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			tail->next = newnode;
		}
		tail = newnode;
	}
	printf("\n");

	printf("being inputed data is printing\n");
	if (head == NULL)
	{
		printf("no data\n");
	}
	else
	{
		cur = head;
		printf("%d ", cur->data);

		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	if (head == NULL)
	{
		return 0;
	}
	else
	{
		Node* delnode = head;
		Node* delnextnode = head->next;

		printf("delete %d\n", head->data);
		free(delnode);

		while (delnextnode != NULL)
		{
			delnode = delnextnode;
			delnextnode = delnextnode->next;

			printf("delete %d\n", delnode->data);
			free(delnode);
		}
	}
}
//20200109