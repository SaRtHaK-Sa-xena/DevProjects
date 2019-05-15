#pragma once
#include "Renderer2D.h";


class TreeNode
{
public:
	//Constructor
	TreeNode(int value);
	//Deconstructor
	~TreeNode();

	//Normal Functions
	bool hasLeft()
	{
		return (m_left != nullptr);
	}
	bool hasRight()
	{
		return (m_right != nullptr);
	}
	int getData()
	{
		return m_value;
	}
	
	//Gets With Node
	TreeNode *getLeft()
	{
		return m_left;
	}
	TreeNode *getRight()
	{
		return m_right;
	}

	//Sets
	void setData(int value)
	{
		m_value = value;
	}
	void setLeft(TreeNode *node)
	{
		m_left = node;
	}
	void setRight(TreeNode *node)
	{
		m_right = node;
	}

	void draw(aie::Renderer2D* renderer, int x, int y, bool selected = false);

private:
	int m_value;

	TreeNode *m_left = nullptr;
	TreeNode *m_right = nullptr;


};