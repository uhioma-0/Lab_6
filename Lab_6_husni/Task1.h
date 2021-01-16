#include<iostream>
using namespace std;
class Node
{
	int data;
	Node* next;
	Node* prev;
public:
	int getData();
	void setData(int data);
	Node* getNext();
	void setNext(Node* next);
	Node* getPrev();
	void setPrev(Node* prev);
	Node* operator=(Node* r)
	{
		data = r->getData();
		next = r->getNext();
		prev= r->getPrev();
		return this;
	}
	~Node()
	{
		next =nullptr;
		prev=nullptr;
	}
};
class DoublyLinkedList: public Node
{
	Node* head;
	Node* tail;
	int nNodes;
public:
	bool add (Node *data, int pos);
	bool remove(int pos);
	bool replace(Node *old, Node *current);
	int search(Node *data) ;
	Node* nodeAt(int pos);
	void display_forward();
	void display_backward();
	int size();
	DoublyLinkedList* operator=(DoublyLinkedList* r)
	{
		head = r->head;
		tail = r->tail;
		nNodes = r->nNodes;
		return this;
	}

	DoublyLinkedList()
	{
		nNodes = 0;
		head = nullptr;
		tail = nullptr;
	}
/*~ DoublyLinkedList()
	{
		nNodes = 0;
		delete head;
		delete tail;
	}*/

};
