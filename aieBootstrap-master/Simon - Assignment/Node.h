#pragma once
#include <string>
#include "Renderer2D.h"
using namespace std;

class Node
{
public:
	Node(string value);
	~Node();

	Node *getRight()
	{
		return m_right;
	}

	string getData()
	{
		return m_value;
	}

	/*Node *getRight()
	{
		return m_right;
	}*/

	void setData(string value)
	{
		m_value = value;
	}

	bool hasRight()
	{
		return(m_right != nullptr);
	}

	void SetRight(Node *node)
	{
		m_right = node;
	}

	void draw(aie::Renderer2D* renderer, int x, int y, bool selected = false);
private:
	string m_value;

	Node *m_right = nullptr;
};