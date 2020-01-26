// DynamicArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Array.h"
#include <string>


using namespace std;


class DynamicArray
{
private:

	int maxSize;
	int usedElements;
	int *ptrArray;



public:
	
	bool restart = false;
	bool restartUO = false;

	//Constructor
	DynamicArray()
	{
		maxSize = 10;
		usedElements = 0;
		ptrArray = new int[maxSize];
	}
	//Constructor


	//Deconstructor
	~DynamicArray()
	{
		delete[]ptrArray;
	}
	//Deconstructor


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
		int *ptrTemp = new int[maxSize];

		for (int i = 0; i < usedElements; i++)
		{
			//Copy values into
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

	void CopyConstructor(DynamicArray *mainArray)
	{
		for (int i = 0; i < usedElements; i++)
		{
			ptrArray[i] = mainArray->ptrArray[i];
			//mainArray->add(getAt(i));
		}
	}

	void initializeArray(int from)
	{
		for (int i = from; i < maxSize; i++)
		{
			//make each un used value to 0
			ptrArray[i] = 0;
		}
	}

	//remove unordered 
	void RemoveUO(int value)
	{
		//remove the value
		for (int i = 0; i < usedElements; i++)
		{
			//Ptr equal to value
			if (ptrArray[i] == value)
			{
				//Swap
				int Temp = ptrArray[i];
				//element equal to last element
				ptrArray[i] = ptrArray[usedElements - 1];
				//last element equal to value[element]
				ptrArray[usedElements - 1] = Temp;
				//delete last value
				popBack();
				//Swap
			}
		}
		
		//check if it needs to loop to it
		for (int i = 0; i < usedElements; i++)
		{
			if (ptrArray[i] == value)
			{
				RemoveUO(value);
			}
		}
	}

	//Clears entire array
	void ClearArray()
	{
		//Create new array
		int *ptrTemp = new int[maxSize];
		delete []ptrArray;
		ptrArray = ptrTemp;

		usedElements = 0;
		
		//intialize new array with no elements
		initializeArray(usedElements);
	}

	//To remove the value ordered
	void Remove(int value)
	{
		for (int i = 0; i < usedElements; i++)
		{
			//if the value of pos matches the value inputted
			if (ptrArray[i] == value)
			{
				if (ptrArray[i + 1] == value)
				{
					restart = true;
				}
				//swap
				int Temp = ptrArray[i];
				ptrArray[i] = ptrArray[i + 1];
				ptrArray[i + 1] = Temp;
				//swap
			}
		}
		popBack();
		if (restart)
		{
			restart = false;
			Remove(value);
		}
	}

	//adds to the dyanmic array
	void add(int el)
	{
		//if the used elements equals the max.
		if (usedElements >= maxSize)
		{
			//resizes the array
			reSize();
		}
		//add after usedElements
		//add at end
		ptrArray[usedElements++] = el;
	}

	//adds in the middle
	void AddInMiddle(int value, int position)
	{
		if (usedElements > 0)
		{
			//one element more than end
			int i = usedElements + 1;

			while (i > position)
			{
				//perform swap
				int Temp = ptrArray[i];
				ptrArray[i] = ptrArray[i - 1];
				ptrArray[i - 1] = Temp;
				//perform swap
				i--;
			}
			
			//increment usedElements
			usedElements += 1;
			//make the value of that position equal to value
			ptrArray[position] = value;
		}
		else
		{
			add(value);
		}
	}

	//returns size of used elements
	int returnElementsUsed() { return usedElements; }

	//returns element data at index
	int getAt(int index)
	{
		if (index < 0 || index >= usedElements)
		{
			//throw("Out of bounds exception!");
			cout << "No Items In Array" << endl;
		}
		else
		{
			return ptrArray[index];
		}
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

	void Sort()
	{
		int i = 0;

		//if list populated with at least two values to be sorted
		if (usedElements > 1)
		{
			//starts loop
			//checks if i less than usedElements
			while (i < (usedElements-1))
			{
				//if current value greater than next value
				if (ptrArray[i] > ptrArray[i + 1])
				{
					//swap both values
					int temp = ptrArray[i];
					ptrArray[i] = ptrArray[i+1];
					ptrArray[i + 1] = temp;
					//swap both values
					i = 0;
				}
				else
				{
					i++;
				}
			}
		}
	}

	void Search(int valueToSearch)
	{
		bool foundValue = false;
		//search through all used elements for key value
		for (int i = 0; i < usedElements; i++)
		{
			//if value matches display value key position value placed in
			if (ptrArray[i] == valueToSearch)
			{
				cout << "Value Found in " << i << endl;
				cout << endl;
				cout << i << ": " << valueToSearch << endl;;
				foundValue = true;
			}
		}
		if (!foundValue)
		{
			std::cout << "The Number: " << "[" << valueToSearch << "]" << " Does not exist in the list" << std::endl;
			std::cout << "Would You Like To Add it to the list? " << "\t\t (y/n)" << std::endl;
			string option;
			cin >> option;
			if (option == "y")
			{
				//only case where list appends to add new value
				std::cout << "Increased Size of Array to include value" << std::endl;
				add(valueToSearch);
			}
		}
	}

	void Display()
	{
		if (getAt(0))
		{
			for (int i = 0; i < usedElements; i++)
			{
				cout << i << ": " << getAt(i) << endl;
			}
		}
		else
		{
			cout << "Array Empty..." << endl;
		}
	}
};


int main()
{
	DynamicArray *temp = new DynamicArray();
	//Remove by unordered
	temp->ClearArray();

	for (int i = 0; i < temp->returnElementsUsed(); i++)
	{
		cout << i << ": " << temp->getAt(i) << endl;
	}

	DynamicArray *dArray = new DynamicArray();
	DynamicArray *TemporaryArray = new DynamicArray();
	bool cont = true;
	char choice = '0';
	int input;
	int location = dArray->returnElementsUsed()/2;
	int amountToAdd;

	while (cont)
	{
		cout << "(q)Add To Middle---(w)RemoveValueORDERED---(e)RemoveValueUNORDERED---(r)AddToEnd---(u)PopBack---(t)Clear\n(y)CopyConstructor---(l)Sort---(;)Search---(p)Display---" << endl;
		cin >> choice;
		switch (choice)
		{
		
		case'q':
			cout << "Adding to middle..." << endl;
			
			//Fixed Attempt Number 1:
			cout << "Enter How Many Values To Add To Middle" << endl;
			cin >> amountToAdd;
			while (cin.fail())
			{
				cout << "Error" << endl;
				cin.clear();
				cout << "Enter a Number: " << endl;
				cin.ignore(256, '\n');
				cin >> amountToAdd;
			}
			
			for (int i = 0; i < amountToAdd; i++)
			{
				cout << "Enter Value to Enter: " << endl;
				cin >> input;
				while (cin.fail())
				{
					cout << "Error" << endl;
					cin.clear();
					cout << "Enter a Number: " << endl;
					cin.ignore(256, '\n');
					cin >> input;
				}
				location = dArray->returnElementsUsed() / 2;
				dArray->AddInMiddle(input, location);
			}
			break;

			//Previous
			//not needed======================================
			/*cout << "Enter Position to Place it in: " << endl;
			cin >> location;
			while (cin.fail())
			{
				cout << "Error" << endl;
				cin.clear();
				cout << "Enter a Number: " << endl;
				cin.ignore(256, '\n');
				cin >> location;
			}*/


			//checks if user entered position above used elements in array
			/*if (location > dArray->returnElementsUsed())
			{
				cout << "Location entered exceeds array list by more than two" << endl;
				break;
			}
			else
			{
				dArray->AddInMiddle(input, location);
				break;
			}*/
			//================================================

		case'w':
			cout << "Removing Value...printing ordered" << endl;
			cout << "Enter value to Remove: " << endl;
			cin >> input;
			while (cin.fail())
			{
				cout << "Error" << endl;
				cin.clear();
				cout << "Enter a Number: " << endl;
				cin.ignore(256, '\n');
				cin >> input;
			}
			dArray->Remove(input);
			break;
		
		case'e':
			cout << "Removing Value...printing unordered" << endl;
			cout << "Enter value to Remove: " << endl;
			cin >> input;
			while (cin.fail())
			{
				cout << "Error" << endl;
				cin.clear();
				cout << "Enter a Number: " << endl;
				cin.ignore(256, '\n');
				cin >> input;
			}
			dArray->RemoveUO(input);
			break;
		
		case'r':
			cout << "Adding to end..." << endl;
			cout << "Which value to add to array: " << endl;
			cin >> input;
			while (cin.fail())
			{
				cout << "Error" << endl;
				cin.clear();
				cout << "Enter a Number: " << endl;
				cin.ignore(256, '\n');
				cin >> input;
			}
			dArray->add(input);
			break;
		
		case't':
			cout << "Clearing Array..." << endl;
			dArray->ClearArray();
			break;
		
		case'y':
			cout << "Copying into another array" << endl;
			TemporaryArray = dArray;
			TemporaryArray->Display();
			break;
		
		case'u':
			cout << "Deleting last element" << endl;
			dArray->popBack();
			break;
		
		case'p':
			cout << "Displaying Array..." << endl;
			dArray->Display();
			break;
		
		case 'l':
			cout << "Sorting Array..." << endl;
			dArray->Sort();
			dArray->Display();
			break;
		
		case';':
			cout << "Searching For Array..." << endl;
			cout << "Enter Value to search" << endl;
			//gather input
			cin >> input;
			while (cin.fail())
			{
				cout << "Error" << endl;
				cin.clear();
				cout << "Enter a Number: " << endl;
				cin.ignore(256, '\n');
				cin >> input;
			}
			dArray->Search(input);
			break;
		
		default:
			break;
		}
	}
		

}