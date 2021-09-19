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

//Lptr이 가리키고 있는 리스트를 초기화
void Inint(listType* Lptr) {
	Lptr->Count = 0;
	Lptr->Head = NULL;
}

//Lptr이 가리키고 있는 리스트가 비어있으면 1, 아니면 0반환
int IsEmpty(listType* Lptr) {
	if (Lptr->Count == 0)return 1;
	else return 0;
}

//Lptr이 가리키고 있는 리스트에 있는 의미있는 값의 개수 반환
int Length(listType* Lptr) {
	return Lptr->Count;
}

//Lptr이 가리키고 있는 리스트의 Position번째에 Item값 삽입
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

//Lptr이 가리키고 있는 리스트의 Position번째 내용을 삭제
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

//Lptr이 가리키고 있는 리스트의 Position번째 내용을 Item내용으로 변경
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

//Lptr이 가리키고 있는 리스트의 Position번째 내용을 찾은 후 이를 반환
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
		printf("(1) 리스트 초기화\n");
		printf("(2) 리스트 공백여부 확인\n");
		printf("(3) 리스트 원소 등록\n");
		printf("(4) 리스트 원소 개수 확인\n");
		printf("(5) 리스트 원소 삽입\n");
		printf("(6) 리스트 원소 삭제\n");
		printf("(7) 리스트 원소 검색\n");
		printf("(8) 리스트 원소 변경\n");
		printf("(9) 프로그램 종료\n");
		printf("--- 기능선택:");
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
			printf("현재 리스트에 %d개 입력됨.\n", Length(&list));
			printf("X를 입력하면 삽입 종료\n");
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
			printf("리스트에 %d개 원소가 있습니다.\n", Length(&list));
			printf("Continue:");
			scanf("%c", &ch);
			if (ch == 'Y') goto AAA;
			else break;
		}
		else if (sel == 5) {//////////////////////////////////
			printf("몇번째? 정수?");
			scanf("%d %d", &loc, &num); getchar();
			Insert(&list, loc, num);
			printf("Continue:");
			scanf("%c", &ch);
			if (ch == 'Y') goto AAA;
			else break;
		}
		else if (sel == 6) {///////////////////////////////////////
			printf("몇번째?");
			scanf("%d", &loc); getchar();
			Delete(&list, loc);
			printf("Continue:");
			scanf("%c", &ch);
			if (ch == 'Y') goto AAA;
			else break;
		}
		else if (sel == 7) {/////////////////////////////////////
			printf("몇번째?");
			scanf("%d", &loc); getchar();
			num = Retrieve(&list, loc);
			printf("%d\n", num);
			printf("Continue:");
			scanf("%c", &ch);
			if (ch == 'Y') goto AAA;
			else break;
		}
		else if (sel == 8) {///////////////////////////////////////
			printf("몇번째? 변경할 정수값?");
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