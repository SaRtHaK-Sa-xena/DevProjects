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

	// Manually sets amount of elements in array
	void manualSetter();

	//clears all elements
	void clear();

	// checks if array empty
	bool Empty();

	// sets value on index
	void setOnIndex();

	void CopyContructor(ArrayClass* dynamicArray);

};