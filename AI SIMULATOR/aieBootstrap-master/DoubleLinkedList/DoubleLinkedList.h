#pragma once
#include "Node.h"
class DoubleLinkedList
{
public:
	DoubleLinkedList();
	~DoubleLinkedList();

	class Iterator
	{
	public:
		Iterator() {};
		Iterator(Node *a_node) : m_node(a_node) {}

		// By using the overloads for operators, 
		// you can make the following:

		//transitions node forward
		void operator++() 
		{ 
			m_node = m_node->next; 
		}
		//===============================


		//transitions node of int forward
		void operator++(int) 
		{ 
			m_node = m_node->next;
		}
		//===============================

		//transitions node backward
		void operator-() 
		{ 
			m_node = m_node->prev;
		}
		//===============================

		//transitions node of int backward
		void operator--(int) 
		{ 
			m_node = m_node->prev; 
		}
		//===============================

		//====returns current node data==
		int &operator *() 
		{ 
			return m_node->m_data;
		}
		//===============================

		//returns the referenced node's data
		int *operator->() 
		{ 
			return &m_node->m_data;
		}
		//===============================

		//returns true if node is equal to NODE node
		bool operator == (const Iterator &rhs) 
		{ 
			return m_node == rhs.m_node;
		}
		//===============================

		//returns true if node not equal to NODE node
		bool operator != (const Iterator &rhs) 
		{ 
			return m_node != rhs.m_node;
		}
		//===============================

		//returns current Node Instance
		Node *GetNode()
		{ 
			return m_node;
		}
		//===============================

		//makes initial node = nullptr
		Node *m_node = nullptr;
	};

	//Functions
	void Print();

	void PushFront(int a_value); // Add a new value to the front of the list--DONE
	void PushBack(int a_value); // Add a new value tot the end of the list--DONE

	//Add a new value after the specified iterator location
	void InsertAfter(Node* prev_node, int a_value);

	Iterator Begin(); //return an iterator the the first element
	Iterator End(); // return an iterator the last element. HINT: nullptr

	Node* First(); // Return the first element by value, assert if no element
	Node* Last(); // Return the last element by value, assert if no element

	int Count(); // Return how many elements exist in the list

	void Erase(Iterator a_iterator); // Remove an element by it's iterator
	void Remove(int value); //Remove all elements with matching values

	void PopBack(); // Remove the last element in the list --DONE
	void PopFront(); // Remove the first element in the list --DONE


	void Sort();

	//Return a boolean, true if the list is empty, false otherwise
	bool Empty(); // --DONE

	void Clear(); // Remove all elements from the list


private:
	Node *head, *tail;
	int m_size;

};