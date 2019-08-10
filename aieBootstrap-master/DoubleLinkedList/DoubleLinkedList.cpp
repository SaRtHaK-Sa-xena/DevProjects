#include "pch.h"
#include "DoubleLinkedList.h"
#include <iostream>
#include <string>

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

//=============PRINTS OUT LIST================
void DoubleLinkedList::Print()
{

	if (!Empty())
	{
		Node *head = this->head;
		int i = 1;
		while (head)
		{
			std::cout << i << ": " << head->m_data << std::endl;
			head = head->next;
			i++;
		}
	}

	else
	{
		std::cout << "List is already Empty..." << std::endl;
	}	
}
//=============DONE===========================


//===========MOVES VALUE TO FIRST=============
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
//=============DONE===========================



//================MOVES VALUE TO END==========
void DoubleLinkedList::PushBack(int a_value)
{

	Node *node = new Node();
	node->m_data = a_value;

	if (Empty())
	{
		//========original==========
		node->next = head;
		head = node;
		//========original==========

		//node = tail;
		//head->next = tail;
		//tail->prev = head;
	}

	else
	{
		//int n = Count();
			//=======ORIGINAL=====
			node->prev = tail;
			tail->next = node;
			tail = node;
		//=================
		
	}
}
//======================DONE==================


//=========INSERTS AFTER A NODE=============
void DoubleLinkedList::InsertAfter(Node * prev_node, int a_value)
{
	if (!Empty())
	{
		Node *node = new Node();
		Node *Node2 = prev_node->next;

		if (Node2 == nullptr)
		{
			prev_node->next = node;
			node->prev = prev_node;
			node->m_data = a_value;
		}
		else
		{
			prev_node->next = node;
			node->prev = prev_node;
			node->next = Node2;
			Node2->prev = node;
			node->m_data = a_value;
		}
	}
	else
	{
		std::cout << "List Already Empty" << std::endl;
	}
}
//=============DONE=========================

//========SETS ITERATOR TO BEGINNING========
DoubleLinkedList::Iterator DoubleLinkedList::Begin()
{
	if (!Empty())
	{
		return head;
	}
	else
	{
		std::cout << "List Already Empty" << std::endl;
	}
}
//=============DONE=========================


//===========SETS ITERATOR TO END===========
DoubleLinkedList::Iterator DoubleLinkedList::End()
{
	if (!Empty())
	{
		return tail;
	}
	else
	{
		std::cout << "List Already Empty" << std::endl;
	}
	
}
//=============DONE=========================


//============RETURNS FIRST ELEMENT=========
Node * DoubleLinkedList::First()
{
	if (!Empty())
	{
		return head;
	}
	else
	{
		std::cout << "List Already Empty" << std::endl;
	}
	
}
//============DONE==========================


//============RETURNS LAST ELEMENT==========
Node * DoubleLinkedList::Last()
{
	if (!Empty())
	{
		return tail;
	}
	else
	{
		std::cout << "List Already Empty" << std::endl;
	}
	
}
//============DONE==========================


//=========COUNTS ALL ELEMENTS==============
int DoubleLinkedList::Count()
{
	if(!Empty())
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
	else
	{
		std::cout << "List Already Empty" << std::endl;
		return 0;
	}

}
//============DONE==========================


//=============ERASE BY ITERATOR============
void DoubleLinkedList::Erase(Iterator a_iterator)
{
	//DoubleLinkedList *doubleList = new DoubleLinkedList();
	
	
	if (!Empty())
	{
		std::string choice;
		std::cout << "From First (BEGIN) or Last (END)" << std::endl;
		std::cin >> choice;
		if (choice == "BEGIN")
		{
			a_iterator = Begin();
			int position;
			int NumberToBeInserted;
			std::cout << "What Position to Delete From The Top: " << std::endl;
			std::cin >> position; //increment forward by...
			for (int i = 0; i < position - 1; i++)
			{
				a_iterator++;//moves iterator forward
			}
			Node *node = nullptr;
			node = a_iterator.GetNode();
			Node *newNode = nullptr;
			newNode = node->prev;
			newNode->next = node->next;
			delete node;
		}
		else
		{
			a_iterator = End();
			int position;
			int NumberToBeInserted;
			std::cout << "What Position to Delete From The Bottom: " << std::endl;
			std::cin >> position; //increment forward by...
			for (int i = 0; i < position - 1; i++)
			{
				a_iterator--;//moves iterator forward
			}
			Node *node = nullptr;
			node = a_iterator.GetNode();
			Node *newNode = nullptr;
			newNode = node->prev;
			newNode->next = node->next;
			delete node;
		}
	}
	else
	{
		std::cout << "List Already Empty" << std::endl;
	}

	
}
//=============DONE=========================


