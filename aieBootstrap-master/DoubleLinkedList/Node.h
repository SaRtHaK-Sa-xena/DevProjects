#pragma once
class Node
{
public:
	Node();
	~Node();

	Node(int a_data);

	Node *next;
	Node *prev;
	int m_data;
};