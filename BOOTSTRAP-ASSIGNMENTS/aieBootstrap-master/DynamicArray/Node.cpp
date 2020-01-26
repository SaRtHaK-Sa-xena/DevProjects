#include "pch.h"
#include "Node.h"


NodeClass::NodeClass(int value)
{
	m_value = value;
}

NodeClass::~NodeClass()
{
}

void NodeClass::setRight(NodeClass* current)
{
	m_right = current;
}

NodeClass* NodeClass::getRight()
{
	return m_right;
}

void NodeClass::setData(int a_nValue)
{
	m_value = a_nValue;
}

int NodeClass::getData()
{
	return m_value;
}