//===============REMOVE VALUE============
void DoubleLinkedList::Remove(int value)
{

	//===================================TEST 2===============
	Node* node = head;

	while (node->m_data != value)
	{
		node = node->next;
	}

	Node* temp = node->prev;

	node = node->next;
	if (node->m_data != value)
	{
		temp->next = node;
		temp = node;
		while (node->m_data != value)
		{
			node = node->next;
		}

		temp->next = node->next;
		delete node;
	}
	else
	{
		while (node->m_data != value)
		{
			node = node->next;
		}

		temp->next = node->next;
		delete node;
	}
	
	//===================================TEST 2===============


	//========================TEST 1========================
	//Node* node = head;

	//while (node->m_data != value)
	//{
	//	node = node->next;
	//}
	////node = value
	//Node* temp = node->prev;

	//node = node->next;
	//while (node->m_data != value)
	//{
	//	//temp->next = node;
	//	node = node->next;
	//	//temp = node;
	//}
	////Node* temp2 = node->next;
	//temp->next = node->next;
	//delete node;
	//========================TEST 1========================



	//=======================ORIGNAL=========================
	//if (!Empty())
	//{
	//	Node* node = head;

	//	while (node->m_data != value)
	//	{
	//		node = node->next;
	//	}
	//	Node* temp = nullptr;
	//	temp = node->prev;
	//	temp->next = node->next;

	//	if(temp->next->m_data == value)
	//	{
	//		temp->next = node->next->next;
	//		//temp = temp->next;
	//	}
	//	delete node;
	//}
	//else
	//{
	//	std::cout << "List AlreadY Empty" << std::endl;
	//}
	//=======================ORIGNAL=========================

}
	// ======================NEW ATTEMPT==
	//if (!Empty())
	//{
	//	Node* node = head;
	//	int j = 0;
	//	int length = Count();
	//	for (int i = 0; i < length; i++)
	//	{
	//		if (node->m_data == value)
	//		{
	//			j++;
	//		}
	//		node = node->next;
	//	}
	//	for (int i = 0; i < j; i++)
	//	{
	//		while (node->m_data != value)
	//		{
	//			node = node->next;
	//		}
	//		Node *temp = nullptr;
	//		temp = node->prev;
	//		temp->next = node->next;
	//		delete node;
	//	}
	//}
	//else
	//{
	//	std::cout << "Empty List..." << std::endl;
	//}
		/*if (node->m_data == value)
		{
			i++;
		}
		while (node->m_data != value)
		{

		}*/
//===============DONE===================


//===============REMOVES LAST VALUE=====
void DoubleLinkedList::PopBack()
{
	if (head == nullptr)
	{
		std::cout << "List Is Empty" << std::endl;
		return;
	}
	else
	{
		Node *node = tail;
		node->prev->next = nullptr;
		tail = tail->prev;
		//node = nullptr;
		delete node;

	}
}
//===============DONE===================


//=============REMOVES FIRST VALUE======
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

//=================SORT=================
void DoubleLinkedList::Sort()
{

	//==============Bubble Sort Used=============================
	Node* node = head;
	Node* nodeRight = node->next;

	int temp;
	int temp2;

	bool swap = false;

	while (node->next != nullptr)
	{
		if (swap)
		{
			node = head;
			nodeRight = node->next;
		}


		if (node->m_data > nodeRight->m_data)
		{
			temp = node->m_data;
			temp2 = nodeRight->m_data;

			//=========SWAP=============
			node->m_data = temp2;
			nodeRight->m_data = temp;
			//=========SWAP=============
			swap = true;
		}
		else
		{
			node = node->next;
			nodeRight = node->next;
			swap = false;
		}
	}
	//==============Bubble Sort Used=============================
}
//=================SORT=================


//==========CHECKS IF LIST EMPTY========
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


//==========CLEARS ENTIRE LIST==========
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
		std::cout << "List Already Empty" << std::endl;
	}
	
}
//===============DONE===================