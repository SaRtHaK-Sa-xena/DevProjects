#include "Array.h"
#include <string>
#include <iostream>

using namespace std;


Bar *Array::ReturnRoot()
{
	return m_pRoot;
}

Array::Array()
{
	m_pRoot = nullptr;
}

Array::~Array()
{

}

Bar Array::CheckIfLost(Bar * Data, Bar * current, bool checkedTrue)
{
	Bar *returnValue = current;

	//current = current->getRight();
	if (returnValue->getData() == Data->getData())
	{
		checkedTrue = true;
		returnValue = current->getRight();//iterate forwards
	}
	else
	{
		checkedTrue = false;
	}

	return *returnValue;
	//
	//return current;
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

//----This Is Important-----------

//Bar * Array::CheckifWon(string value, Array *firstList, Array *secondList)
//{
//	Bar *current = nullptr; //to Find
//	
//	if (firstList->m_pRoot->getData() == secondList->m_pRoot->getData())
//	{
//		return true;
//		current = firstList->m_pRoot;
//		current = current->getRight();
//		current->getData();
//		//continue
//
//	}
//
//
//	current = m_pRoot;
//	if (current->getData() == value)
//	{
//		return current;
//	}
//	else
//	{
//		while (current->getRight() != nullptr)
//		{
//			current = current->getRight();
//			if (current->getData() == value)
//			{
//				return current;
//			}
//		}
//	}
//}
//
//Bar*Array::ReturnValue(string value)
//{
//	Bar*current = nullptr;
//	current = m_pRoot;
//
//	for()
//}

//----This Is Important-----------


void Array::insert(string a_nValue)
{
	/*int x;
	int y;
	int z;
	if (a_nValue == "RED")
	{
		x = 600;
		y = 150;
		z = 200;
	}
	else if (a_nValue == "BLUE");
	{
		x = 600;
		y = 150;
		z = 200;
	}*/



	if (m_pRoot == nullptr)
	{
		m_pRoot = new Bar(0,0,0,210,a_nValue);
	}
	else
	{
		Bar *current = nullptr;
		current = m_pRoot;

		//iterate towards the right until the right == null, then insert node there
		while (current != nullptr)
		{
			if (current->getRight() == nullptr)
			{
				current->setRight(new Bar(0,0,0,0,a_nValue)); //has position 0, and string colour of something
				//current->SetValue(-1);
				break;
			}
			current = current->getRight();
		}
	}
}

void Array::CheckIfWon(Bar *Data, bool checkedTrue)
{
	//Bar *current = nullptr;
	//Bar *iterator = m_pRoot;
	Bar* returnValue = m_pRoot;

	//current = current->getRight();
	if (returnValue->getData() == Data->getData())
	{
		checkedTrue = true;
		//returnValue = current->getRight();//iterate forwards
	}
	else
	{
		checkedTrue = false;
	}

	/*while (iterator->getRight != nullptr)
	{
		if (current->getData() == iterator->getData())
		{
			iterator = iterator->getRight();
		}
	}*/
}

//void Array::draw(aie::Renderer2D * renderer, Bar * selected)
//{
//	draw(renderer, m_pRoot, 640, 680, 640, selected);
//}


//==================Don't think Drawing is Need=============================
//void Array::draw(aie::Renderer2D * renderer, Bar *pNode, int x, int y, int horizontalSpacing, Bar * selected)
//{
	//horizontalSpacing /= 2;
	//if (pNode)
	//{
		//if (pNode->hasRight())
		//{
			//renderer->setRenderColour(1, 0, 0);
			//renderer->drawLine(x, y, x + horizontalSpacing, y - 80);
			//draw(renderer, pNode->getRight(), x + horizontalSpacing,
				//y - 80, horizontalSpacing, selected);
		//}
		//pNode->Draw(renderer, x, y, (selected == pNode));
	//}
//}
//==================Don't think Drawing is Need=============================


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
