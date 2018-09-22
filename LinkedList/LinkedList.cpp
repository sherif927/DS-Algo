#include "stdafx.h"
#include <iostream>

using namespace std;

struct Node{
	int Data;
	Node* Next;
};

Node* Head;
int length = 0;

void Insert(int x);
void InsertAtHead(int x);
void InsertAt(int x, int i);
void Delete(int i);
void Print();

int main()
{
	int x;
	InsertAt(1, 0); // 1
	InsertAt(2, 0); // 2 1
	InsertAt(3, 1); // 2 3 1
	InsertAt(4, 2); // 2 3 4 1
	InsertAt(5, 4); // 2 3 4 1 5
	Print();

	Delete(1); //2 4 1 5
	Delete(0); //4 1 5
	Print();
	system("pause");
}

void Insert(int x)
{
	if(Head == NULL)
	{
		Head = new Node();
		Head->Data = x;
		Head->Next = NULL;
	}
	else
	{
		Node* temp = new Node();
		temp->Data = x;
		temp->Next = NULL;

		Node*trav = Head;
		while(trav->Next != NULL)
			trav = trav->Next;
		trav->Next = temp;
	} length++;
}

void InsertAtHead(int x)
{
	if(Head == NULL)
	{
		Head = new Node();
		Head->Data = x;
		Head->Next = NULL;
	}
	else
	{
		Node* temp = new Node();
		temp->Data = x;
		temp->Next = Head;

		Head = temp;
	} length++;
}

void InsertAt(int x,int index)
{
	if(index == 0)
		InsertAtHead(x);
	else
	{
		Node* trav = Head;
		Node* temp = new Node();
		temp->Data = x;

		for(int i = 0; i < index - 1;i++)
			trav = trav->Next;
		
		temp->Next = trav->Next;
		trav->Next = temp;

		length++;
	}
}

void Delete(int index)
{
	Node* trav = Head;
	Node* temp;

	if(index == 0)
	{
		temp = Head;
		Head = Head->Next;
	}
	else
	{
		for(int i = 0; i < index - 2; i++)
			trav = trav->Next;

		temp = trav->Next;
		trav->Next = trav->Next->Next;
	}
	delete(temp);
}

void Print()
{
	Node* trav = Head;
	while(trav != NULL)
	{
		cout << trav->Data<<" ";
		trav = trav->Next;
	} cout << endl;
}

