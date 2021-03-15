#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

struct Node* head;

typedef struct List {
	struct Node* head;
	struct Node* tail;
	int size;
} List;
void printLinkedList(List* LinkedList);
int SearchInDoubleLinkedList(List* LinkedList,int key);