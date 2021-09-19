#include<stdio.h>
#include<stdlib>
#define MAX 100

typedef struct nodeRecord {
	int Data;
	nodeRecord* Next;
}node;

typedef node* Nptr;
typedef struct {
	int Count;
	Nptr Head;
}listType;

//Lptr�� ����Ű�� �ִ� ����Ʈ�� �ʱ�ȭ
void Inint(listType* Lptr) {
	Lptr->Count = 0;
	Lptr->Head = NULL;
}

//Lptr�� ����Ű�� �ִ� ����Ʈ�� ��������� 1, �ƴϸ� 0��ȯ
int IsEmpty(listType* Lptr) {
	if (Lptr->Count == 0)return 1;
	else return 0;
}

//Lptr�� ����Ű�� �ִ� ����Ʈ�� �ִ� �ǹ��ִ� ���� ���� ��ȯ
int Length(listType* Lptr) {
	return Lptr->Count;
}

//Lptr�� ����Ű�� �ִ� ����Ʈ�� Position��°�� Item�� ����
void Insert(listType* Lptr, int Position, int Item) {
	if ((Position > (Lptr->Count + 1)) || (Position < 1)) {
		printf("Position out of Range\n");
	}
	else {
		Nptr p = (node*)malloc(sizeof(node));
		p->Data = Item;
		if (Position == 1) {
			p->Next = Lptr->Head;
			Lptr->Head = p;
		}
		else {
			Nptr Temp = Lptr->Head;
			for (int i = 1;i < (Position - 1); i++) {
				Temp = Temp->Next;
			}
			p->Next = Temp->Next;
			Temp->Next = p;
		}
		Lptr->Count += 1;
	}
}

//Lptr�� ����Ű�� �ִ� ����Ʈ�� Position��° ������ ����
void Delete(listType* Lptr, int Position) {
	if (IsEmpty(Lptr)) {
		printf("list empty\n");
	}
	else if ((Position > (Lptr->Count + 1)) || (Position < 1)) {
		printf("Position out of Range\n");
	}
	else {
		if (Position == 1) {
			Nptr p = Lptr->Head;
			Lptr->Head = Lptr->Head->Next;
		}
		else {
			Nptr Temp = Lptr->Head;
		    for (int i = 1;i < (Position - 1);i++) {
			    Temp = Temp->Next;
		    }
		    Nptr p = Temp->Next;
		    Temp->Next = p->Next;
		}
		Lptr->Count -= 1;
		free(p);
	}
}////////////////////////////////////////////////////////////////////////////////

//Lptr�� ����Ű�� �ִ� ����Ʈ�� Position��° ������ Item�������� ����
void Update(listType* Lptr, int Position, int Item) {
	if (IsEmpty(Lptr)) {
		printf("list empty\n");
	}
	else if ((Position > (Lptr->Count + 1)) || (Position < 1)) {
		printf("Position out of Range\n");
	}
	else {
		Lptr->Data[Position - 1] = Item;
	}
}

//Lptr�� ����Ű�� �ִ� ����Ʈ�� Position��° ������ ã�� �� �̸� ��ȯ
int Retrieve(listType* Lptr, int Position) {
	if (IsEmpty(Lptr)) {
		printf("list empty\n");
	}
	else if ((Position > (Lptr->Count + 1)) || (Position < 1)) {
		printf("Position out of Range\n");
	}
	else {
		return Lptr->Data[Position - 1];
	}
}

int main(void) {
	listType list;
	Inint(&list);
	int sel, em, innum;
	int num, loc;
	char ch;
	while (1) {
	AAA:printf("\n");
		printf("(1) ����Ʈ �ʱ�ȭ\n");
		printf("(2) ����Ʈ ���鿩�� Ȯ��\n");
		printf("(3) ����Ʈ ���� ���\n");
		printf("(4) ����Ʈ ���� ���� Ȯ��\n");
		printf("(5) ����Ʈ ���� ����\n");
		printf("(6) ����Ʈ ���� ����\n");
		printf("(7) ����Ʈ ���� �˻�\n");
		printf("(8) ����Ʈ ���� ����\n");
		printf("(9) ���α׷� ����\n");
		printf("--- ��ɼ���:");
		scanf("%d", &sel);
		getchar();
		if (sel == 1) {////////////////////////////////
			Inint(&list);
			printf("Continue:");
			scanf("%c", &ch);
			if (ch == 'Y') goto AAA;
			else break;
		}
		else if (sel == 2) {/////////////////////////////////
			em = IsEmpty(&list);
			if (em == 1)printf("list empty\n");
			else printf("list not empty\n");
			printf("Continue:");
			scanf("%c", &ch);
			if (ch == 'Y') goto AAA;
			else break;
		}
		else if (sel == 3) {//////////////////////////////
			printf("���� ����Ʈ�� %d�� �Էµ�.\n", Length(&list));
			printf("X�� �Է��ϸ� ���� ����\n");
			while (1) {
				scanf("%d", &innum);  getchar();
				if (innum == 0)break;
				Insert(&list, Length(&list) + 1, innum);
			}
			printf("Continue:");
			scanf("%c", &ch);
			if (ch == 'Y') goto AAA;
			else break;
		}
		else if (sel == 4) {/////////////////////////////
			printf("����Ʈ�� %d�� ���Ұ� �ֽ��ϴ�.\n", Length(&list));
			printf("Continue:");
			scanf("%c", &ch);
			if (ch == 'Y') goto AAA;
			else break;
		}
		else if (sel == 5) {//////////////////////////////////
			printf("���°? ����?");
			scanf("%d %d", &loc, &num); getchar();
			Insert(&list, loc, num);
			printf("Continue:");
			scanf("%c", &ch);
			if (ch == 'Y') goto AAA;
			else break;
		}
		else if (sel == 6) {///////////////////////////////////////
			printf("���°?");
			scanf("%d", &loc); getchar();
			Delete(&list, loc);
			printf("Continue:");
			scanf("%c", &ch);
			if (ch == 'Y') goto AAA;
			else break;
		}
		else if (sel == 7) {/////////////////////////////////////
			printf("���°?");
			scanf("%d", &loc); getchar();
			num = Retrieve(&list, loc);
			printf("%d\n", num);
			printf("Continue:");
			scanf("%c", &ch);
			if (ch == 'Y') goto AAA;
			else break;
		}
		else if (sel == 8) {///////////////////////////////////////
			printf("���°? ������ ������?");
			scanf("%d %d", &loc, &num); getchar();
			Update(&list, loc, num);
			printf("Continue:");
			scanf("%c", &ch);
			if (ch == 'Y') goto AAA;
			else break;
		}
		else if (sel == 9) {/////////////////////////////////
			break;
		}
	}
}