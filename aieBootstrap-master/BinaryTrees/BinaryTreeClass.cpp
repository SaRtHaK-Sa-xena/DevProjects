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


//======INSERTS VALUE IN TREE=========================================
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
		TreeNode *current = nullptr;
		current = m_pRoot; //current will equal m_pRoot
		
		
		//Save-1				   
		while (current != nullptr)
		{
			if (a_nValue < current->getData())//if 2 < 5 [2 equal to current] --- [5 equal to root]
			{
				if (current->getLeft() == nullptr)
				{
					current->setLeft(new TreeNode(a_nValue));
					break;
				}
				current = current->getLeft();//moves down the left
				//Save-2
			
			}
			
			if (a_nValue > current->getData())//If value greater, it'll make it right child
			{
				if (current->getRight() == nullptr)
				{
					current->setRight(new TreeNode(a_nValue));
					break;
				}
				current = current->getRight();//moves down the right
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
	TreeNode *current = nullptr; //To remove
	TreeNode *parent = nullptr;
//========================================================================================
	if (findNode(a_nValue, &current, &parent) == true)
	{
		//=============DELETEING ROOT FUNCTION==============
		if (parent == nullptr) 
		{

			//======TRIED FIXING THIS============
			if (!current->hasLeft() && !current->hasRight()) //has no children
			{
				m_pRoot = nullptr;
				delete current; //closes program since there is no root
			}
			else if (current->hasLeft() && current->hasRight())// has both children
			{
				TreeNode* temp = nullptr;
				temp = current->getRight();
				if (!temp->hasLeft()) //if the right child doesn't hold a left child
				{
					parent = current->getRight();
					parent->setLeft(current->getLeft());
					m_pRoot = parent;
					delete current;
				}
				else // if the right child holds a left child
				{
					parent = current->getRight();
					while (parent->hasLeft())
					{
						parent = parent->getLeft();
					}
					parent->setRight(current->getRight());
					parent->setLeft(current->getLeft());
					m_pRoot = parent;
					delete current;
					//==================================
				/*	while (temp->hasLeft())
					{
						temp = temp->getLeft();
					}
					parent = temp;
					parent->setLeft(current->getLeft());
					parent->setRight(current->getRight());
					m_pRoot = parent;
					delete current;*/
					//=====================================
					/*temp->setLeft(current->getLeft());
					temp->setRight(current->getRight());
					current->setLeft(nullptr);
					current->setRight(nullptr);
					m_pRoot = temp;
					delete current;*/
					//====================================
					//parent = current->getRight();
					//TreeNode* temp2 = nullptr;
					//temp2 = current->getRight();
					//while (temp2->hasLeft())//iterate down right child's left child's left children |-if any-|
					//{
					//	temp2 = temp2->getLeft(); //iterating down
					//}
					//m_pRoot->setData(temp2->getData());
					////current->setRight(temp2);
					////temp2->setRight(parent);
					////temp2->setLeft(current->getLeft());
					////m_pRoot = temp2;
					//delete temp2;

					////temp2->setLeft(current->getLeft());
					////m_pRoot = parent;
					////delete current;

				}
			}
			else if (current->hasLeft() && !current->hasRight())
			{
				parent = current->getLeft();
				m_pRoot = parent;
				delete current;
			}
			else if (current->hasRight() && !current->hasLeft())
			{
				parent = current->getRight();
				m_pRoot = parent;
				delete current;
			}
			

		}
		//=========END DELETEING ROOT FUNCTION==============


		//====================DELETE RIGHT SIDE OF PARENT======================
		else if (parent->getRight() == current)
		{
			if (!current->hasRight() && !current->hasLeft()) //has no children
			{
				parent->setRight(nullptr);
				delete current;
			}
			else if (current->getLeft() == nullptr && current->getRight() != nullptr) //has right child but no left
			{
				parent->setRight(current->getRight());
				delete current;
			}
			else if (current->getRight() == nullptr && current->getLeft() != nullptr)// has left child but no right
			{
				parent->setRight(current->getLeft());
				delete current;
			}
			else if (current->getLeft() != nullptr && current->getRight() != nullptr)//has both children
			{
				//IF current's right child doesn't hold a left child
				if (current->getRight()->getLeft() == nullptr)
				{
					parent->setRight(current->getRight());
					TreeNode* temp = nullptr;
					temp = parent->getRight();
					//while (temp->getLeft() != nullptr)
					//{
						//temp = temp->getLeft();
					//}
					temp->setLeft(current->getLeft());
					delete current;
				}
				else //IF current's right child holds a left child
				{
					parent->setRight(current->getRight());
					TreeNode* temp = nullptr;
					temp = parent->getRight();
					while (temp->hasLeft())
					{
						temp = temp->getLeft();
					}
					temp->setLeft(current->getLeft());
					delete current;
				}
				
			}
		}
		//===============END  DELETE RIGHT SIDE OF PARENT======================



		//====================DELETE LEFT SIDE OF PARENT======================
		else if (parent->getLeft() == current)
		{
			if (current->getRight() == nullptr && current->getLeft() == nullptr) // has no children
			{
				parent->setLeft(nullptr);
				delete current;
			}
			else if (current->getLeft() == nullptr && current->getRight() != nullptr)// has right child but no left
			{
				parent->setLeft(current->getRight());
				delete current;
			}
			else if (current->getLeft() != nullptr && current->getRight() == nullptr)// has left child but no right
			{
				parent->setLeft(current->getLeft());
				delete current;
			}
			else if (current->getRight() != nullptr && current->getLeft() != nullptr)// has both children
			{
				parent->setLeft(current->getRight());
				TreeNode* temp = nullptr;
				temp = parent->getLeft();
				if (temp->hasLeft())
				{
					temp = temp->getLeft();
				}
				temp->setLeft(current->getLeft());
			}
		}
		//================END DELETE LEFT SIDE OF PARENT======================
	}
}




//======Find Node->Goes Into findNode()=========================================
TreeNode * BinaryTree::find(int a_nValue)
{
	TreeNode *current = new TreeNode(a_nValue);
	TreeNode *parent = new TreeNode(a_nValue);
	findNode(a_nValue, &current, &parent);
	return current;
}
//======DONE=========================================



//======Draws Node=========================================
void BinaryTree::draw(aie::Renderer2D * renderer, TreeNode * selected)
{
	//if (selected == nullptr)
	//{
	//	return;
	//}
	draw(renderer, m_pRoot, 640, 680, 640, selected);
}
//======DONE=========================================

//======Finds Node AND RETURNS parent and Current=========================================
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
//======DONE=========================================


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
