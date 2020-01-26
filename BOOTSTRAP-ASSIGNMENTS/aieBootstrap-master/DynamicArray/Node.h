#pragma once
#include <iostream>


class NodeClass
{
public:

	NodeClass(int value);
	~NodeClass();


	//To Set Values
	void setRight(NodeClass* current);

	//To Check Values 
	NodeClass *getRight();

	void setData(int a_nValue);
	int getData();

private:
	NodeClass *m_right = nullptr;
	NodeClass *m_left = nullptr;

	int m_value;
};