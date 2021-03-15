#include "LinkedList.h"

//Creates a new Node and returns pointer to it. 
struct Node* GetNewNode(int x) {
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
struct List* GetNewLink() {
	List* LinkedList = (List*)malloc(sizeof(List));

	LinkedList->head = NULL;
	LinkedList->tail = NULL;
	LinkedList->size = 0;
	return LinkedList;
}

bool  insert (struct List* myLinkedList,struct Node* myNode)
{
    if (myLinkedList->head==NULL)
    {
        myLinkedList->head=myNode;
        myLinkedList->tail=myNode;
        myNode->next=NULL;
        myNode->prev=NULL;
        return true;
    }
    else{
            myLinkedList->tail->next=myNode;
            myNode->prev=myLinkedList->tail;
            return true;
        }
        myLinkedList->size+=1;
} 
void printLinkedList(List* LinkedList) {
	struct Node* temp = LinkedList->head;
	printf("Forward: ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int SearchInDoubleLinkedList(List* LinkedList,int key) {
	struct Node* temp = LinkedList->head;
	while (temp != NULL) {
		if (temp->data == key) {
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}