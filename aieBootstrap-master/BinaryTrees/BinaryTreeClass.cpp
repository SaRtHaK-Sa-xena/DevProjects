#include "BinaryTreeClass.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree()
{
	m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
}

bool BinaryTree::isEmpty() const
{
	if (m_pRoot == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
	//return false;
}


//======DONE=========================================
void BinaryTree::insert(int a_nValue)
{
	if (m_pRoot == nullptr) 
	{
		cout << "It is is empty..." << endl;
		cout << "storing in the root" << endl;

		m_pRoot = new TreeNode(a_nValue);
	}
	else
	{
		//TreeNode *parent = nullptr;
		TreeNode *current = nullptr;
		current = m_pRoot; //current will equal m_pRoot //use &
		
		
		//Save-1				   
		while (current != nullptr)
		{
			if (a_nValue < current->getData()) //< m_pRoot->getData()) //if 2 < 5 [2 equal to current] --- [5 equal to root]
			{
				//current->setData(a_nValue);
				if (current->getLeft() == nullptr)
				{
					current->setLeft(new TreeNode(a_nValue));
					break;
				}
				current = current->getLeft();
				//Save-2
			
			}
			
			if (a_nValue > current->getData())//(current->getData() > m_pRoot->getData())//
			{
				//parent->setRight(current); //setting parent's child value to current, which is a_nValue
				//current->setData(a_nValue);
				if (current->getRight() == nullptr)
				{
					current->setRight(new TreeNode(a_nValue));
					break;
				}
				current = current->getRight();
			}
			
			if (a_nValue == current->getData())
			{
				cout << "Value is already in the tree" << endl;
				return;
			}
		}
		//Save-3
	}
}
//======DONE=========================================


void BinaryTree::remove(int a_nValue)
{
	TreeNode *current = nullptr;
	TreeNode *parent = nullptr;
	findNode(a_nValue, &current, &parent);
	//m_pRoot->setData(a_nValue);
	current = m_pRoot;
	if (current->hasRight())
	{
		//parent = current;
		while (current->getLeft() != nullptr)
		{
			if (a_nValue < current->getData())
			{
				parent = current;
				if (parent->getLeft() == nullptr && parent->getRight() == nullptr)
				{
					//Equals to NullPointer
					delete current;
					break;
				}
				current = parent->getLeft(); //current will now equal parent
				//parent->getLeft() = current->getRight();
				break;
			}
		}
		

		//current = parent->getRight();
		//parent->setLeft(current->getLeft());
		//delete current;
	}
	delete current;
	//if(a_nValue < current->getData())
	//	TreeNode *copy = nullptr;
	//	copy = current;
	//	parent->getData();
	//	//if you are deleting the parent's left node
	//	if (input == 1)
	//	{
	//		parent->setLeft(copy->getLeft());
	//	}
	//	else
	//	{
	//		parent->setRight(copy->getRight());
	//	}


	//}
	//else
	//{
	//	int input_again = 0;
	//	cin >> input_again;
	//	if (input_again == 1)
	//	{
	//		parent->setLeft(current->getLeft());
	//	}
	//	else if (input_again = 2)
	//	{
	//		parent->setRight(current->getRight());
	//	}
	//	else
	//	{
	//		current->setLeft(m_pRoot);
	//	}
	//	
	//}
}

//Sort of Works
TreeNode * BinaryTree::find(int a_nValue)
{
	TreeNode *current = new TreeNode(a_nValue);
	TreeNode *parent = new TreeNode(a_nValue);
	findNode(a_nValue, &current, &parent);
	return current;
}

void BinaryTree::draw(aie::Renderer2D * renderer, TreeNode * selected)
{
	//if (selected == nullptr)
	//{
	//	return;
	//}
	draw(renderer, m_pRoot, 640, 680, 640, selected);
}

//Sort of Works
bool BinaryTree::findNode(int a_nSearchValue, TreeNode ** ppOutNode, TreeNode ** ppOutParent)
{
	TreeNode *current = new TreeNode(a_nSearchValue);
	TreeNode *previous = nullptr;

	//m_pRoot = new TreeNode(a_nSearchValue);
	current = m_pRoot;
	while (current != nullptr) 
	{
		
		if (a_nSearchValue == current->getData())
		{
			*ppOutNode = current;
			*ppOutParent = previous;
			return true;
				//current->getLeft(),
				//current->getRight();
		}
		else
		{
			if (a_nSearchValue < current->getData())
			{
				previous = current; // previous will equal current
				current = previous->getLeft(); // current [where it's looking] will equal previous's child on the right
				//current->setLeft(current);
			}
			else
			{
				previous = current; // previous will equal current
				current = previous->getRight();// current [where it's looking] will equal previous's child on the left 
				//current->setRight(current);
			}
		}
	}
	return false;
}

void BinaryTree::draw(aie::Renderer2D * renderer, TreeNode *pNode, int x, int y, int horizontalSpacing, TreeNode * selected)
{
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->hasLeft())
		{
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x - horizontalSpacing, y - 80);
			draw(renderer, pNode->getLeft(), x - horizontalSpacing,
				y - 80, horizontalSpacing, selected);
		}
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
