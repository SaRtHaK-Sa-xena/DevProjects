#include "Node.h"



Node::Node(int value)
{
	m_value = value;
	current_value = 0;
}

Node::~Node()
{
}

void Node::SetValue(float value)
{
	current_value = value;
}

void Node::setRight(Node * current)
{
	m_right = current;
}

void Node::setLeft(Node * current)
{
	m_left = current;
}

Node * Node::getRight()
{
	return m_right;
}

Node * Node::getLeft()
{
	return m_left;
}

void Node::setData(int value)
{
}

int Node::getData()
{
	return m_value;
}
