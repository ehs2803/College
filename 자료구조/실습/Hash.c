#include<stdio.h>
#include "Hash.h"

int getSnn(struct person* pp) {
	return pp->ssn;
}
void showinfo_person(struct person* pp) {
	printf("주민등록번호: %d\n", pp->ssn);
	printf("이름: %s\n", pp->name);
	printf("주소: %d\n", pp->add);
}
struct person* makePersonData(int ssn, char* name, char* add) {
	struct person* newp = malloc(sizeof(struct person));
	newp->ssn = ssn;
	strcpy(newp->name, name);
	strcpy(newp->add, add);
	return newp;
}

void TbInint(struct HashTable* pt, HashFunc* f) {
	int i;
	for (i = 0;i < hash_table;i++) {
		(pt->tb[i]).status = empty;
	}
	pt->hf = f;
}
void TbInsert(struct HashTable* pt, int key, struct person* value) {
	int hv = pt->hf(key);
	pt->tb[hv].value = value;
	pt->tb[hv].key = key;
	pt->tb[hv].status = inuse;
}
struct person* TbDelete(struct HashTable* pt, int key) {
	int hv = pt->hf(key);

	if ((pt->tb[hv]).status != inuse) {
		return NULL;
	}
	else {
		(pt->tb[hv]).status = deleted;
		return (pt->tb[hv]).value;
	}
}
struct person* TbSearch(struct HashTable* pt, int key) {
	int hv = pt->hf(key);

	if ((pt->tb[hv]).status != inuse) {
		return NULL;
	}
	else {
		return (pt->tb[hv]).value;
	}
}

int GetHashValue(int n) {
	return n % hash_table;
}

void TbInint_ch(struct HashTable_chaining* hp, HashFunc* f) {
	int i;
	for (i = 0;i < hash_table;i++) {
		hp->tb[i].Head = NULL;
		hp->tb[i].count = 0;
	}
	hp->hfu = f;
}
void TbInsert_ch(struct HashTable_chaining* hp, int key, struct person* value) {
	int hv = hp->hfu(key);
	struct Slot ns = { key,value,null };
	struct node_hash* temp = malloc(sizeof(struct node_hash));
	temp->data = ns;

	temp->next = hp->tb[hv].Head;
	hp->tb[hv].Head = temp;
	
	hp->tb[hv].count++;
}
struct person* TbDelete_ch(struct HashTable_chaining* hp, int key) {
	int hv = hp->hfu(key);

	if (hp->tb[hv].Head == NULL) {
		printf("삭제할 데이터가 없습니다.\n");
	}
	else {
		struct node_hash* temp = hp->tb[hv].Head;
		if (temp->data.key == key) {
			struct person* tp = temp->data.value;
			temp = NULL;
			free(temp);
			return tp;
		}
		else {
			while ((temp != NULL) && (temp->next->data.key != key)) {
				temp = temp->next;
			}
			if (temp == NULL) {
				printf("삭제할 데이터가 없습니다.\n");
			}
			else {
				struct node_hash* temp2 = temp->next;
				temp->next = temp2->next;
				struct person* tp = temp2->data.value;
				free(temp2);
				return tp;
			}
		}
	}
}
struct person* TbSearch_ch(struct HashTable_chaining* hp, int key) {
	int hv = hp->hfu(key);

	if (hp->tb[hv].Head == NULL) {
		printf("해당 데이터가 없습니다.\n");
	}
	else {
		struct node_hash* temp = hp->tb[hv].Head;
		if (temp->data.key == key) {
			struct person* tp = temp->data.value;	
			return tp;
		}
		else {
			while ((temp != NULL) && (temp->data.key != key)) {
				temp = temp->next;
			}
			if (temp == NULL) {
				printf("찾는 데이터가 없습니다.\n");
			}
			else {
				struct person* tp = temp->data.value;
				return tp;
			}
		}
	}
}
//20200717-4,6,8