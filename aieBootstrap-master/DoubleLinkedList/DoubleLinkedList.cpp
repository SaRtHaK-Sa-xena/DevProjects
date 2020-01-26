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
	}

	else
	{
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
		//if (a_value < Count())
		//{
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
	//create string to take input
	std::string inputFromUser;
	int position;

	if (!Empty())
	{
		//call for input
		std::cout << "Enter + if you wish to start from the beginning" << std::endl;
		std::cout << "Enter - if you wish to start from the end" << std::endl;
		std::cout << "Examples include: +2 (starts from beginning and deletes position 2)," << std::endl;
		std::cout << "-3 (starts from end and deletes position 3)" << std::endl;
		std::cin >> inputFromUser;
		
		if(inputFromUser[0] == '+')
		{
			//string without the plus or minus
			std::string stringWithoutThePlusOrMinus = inputFromUser.erase(0, 1);

			a_iterator = Begin();
			//convert to an integer
			position = std::stoi(stringWithoutThePlusOrMinus);


			if (Count() >= position)
			{
				if (position == Count())
				{
					PopBack();
				}
				else
				{
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
			}
		}
		else if(inputFromUser[0] == '-')
		{
			//string without the plus or minus
			std::string stringWithoutThePlusOrMinus = inputFromUser.erase(0, 1);


			a_iterator = End();
			position = std::stoi(stringWithoutThePlusOrMinus);
			
			if (Count() >= position)
			{
				if (position == Count())
				{
					PopFront();
				}
				//since iterator doesn't need to move
				else if (position == 0)
				{
					PopBack();
				}
				else
				{
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
		}
		else
		{
			std::cout << "Wrong Input Entered, You must enter + or - before entering a number" << std::endl;
			std::cout << "Please try again later..." << std::endl;
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
	//new Way Better Way
	Node *current = head;

	//check if first value is equal to that _value

	if (Count() == 0)
	{
		return;
	}

	else if (Count() == 1)
	{
		if (head->m_data == value)
		{
			head = nullptr;
			delete head;
		}
		else
		{
			return;
		}
	}

	else if (Count() > 1)
	{
			for (int j = 0; j < Count(); j++)
			{
				//check if current is equal to that of the value
				if (current->m_data == value)
				{
					if (current == head)
					{
						head = head->next;
						current = head->prev;
						delete current;
						break;
					}
					else if(current == tail)
					{
						//delete current;
						PopBack();

						break;
					}
					else
					{
						//create previous node of original current
						Node *prev_to_original_node = current->prev;

						//create next node of original current
						Node *next_to_original_node = current->next;

						//make the next of the original's previous to the original node 
						prev_to_original_node->next = next_to_original_node;

						//make the previo of the original's next to the original node 
						next_to_original_node->prev = prev_to_original_node;

						//make current null
						current = nullptr;
						delete current;

						break;
					}
				}
				else
				{
					current = current->next;
				}
			}
	}

	Node* check = head;

	//while (check != tail)
	for(int i = 0; i < Count();i++)
	{
		if (check->m_data == value)
		{
			Remove(value);
		}
		check = check->next;
	}
}

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
		//if one item in list
		if (Count() == 1)
		{
			tail = nullptr;
			delete tail;
		}
		else
		{
			Node *node = tail;
			node->prev->next = nullptr;
			tail = tail->prev;
			delete node;
		}
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
		//if only one item in list
		if (Count() == 1)
		{
			head = nullptr;
			delete head;
		}
		else 
		{
			Node *node = new Node();
			head = head->next;
			node = head->prev;
			delete node;
		}
	}
}
//===============DONE===================

//=================SORT=================
void DoubleLinkedList::Sort()
{
	//if count not equal to zero
	if (Count() != 0)
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