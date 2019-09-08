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


	//Copy Constructor may not be needed for this
	void CopyConstructor(DynamicArray *mainArray)
	{
		for (int i = 0; i < usedElements; i++)
		{
			ptrArray[i] = mainArray->ptrArray[i];
			//mainArray->add(getAt(i));
		}
	}

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

	//remove unordered 
	void RemoveUO(string value)
	{
		for (int i = 0; i < usedElements; i++)
		{
			//Ptr equal to value
			if (ptrArray[i].getData() == value)
			{
				//|------------Swap------------------

				//create a temp storage of pointer
				Square Temp = ptrArray[i];
				//element equal to last element
				ptrArray[i] = ptrArray[usedElements - 1];
				//last element equal to value[element]
				ptrArray[usedElements - 1] = Temp;
				//delete last value
				popBack();
				break;

				//|------------Swap------------------
			}
		}
	}

	//Clears entire array---May not be required for this project
	void ClearArray()
	{
		//Create new array
		Square *ptrTemp = new Square[maxSize];
		delete[]ptrArray;
		ptrArray = ptrTemp;

		usedElements = 0;

		//intialize new array with no elements
		initializeArray(usedElements);
	}

	//To remove the value ordered
	void Remove(string value)
	{
		for (int i = 0; i < usedElements; i++)
		{
			//if the value of pos matches the value inputted
			if (ptrArray[i].getData() == value)
			{
				//swap
				Square Temp = ptrArray[i];
				ptrArray[i] = ptrArray[i + 1];
				ptrArray[i + 1] = Temp;
				//swap
			}
		}
		popBack();
		//Call PopBack function

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
		//add after usedElements
		//add at end
		
		//check if value should be correct
		//if (colourValue == "RED")
			//
		ptrArray[usedElements++] = *new Square(0,0,0,0,colourValue);
	}

	//adds in the middle
	void AddInMiddle(string Colourvalue, int position)
	{
		if (usedElements > 1)
		{
			//one element more than end
			int i = usedElements + 1;

			while (i > position)
			{
				//perform swap
				Square Temp = ptrArray[i];
				ptrArray[i] = ptrArray[i - 1];
				ptrArray[i - 1] = Temp;
				//perform swap
				i--;
			}
			//for (int i = position; i < usedElements; i++)
			//{
			//	//swap

			//	ptrArray[i] = ptrArray[i + 1];
			//}
			//increment usedElements
			usedElements += 1;
			//make the value of that position equal to value
			ptrArray[position] = *new Square(0,0,0,0,Colourvalue);
		}
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

	void Display()
	{
		Square *temp = new Square();
		if (getAt(0)->getData() == "")
		{
			for (int i = 0; i < usedElements; i++)
			{
				cout << i << ": " << getAt(i)->getData() << endl;
			}
		}
		else
		{
			cout << "Array Empty..." << endl;
		}
	}

};






