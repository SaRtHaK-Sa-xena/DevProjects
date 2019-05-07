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
	TreeNode *current = nullptr; //To remove
	TreeNode *parent = nullptr;
	findNode(a_nValue, &current, &parent);
	//Save-7
	//Save-6


	//while (current->getLeft() != nullptr)
	//{
		//--------No Need to go down a step---|
		//parent = current;                   |
		//current = parent->getLeft();		  |
		//---------No Need to go down a step--|
		//if (current->hasRight())
		//{
		//	//Deleting Right
		//	//current = current->getRight();
		//	//current = 19;
		//	parent->setLeft(current->getLeft());
		//	TreeNode *Temp = nullptr;
		//	//Temp = parent->getLeft(); //temp = 9;

		//	Temp = parent->getLeft()->getRight();
		//	
		//	if (Temp != nullptr)
		//	{
		//		Temp->setRight(current->getRight());
		//		//parent->setRight(Temp);
		//		delete current;
		//	}
		//	else
		//	{
		//		Temp = current->getLeft();
		//	}
		//
		//}
		//else
		//{
		//	parent->setLeft(current->getLeft());
		//	if (current->getLeft() == nullptr && current->getRight() == nullptr)
		//	{
		//		parent->setLeft(current);
		//	}
		//	delete current;
		//	//deleting LEFT SIDE
		//}


//========================================================================================
		if (parent->getRight() == current)
		{
			if (current->hasRight() && current->getLeft() == nullptr)
			{
				//parent->setLeft(current->getLeft());

				parent->setRight(current->getLeft());
				TreeNode *Temp = nullptr;
				//Temp = current-
				if (Temp->getLeft()!=nullptr)
				{
					
				}
				delete current;

			}
			else if(current->hasLeft())
			{
				 //now right equals 3
				TreeNode *Temp = nullptr;
				Temp = current->getLeft();
				if(Temp->getRight() != nullptr) //
				{
					parent->setRight(current->getLeft());
					Temp->setRight(current->getRight());
					//Temp = Temp->getRight();
				}
				parent->setRight(current->getLeft());
				//temp->setRight()
				//current->getRight

				delete current;
			}
			else
			{
				delete current;
			}
		}
		else // if(parent->getLeft() == current)
		{
			if (current->hasLeft() && current->getRight() == nullptr)
			{
				//Temp = current->getLeft();
				
				
				//getLeft()//->getRight();

				//THIS ONE========================================================
				//if (current->getRight() != nullptr) //if right side exists
				//{
				//	TreeNode *temp = nullptr;
				//	temp = current->getRight();
				//	
				//	parent->setLeft(current->getLeft());
				//}
				//================================================================
				parent->setLeft(current->getLeft());
				delete current;
				//5 under 3
				//SET
				//Temp = Temp->getLeft(); 
				//DELETE
				
			}
			else if (current->hasRight() && current->getLeft() == nullptr)
			{
				parent->setLeft(current->getRight());
				delete current;


				//Try to Fix =======================================================
				/*parent->setLeft(current->getRight());*/
				//TreeNode *Temp = nullptr;
				//Temp = current->getLeft();
				//while (Temp->getRight() != nullptr)
				//{
				//	Temp = Temp->getRight(); //iterate until the right side is empty
				//	//if ---> temp->getLeft != nullptr, set to 
				//}
				//Temp->setRight(current->getRight()); //now add to the right of that empty side
				//delete current;
				//CONTINUE THIS ========================================================

			}
			else if (current->hasLeft() && current->hasRight())
			{

			}
			else
			{
				delete current;
			}
			
		}
	//}

	/*if (current->getLeft() == nullptr)
	{
		parent->setRight(nullptr);
		delete current;
	}*/

	//parent->setLeft(nullptr);
	//delete current;
	//if (parent->getLeft() == nullptr)
	//{
	//	parent->setRight(nullptr);
	//	delete current;
	//}
	//else if (parent->getLeft() == nullptr && parent->getRight() == nullptr)
	//{
	//	parent->setRight(nullptr);
	//	delete current;
	//}
	//else
	//{
	//	parent->setLeft(nullptr);
	//	delete current;
	//}
	
}


//if (current->getData() == a_nValue)
//{
//	//TreeNode *Temp = nullptr;
//	//Temp->setData(current->getData());
//	//parent->setLeft(Temp);
//	//delete current;
//	////break;
//}
//current = parent->getRight();
//if (current->getData() == a_nValue)
//{
//	parent->set
//}
//else
//{
//	//if current->getData() = m_pRoot -> break;
//	current = parent->getLeft();
//	//break;
//}
//parent->setRight()

//======DONE=========================================
TreeNode * BinaryTree::find(int a_nValue)
{
	TreeNode *current = new TreeNode(a_nValue);
	TreeNode *parent = new TreeNode(a_nValue);
	findNode(a_nValue, &current, &parent);
	return current;
}
//======DONE=========================================


void BinaryTree::draw(aie::Renderer2D * renderer, TreeNode * selected)
{
	//if (selected == nullptr)
	//{
	//	return;
	//}
	draw(renderer, m_pRoot, 640, 680, 640, selected);
}


//======DONE=========================================
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
