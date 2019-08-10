#pragma once
#include "Node.h"

class ArrayClass
{
private:
	NodeClass *root;


public:

	// constructor
	ArrayClass();

	//helper function returning root
	NodeClass *returnRoot();

	//adds new element in array
	void insert(int value);

	// displays the values of each element
	void display();	

	//sorts elements by value held
	void sort();

	//finds value using value
	void search(int a_value);

	// removes last element in array
	void popBack();

	// removes first element in array
	void popFront();

	// checks if array empty
	bool Empty();
};