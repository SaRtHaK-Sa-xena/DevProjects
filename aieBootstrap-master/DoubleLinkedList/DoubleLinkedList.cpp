#include "pch.h"
#include "DoubleLinkedList.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList()
{
	head = nullptr;
	tail = nullptr;
	m_size = 0;
}

DoubleLinkedList::~DoubleLinkedList()
{
}





//void DoubleLinkedList::Fill(int a_data)
//{
//	if (head == nullptr)
//	{
//		Node *node = new Node(); //Create 
//		node->m_data = a_data; //Make it's data equal to entered INT
//		head->m_data = node->m_data; //make that the head
//		
//	}
//	else
//	{
//		Node *node = new Node();
//		node->m_data = a_data;
//		head->next = node;
//		
//
//	}
//	Node *node = new Node();
//	node->m_data = a_data;
//	head->m_data = node->m_data;
//	head = head->next;
//	tail = node;
//}

//=============DONE===========================
void DoubleLinkedList::Print()
{
	Node *head = this->head;
	int i = 1;
	while (head)
	{
		std::cout << i << ": " << head->m_data << std::endl;
		head = head->next;
		i++;
	}
	

	//node->prev = head;
	//node->next = node;
	//head->m_data = node->m_data;
	//std::cout << head->m_data;
}
//=============DONE===========================


//=============DONE===================
void DoubleLinkedList::PushFront(int a_value)
{
	Node *node = new Node();
	node->m_data = a_value;
	node->next = nullptr;
	node->prev = nullptr;

	if (head == nullptr)
	{
		head = node;
		tail = node;
		std::cout << "Head is Empty" << "\nStoring in Head" << std::endl;
	}
	else
	{
		node->next = head;
		head->prev = node;
		head = node;
	}
}
//=============DONE===================



//======================DONE===============
void DoubleLinkedList::PushBack(int a_value)
{
	Node *node = new Node();
	node->m_data = a_value;
	if (Empty())
	{
		node->next = head;
		head = node;
	}
	else
	{
		/*Node *other = head;
		while (other->next != nullptr)
		{
			other = other->next;
		}*/
		node->prev = tail;
		tail->next = node;
		tail = node;
		
	}
}
//======================DONE===============


//=============DONE===================
void DoubleLinkedList::InsertAfter(Node * prev_node, int a_value)
{
	Node *node = new Node();
	Node *Node2 = prev_node->next;

	prev_node->next = node;
	node->prev = prev_node;
	node->next = Node2;
	Node2->prev = node;
	node->m_data = a_value;
}
//=============DONE===================

//=============DONE==================
DoubleLinkedList::Iterator DoubleLinkedList::Begin()
{
	return head;
}
//=============DONE==================


//=============DONE==================
DoubleLinkedList::Iterator DoubleLinkedList::End()
{
	return tail;
}
//=============DONE==================


//============DONE==============
Node * DoubleLinkedList::First()
{
	return head;
}
//============DONE==============


//============DONE==============
Node * DoubleLinkedList::Last()
{
	return tail;
}
//============DONE==============


//============DONE==============
int DoubleLinkedList::Count()
{
	int i = 0;
	Node* node = head;
	while (node->next != nullptr)
	{
		node = node->next;
		i++;
	}
	i++;
	return i;
}
//============DONE==============


//=============WDONE==================
void DoubleLinkedList::Erase(Iterator a_iterator)
{
	int position;
	int NumberToBeInserted;
	std::cout << "What Position to Delete: " << std::endl;
	std::cin >> position;
	for (int i = 0; i < position - 1; i++)
	{
		a_iterator++;
	}
	Node *node = nullptr;
	node = a_iterator.GetNode();
	Node *newNode = nullptr;
	newNode = node->prev;
	newNode->next = node->next;
	delete node;
}
//=============DONE==================


//===============DONE===================
void DoubleLinkedList::Remove(int value)
{
	Node* node = head;
	while (node->m_data != value)
	{
		node = node->next;
	}
	Node* temp = nullptr;
	temp = node->prev;
	temp->next = node->next;
	delete node;

}
//===============DONE===================


//===============DONE===================
void DoubleLinkedList::PopBack()
{
	if (head == nullptr)
	{
		std::cout << "List Is Empty" << std::endl;
		return;
	}
	else
	{
		/*Node *node = head;
		while (node->next != nullptr)
		{
			node = node->next;
		}
		tail = node->prev;
		tail->next = nullptr;
		tail->prev = node->prev->prev;
		delete node;*/

		Node *node = tail;
		node->prev->next = nullptr;
		tail = tail->prev;
		//node = nullptr;
		delete node;

	}
}
//===============DONE===================


//===============DONE===================
void DoubleLinkedList::PopFront()
{
	if (head == nullptr)
	{
		std::cout << "List Is Empty" << std::endl;
		return;
	}
	else
	{
		Node *node = new Node();
		head = head->next;
		node = head->prev;
		delete node;

	}
}
//===============DONE===================


//===============DONE===================
bool DoubleLinkedList::Empty()
{
	if (head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
//===============DONE===================


//===============DONE===================
void DoubleLinkedList::Clear()
{
	if (!Empty())
	{
		head = nullptr;
		tail = nullptr;
		delete head;
		delete tail;
		std::cout << "List Cleared... " << std::endl;
	}
	else
	{
		std::cout << "List AlreadY Empty" << std::endl;
	}
	
}
//===============DONE===================