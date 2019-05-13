#include "pch.h"
#include "Node.h"


Node::Node()
{
	next = nullptr;
	prev = nullptr;
	m_data = 0;
}


Node::~Node()
{
}

Node::Node(int a_data)
{
	next = nullptr;
	prev = nullptr;
	m_data = a_data;
}