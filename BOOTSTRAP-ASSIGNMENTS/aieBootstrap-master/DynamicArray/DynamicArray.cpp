// DynamicArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Array.h"


using namespace std;


class DynamicArray
{
private:

	int maxSize;
	int usedElements;
	int *ptrArray;



public:
	
	

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
	DynamicArray *operator=(DynamicArray* otherArray)
	{
		DynamicArray *copyIntoArray = new DynamicArray();

		for (int i = 0; i < otherArray->usedElements; i++)
		{
			//copy into
			copyIntoArray->ptrArray[i] = otherArray->ptrArray[i];
		}

		//Copy other values of member variables
		copyIntoArray->maxSize = otherArray->maxSize;
		copyIntoArray->usedElements = otherArray->usedElements;

		//return pointer to new copied Dynamic Array
		return copyIntoArray;
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
		mainArray = this;
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
				break;
				//Swap
			}
		}


		/*int i = 0;
		while (i < usedElements)
		{
			if (ptrArray[i] == value)
			{
				int Temp = ptrArray[i];
				ptrArray[i] = ptrArray[usedElements];
				ptrArray[usedElements] = ptrArray[i];
				popBack();
				break;
			}
			i++;
		}*/

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
				//swap
				int Temp = ptrArray[i];
				ptrArray[i] = ptrArray[i + 1];
				ptrArray[i + 1] = Temp;
				//swap
			}
		}
		popBack();
		//Call PopBack function

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
		//for (int i = position; i < usedElements; i++)
		//{
		//	//swap

		//	ptrArray[i] = ptrArray[i + 1];
		//}
		//increment usedElements
		usedElements += 1;
		//make the value of that position equal to value
		ptrArray[position] = value;
	}

	//returns size of used elements
	int returnElementsUsed() { return usedElements; }

	//returns element data at index
	int getAt(int index)
	{
		if (index < 0 || index >= usedElements)
		{
			throw("Out of bounds exception!");
		}
		return ptrArray[index];
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
		for (int i = 0; i < usedElements; i++)
		{
			ptrArray[i]
		}
	}

};


int main()
{
	DynamicArray *temp = new DynamicArray();


	//Adds values
	temp->add(15);
	temp->add(125);
	temp->add(13);
	temp->add(3);
	temp->add(67);
	temp->add(12);

	//Add in middle
	//temp->AddInMiddle(999, 3);

	//Remove by ordered
	//temp->Remove(999);

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
	int location;

	while (cont)
	{
		cout << "(q)Add To Middle---(w)RemoveValueORDERED---(e)RemoveValueUNORDERED---(r)AddToEnd---(u)PopBack---(t)Clear---(y)CopyConstructor---(p)Display---" << endl;
		cin >> choice;
		switch (choice)
		{
		case'q':
			cout << "Adding to middle..." << endl;
			cout << "Enter Value to Enter: " << endl;
			cin >> input;

			cout << "Enter Position to Place it in: " << endl;
			cin >> location;

			dArray->AddInMiddle(input, location);
			break;
		case'w':
			cout << "Removing Value...printing ordered" << endl;
			cout << "Enter value to Remove: " << endl;
			cin >> input;
			dArray->Remove(input);
			break;
		case'e':
			cout << "Removing Value...printing unordered" << endl;
			cout << "Enter value to Remove: " << endl;
			cin >> input;
			dArray->RemoveUO(input);
			break;
		case'r':
			cout << "Adding to end..." << endl;
			cout << "Which value to add to array: " << endl;
			cin >> input;
			dArray->add(input);
			break;
		case't':
			cout << "Clearing Array..." << endl;
			dArray->ClearArray();
			break;
		case'y':
			cout << "Copying into another array" << endl;
			dArray->CopyConstructor(TemporaryArray);
			break;
		case'u':
			cout << "Deleting last element" << endl;
			dArray->popBack();
			break;
		case'p':
			cout << "Displaying Array..." << endl;
			break;
		default:
			break;
		}
	}
		

}

