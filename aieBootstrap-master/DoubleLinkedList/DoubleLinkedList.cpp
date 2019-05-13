#include "pch.h"
#include "DoubleLinkedList.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList()
{
	head = nullptr;
	tail = nullptr;
	m_size = 5;
}

DoubleLinkedList::~DoubleLinkedList()
{
}

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



//======================SEEMS DONE===============
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
//======================SEEMS DONE===============


void DoubleLinkedList::InsertAfter(Node * prev_node, int a_value)
{
	Node *node = nullptr;
	//node = prev_node;
	/*node->next = prev_node;
	prev_node->prev = node;*/
	Node *Node2 = prev_node->next;

	prev_node->next = node;
	node->prev = prev_node;
	node->next = Node2;
	Node2->prev = node;
	node->m_data = a_value;
}

DoubleLinkedList::Iterator DoubleLinkedList::Begin()
{
	return Iterator();
}

DoubleLinkedList::Iterator DoubleLinkedList::End()
{
	return Iterator();
}

Node * DoubleLinkedList::First()
{
	return nullptr;
}

Node * DoubleLinkedList::Last()
{
	return nullptr;
}

int DoubleLinkedList::Count()
{
	return 0;
}

void DoubleLinkedList::Erase(Iterator a_iterator)
{
}

void DoubleLinkedList::Remove(int value)
{
}

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

bool DoubleLinkedList::Empty()
{
	return false;
}

void DoubleLinkedList::Clear()
{
}
