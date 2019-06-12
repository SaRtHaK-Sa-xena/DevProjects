#include "DynamicArrayClass.h"


DynamicArrayClass::DynamicArrayClass()
{
	root = nullptr;
}

DynamicArrayClass::~DynamicArrayClass()
{
}

void DynamicArrayClass::insert(int a_nValue)
{
	if (root == nullptr)
	{
		root = new Node(a_nValue);
	}
	else
	{
		Node* current = nullptr;
		current = root;

		//iterate towards the right until the right == null, then insert node there
		while (current != nullptr)
		{
			if (current->getRight() == nullptr)
			{
				current->setRight(new Node(a_nValue)); //has position 0, and string colour of something
				//current->SetValue(-1);
				break;
			}
			current = current->getRight();
		}
	}
}

void DynamicArrayClass::remove(int a_nValue)
{
	/*Node* node = root;
	while (node->getData() != a_nValue)
	{
		node = node->getRight();
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
	}*/


	Node *current = root;

	while (current->getRight() != nullptr)
	{
		current = current->getRight();
		if (current->getData() == a_nValue)
		{
			current->getLeft->setRight(current->getRight());
			delete current;
		}
	}
}
