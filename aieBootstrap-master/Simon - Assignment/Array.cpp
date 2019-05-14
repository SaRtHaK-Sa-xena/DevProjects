#include "Array.h"
#include <string>
#include <iostream>

using namespace std;


Array::Array()
{
	m_pRoot = nullptr;
}

Array::~Array()
{

}

bool Array::isEmpty() const
{
	if (m_pRoot == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Array::insert(string a_nValue)
{
	if (m_pRoot == nullptr)
	{
		m_pRoot = new Node(a_nValue);
	}
	else
	{
		Node *current = nullptr;
		current = m_pRoot;

		while (current != nullptr)
		{
			if (current->getRight() == nullptr)
			{
				current->SetRight(new Node(a_nValue));
				break;
			}
			current = current->getRight();
		}
	}
}

void Array::draw(aie::Renderer2D * renderer, Node * selected)
{
	draw(renderer, m_pRoot, 640, 680, 640, selected);
}

void Array::draw(aie::Renderer2D * renderer, Node *pNode, int x, int y, int horizontalSpacing, Node * selected)
{
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->hasRight())
		{
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x + horizontalSpacing, y - 80);
			draw(renderer, pNode->getRight(), x + horizontalSpacing,
				y - 80, horizontalSpacing, selected);
		}
		pNode->draw(renderer, x, y, (selected == pNode));
	}
}

//void Array::Insert(string Value)
//{
//	//Adds a whole bunch of values to an array
//	string arrayOfColours[4] = { "RED","BLUE","GREEN","YELLOW" };
//	Value = arrayOfColours[rand() % 4];
//	Node *node = new Node();
//	node->m_data = Value;
//	node->next = nullptr;
//	node->prev = nullptr;
//
//	if()
//}
