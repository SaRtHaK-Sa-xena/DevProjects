#pragma once

// DynamicArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Square.h"
using namespace std;


class DynamicArray
{
private:

	//max size of elements in array
	int maxSize;

	//currently used elements
	int usedElements;

	//create array of square type
	Square *ptrArray;

public:



	//Constructor
	DynamicArray()
	{
		//create 10 elements in beginning
		maxSize = 10;
		
		//create the array with 0 used
		usedElements = 0;
		
		ptrArray = new Square[maxSize];
		//may not be used.
		//ptrArray = new int[maxSize];
	}
	//Constructor


	//Deconstructor
	~DynamicArray()
	{
		//delete array
		delete[]ptrArray;
	}
	//Deconstructor


	Square *ReturnRoot()
	{
		return &ptrArray[0];
	}

	//Assignment Operator Override function
	void *operator=(DynamicArray* otherArray)
	{
		for (int i = 0; i < otherArray->usedElements; i++)
		{
			//copy into
			ptrArray[i] = otherArray->ptrArray[i];
		}

		//Copy other values of member variables
		maxSize = otherArray->maxSize;
		usedElements = otherArray->usedElements;

		//return pointer to new copied Dynamic Array
	}
	//Assignment Operator Override function


	//Resize Function
	void reSize()
	{
		//increase maxSize
		maxSize *= 2;

		//create temporary pointer
		//Square *ptrTemp = new Square[maxSize];
		
		//This may work
		Square *ptrTemp = new Square[maxSize];

		for (int i = 0; i < usedElements; i++)
		{
			//Copy values into new Array
			ptrTemp[i] = ptrArray[i];
		}

		//delete previous Array
		delete[] ptrArray;

		//Make member variable array equal to new array
		ptrArray = ptrTemp;

		//initialize array using usedElements
		initializeArray(usedElements);
	}
	//Resize Function


	//initalize 
	void initializeArray(int from)
	{
		for (int i = from; i < maxSize; i++)
		{
			//make it have value of null, with no position
			//check if this works
			ptrArray[i] = *new Square();
			std::cout << "Added Line: \n ptrArray[" << i << "] = *new Square();";
		}
	}

	//adds to the dyanmic array
	void add(string colourValue)
	{
		//if the used elements equals the max.
		if (usedElements >= maxSize)
		{
			//resizes the array
			reSize();
		}
		//add at end
		ptrArray[usedElements++] = *new Square(0,0,0,0,colourValue);
	}

	//returns size of used elements
	int returnElementsUsed() { return usedElements; }

	//returns element data at index
	Square *getAt(int index)
	{
		if (index < 0 || index >= usedElements)
		{
			throw("Out of bounds exception!");
		}
		return &ptrArray[index];
	}

	//deletes last element in array
	void popBack()
	{
		if (usedElements > 0)
		{
			ptrArray[--usedElements];
		}
		else
		{
			cout << "Array empty...";
		}
	}
};






