#pragma once
#include "Node.h"

class ArrayClass
{
private:
	NodeClass *root;


public:

	ArrayClass();
	NodeClass *returnRoot();

	void insert(int value);
	void display();	
	void sort();
	void search(int a_value);
};