//----Don't Hit-----
//int main()
//{
//	ArrayClass* DynamicTree = new ArrayClass();
//	ArrayClass * secondDynamicTree = new ArrayClass();
//	int value;
//	bool cont = true;
//	bool NewArrayCreated = false;
//	bool switchArray = false;
//	char choice = '0';
//	int i = 0;
//	int t1 = 555;
//	int t2 = 222;
//	int searchId;
//	NodeClass* current;
//	NodeClass* currentRight;
//	
//
//	std::cout << "What size will you like to give your dynamic array?" << std::endl;
//	DynamicTree->manualSetter();
//
//	while (cont)
//	{
//		cout << "What Do you want to Do? " << endl;
//		cout << "(d)isplay---(s)ort---(f)ind---(c)popBack---(x)popFront---(z)clear---(b)setIndex---(,)copyConstructor---(e)xit---" << endl;
//		if (NewArrayCreated)
//		{
//			cout << "Use Newly created array (n)" << endl;
//		}
//		cin >> choice;
//		if (switchArray == false)
//		{
//			switch (choice)
//			{
//			case'd':
//				//displays entire array
//				cout << "\t\t\t displaying..." << endl;
//				DynamicTree->display();
//				break;
//			case'c':
//				//removes last element
//				DynamicTree->popBack();
//				cout << "\t\t\t displaying..." << endl;
//				DynamicTree->display();
//				break;
//			case'x':
//				//removes front element
//				DynamicTree->popFront();
//				cout << "\t\t\t displaying..." << endl;
//				DynamicTree->display();
//				break;
//			case'z':
//				//clears entire array
//				DynamicTree->clear();
//				cout << "\t\t\t displaying..." << endl;
//				DynamicTree->display();
//				break;
//			case'b':
//				//sets values on index
//				DynamicTree->setOnIndex();
//				cout << "\t\t\t displaying..." << endl;
//				DynamicTree->display();
//				break;
//			case',':
//				//copies elements of array into second array
//				DynamicTree->CopyContructor(secondDynamicTree);
//				cout << "\t\t\t displaying..." << endl;
//				std::cin.get();
//				//displays it in second Dynamic Array
//				std::cout << "Displaying in New Array" << std::endl;
//				secondDynamicTree->display();
//				NewArrayCreated = true;
//				break;
//			case's':
//				//sorts the array
//				cout << "\t\t\t Sorting..." << endl;
//				DynamicTree->sort();
//				//==============DISPLAY====================
//				current = DynamicTree->returnRoot();
//				cout << "Reached End" << endl;
//				while (current->getRight() != nullptr)
//				{
//					i++;
//					cout << "Data:" << i << " " << current->getData() << endl;
//					current = current->getRight();
//				}
//				i = i + 1;
//				cout << "Data:" << i << " " << current->getData() << endl;
//				i = 0;
//				//==============DISPLAY====================
//
//				break;
//			case'f':
//				//displays searched id
//				cout << "\t\t\t searching..." << endl;
//				cout << "Enter Id To Look For: " << endl;
//				cin >> searchId;
//				while (cin.fail())
//				{
//					cout << "Error" << endl;
//					cin.clear();
//					cin.ignore(256, '\n');
//					cout << endl;
//					cout << "Enter a number please: " << endl;
//					cin >> searchId;
//				}
//				DynamicTree->search(searchId);
//				break;
//			case'e':
//				//exits the application
//				cout << "Exiting..." << endl;
//				return 0;
//			default:
//				//default, activated due to improper input
//				cout << "Enter One Of The Listed Options" << endl;
//				break;
//			if (NewArrayCreated)
//			{
//			case'n':
//				cout << "Switching Working Array" << endl;
//				switchArray = true;
//			}
//			}
//		}
//		if (switchArray == true)
//		{
//			switch (choice)
//			{
//			case'd':
//				//displays entire array
//				cout << "\t\t\t displaying..." << endl;
//				secondDynamicTree->display();
//				break;
//			case'c':
//				//removes last element
//				secondDynamicTree->popBack();
//				cout << "\t\t\t displaying..." << endl;
//				secondDynamicTree->display();
//				break;
//			case'x':
//				//removes front element
//				secondDynamicTree->popFront();
//				cout << "\t\t\t displaying..." << endl;
//				secondDynamicTree->display();
//				break;
//			case'z':
//				//clears entire array
//				secondDynamicTree->clear();
//				cout << "\t\t\t displaying..." << endl;
//				secondDynamicTree->display();
//				break;
//			case'b':
//				//sets values on index
//				secondDynamicTree->setOnIndex();
//				cout << "\t\t\t displaying..." << endl;
//				secondDynamicTree->display();
//				break;
//			case's':
//				//sorts the array
//				cout << "\t\t\t Sorting..." << endl;
//				secondDynamicTree->sort();
//				//==============DISPLAY====================
//				current = secondDynamicTree->returnRoot();
//				cout << "Reached End" << endl;
//				while (current->getRight() != nullptr)
//				{
//					i++;
//					cout << "Data:" << i << " " << current->getData() << endl;
//					current = current->getRight();
//				}
//				i = i + 1;
//				cout << "Data:" << i << " " << current->getData() << endl;
//				i = 0;
//				//==============DISPLAY====================
//
//				break;
//			case',':
//				switchArray = false;
//				break;
//			case'f':
//				//displays searched id
//				cout << "\t\t\t searching..." << endl;
//				cout << "Enter Id To Look For: " << endl;
//				cin >> searchId;
//				while (cin.fail())
//				{
//					cout << "Error" << endl;
//					cin.clear();
//					cin.ignore(256, '\n');
//					cout << endl;
//					cout << "Enter a number please: " << endl;
//					cin >> searchId;
//				}
//				secondDynamicTree->search(searchId);
//				break;
//			case'e':
//				//exits the application
//				cout << "Exiting..." << endl;
//				return 0;
//			default:
//				//default, activated due to improper input
//				cout << "Enter One Of The Listed Options" << endl;
//				break;
//			}
//		}
//	}
//}
//----Don't Hit-----


