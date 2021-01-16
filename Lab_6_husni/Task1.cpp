#include<iostream>
#include "Task1.h"
using namespace std;

bool DoublyLinkedList::add(Node* data, int pos)
{
	if (!data)
		return false;
	if (pos > nNodes)
		return false;
	else
	{
		if (pos == 0)
		{
			DoublyLinkedList* temp = new DoublyLinkedList;
			temp= this;
			data->setPrev(nullptr);
			data->setNext(temp->head);
			if (nNodes > 0)
				this->head->setPrev(data);
			this->head = data;
			nNodes =nNodes+1;
			return true;
		}
		if(0 < pos && pos < nNodes)
		{
			Node* nodeBeforeNew = nodeAt(pos-1);
			Node* nodeAfterNew = nodeAt(pos);
			nodeBeforeNew->setNext(data);
			nodeAfterNew->setPrev(data);
			data->setNext(nodeAfterNew);
			data->setNext(nodeBeforeNew);

			nNodes = nNodes + 1;
			return true;

		}
		else //tail node
		{
			Node* nodeBeforeNew = nodeAt(pos - 1);
			nodeBeforeNew->setNext(data);
			data->setNext(nullptr);
			data->setPrev(nodeBeforeNew);
			tail = data;
			nNodes = nNodes + 1;
			return true;

		}

	}
}


bool DoublyLinkedList::remove(int pos)
{
	if (pos > nNodes)
		return false;
	if (pos == 0)//head
	{
		Node* temp=new Node;
		temp=head;
		this->head = this->head->getNext();
		this->head->setPrev(nullptr);
		nNodes = nNodes - 1;
		temp->setNext(nullptr);
		temp->setPrev(nullptr);
		return true;	
	}
	if (0 < pos && pos < nNodes-1)
	{
		Node* deleteNode = this->nodeAt(pos);
		Node* nodeBeforeDeletedNode = deleteNode->getPrev();
		Node* nodeAfterDeletedNode = deleteNode->getNext();
		nodeBeforeDeletedNode->setNext(nodeAfterDeletedNode);
		nodeAfterDeletedNode->setPrev(nodeBeforeDeletedNode);
		delete deleteNode;
		nNodes = nNodes - 1;
		return true;
	}
	else//tail
	{
		Node* temp= nodeAt(pos-1);
		temp->setNext(nullptr);
		tail = temp;
		delete nodeAt(pos);
		nNodes = nNodes - 1;
		return true;
	}

}

bool DoublyLinkedList::replace(Node* old, Node* current)
{
	int pos = this->search(old);
	if (pos== -1)
		return false;
	if (!current)
		return false;
	else
	{
		this->remove(pos);
		this->add(current, pos);
		return true;
	}


}

int DoublyLinkedList::search(Node* data)
{
	DoublyLinkedList tempLinkedList;
	tempLinkedList= this;
	if (tempLinkedList.head->getData() == data->getData())
	{

		return 0;
	}
	if (tempLinkedList.head->getData() == data->getData() && tempLinkedList.head->getNext() != nullptr)
		return -1;
	else
	{
		while (tempLinkedList.head->getNext() != nullptr)
		{
			tempLinkedList.head = this->head->getNext();
			tempLinkedList.nNodes = (this->nNodes) - 1;
			tempLinkedList.search(data);
			
		}
	}
}


Node* DoublyLinkedList::nodeAt(int pos)
{
	if (pos > nNodes)
		return nullptr;
	else
	{
		DoublyLinkedList temp;
		temp= this;
		int index = 0;
		while (index< pos)
		{
			temp.head = temp.head->getNext();
			index = index + 1;

		}
		return temp.head;
		
	}
}

void DoublyLinkedList::display_forward()
{
	DoublyLinkedList temp;
	temp.head = this->head;
	temp.tail = this->tail;
	temp.nNodes = this->nNodes;

	int index = 0;
	cout << "The data in the Linked list From forward: ";
	while (index < nNodes)
	{
		if (0<index)
			cout << ",";
		cout << temp.head->getData();
		temp.head = temp.head->getNext();
		temp.nNodes = this->nNodes-1;
		index = index + 1;
	}
	cout << endl;
	
	
}

void DoublyLinkedList::display_backward()
{
	DoublyLinkedList temp;
	temp.head = this->head;
	temp.tail = this->tail;
	temp.nNodes = this->nNodes;

	int index = 0;
	cout<<"The data in the  Linked list From backward: ";
	while (nNodes-index>0)
	{
		if (0 < index)
			cout << ",";
		cout << temp.tail->getData();
		temp.tail = temp.tail->getPrev();
		temp.nNodes = this->nNodes - 1;
		index = index + 1;
	}
	cout << endl;
	
}

int DoublyLinkedList::size()
{
	return nNodes;
}

int Node::getData()
{
	return data;
}

void Node::setData(int data)
{
	this->data = data;
}

Node* Node::getNext()
{
	return this->next;
	/*if (next != nullptr)
		return next;
	else
		return nullptr;*/
}

void Node::setNext(Node* next)
{
	this->next = next;
}

Node* Node::getPrev()
{
	return prev;
}

void Node::setPrev(Node* prev)
{
	this->prev = prev;
}/*
int main()
{
	Node husni;
	Node husen;
	Node hayati;
	Node hanan;
	Node hayat;
	Node halima;
	Node hasenat;
	husni.setData(26);
	husen.setData(59);
	hanan.setData(30);
	halima.setData(56);
	hayati.setData(26);
	hayat.setData(20);
	hasenat.setData(16);

	DoublyLinkedList Family;
	Family.add(&husen, 0);
	cout<<Family.size()<<endl;
	Family.add(&halima, 1);
	Family.display_forward();
	Family.display_backward();
	Family.add(&hanan, 2);
	Family.display_forward();
	Family.remove(2);
	Family.display_forward();
	Family.remove(0);
	Family.display_forward();
	cout<<boolalpha<<Family.add(&hanan, 2)<<endl;
	cout << boolalpha << Family.add(&hanan, 1) << endl;
	Family.add(&husen, 0);
	Family.display_forward();
	Family.replace(&husen, &husni);
	Family.display_forward();
	//some of the method that i didnot call in in main are called when i called other method inside, forecample search 
	// method is called inside replace, etc...
}*/