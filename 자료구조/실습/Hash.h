#ifndef __HASH_H__
#define __HASH_H__
#define hash_table 100

struct person {
	int ssn;
	char name[10];
	char add[10];
};
int getSnn(struct person* pp);
void showinfo_person(struct person* pp);
struct person* makePersonData(int ssn, char* name, char* add);

enum SlotStatus{empty,deleted,inuse,null};
struct Slot{
	int key;
	struct person* value;
	enum SlotStatus status;
};

typedef int HashFunc(int key);
struct HashTable {
	struct Slot tb[hash_table];
	HashFunc* hf;
};
void TbInint(struct HashTable* pt, HashFunc* f);
void TbInsert(struct HashTable* pt, int key, struct person* value);
struct person* TbDelete(struct HashTable* pt, int key);
struct person* TbSearch(struct HashTable* pt, int key);


struct node_hash {
	struct Slot data;
	struct node_hash* next;
};
struct list_link_hash {
	int count;
	struct node_hash* Head;
};
struct HashTable_chaining {
	struct list_link_hash tb[hash_table];
	HashFunc* hfu;
};
void TbInint_ch(struct HashTable_chaining* hp, HashFunc* f);
void TbInsert_ch(struct HashTable_chaining* hp, int key, struct person* value);
struct person* TbDelete_ch(struct HashTable_chaining* hp, int key);
struct person* TbSearch_ch(struct HashTable_chaining* hp, int key);

int GetHashValue(int n);

#endif
//20200717-4,6,8