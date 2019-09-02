// DynamicArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Array.h"


using namespace std;


class DynamicArray
{
private:

	int cap;
	int usedElements;
	int *ptrArray;



public:

	DynamicArray()
	{
		cap = 10;
		usedElements = 0;
		ptrArray = new int[cap];
	}

	~DynamicArray()
	{
		delete[]ptrArray;
	}

	void reSize()
	{
		//increase cap
		cap *= 2;

		//create temporary pointer
		int *ptrTemp = new int[cap];

		for (int i = 0; i < usedElements; i++)
		{
			ptrTemp[i] = ptrArray[i];
		}

		delete[] ptrArray;

		ptrArray = ptrTemp;

		initializeArray(usedElements);
	}

	void initializeArray(int from)
	{
		for (int i = from; i < cap; i++)
		{
			ptrArray[i] = 0;
		}
	}

	int Remove(int value)
	{
		for (int i = 0; i < usedElements; i++)
		{
			if (ptrArray[i] == value)
			{
				//swap
				int Temp = ptrArray[i];
				ptrArray[i] = ptrArray[i + 1];
				ptrArray[i + 1] = Temp;
			}
		}
		//Call PopBack function

	}

	void add(int el)
	{
		if (usedElements >= cap)
		{
			reSize();
		}
		ptrArray[usedElements++] = el;
	}

	int AddInMiddle(int value, int position)
	{
		for (int i = position; i < usedElements; i++)
		{
			ptrArray[i] = ptrArray[i + 1];
		}
		ptrArray[position] = value;
	}

	int returnElementsUsed() { return usedElements; }

	int getAt(int index)
	{
		if (index < 0 || index >= usedElements)
		{
			throw("Out of bounds exception!");
		}
		return ptrArray[index];
	}

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


int main()
{
	DynamicArray *temp = new DynamicArray();
	temp->CreateArray(5);

	for (int i = 0; i < temp->returnElementsUsed(); i++)
	{

	}

}

//----Don't Hit-----
int main()
{
	ArrayClass* DynamicTree = new ArrayClass();
	ArrayClass * secondDynamicTree = new ArrayClass();
	int value;
	bool cont = true;
	bool NewArrayCreated = false;
	bool switchArray = false;
	char choice = '0';
	int i = 0;
	int t1 = 555;
	int t2 = 222;
	int searchId;
	NodeClass* current;
	NodeClass* currentRight;
	

	std::cout << "What size will you like to give your dynamic array?" << std::endl;
	DynamicTree->manualSetter();

	while (cont)
	{
		cout << "What Do you want to Do? " << endl;
		cout << "(d)isplay---(s)ort---(f)ind---(c)popBack---(x)popFront---(z)clear---(b)setIndex---(,)copyConstructor---(e)xit---" << endl;
		if (NewArrayCreated)
		{
			cout << "Use Newly created array (n)" << endl;
		}
		cin >> choice;
		if (switchArray == false)
		{
			switch (choice)
			{
			case'd':
				//displays entire array
				cout << "\t\t\t displaying..." << endl;
				DynamicTree->display();
				break;
			case'c':
				//removes last element
				DynamicTree->popBack();
				cout << "\t\t\t displaying..." << endl;
				DynamicTree->display();
				break;
			case'x':
				//removes front element
				DynamicTree->popFront();
				cout << "\t\t\t displaying..." << endl;
				DynamicTree->display();
				break;
			case'z':
				//clears entire array
				DynamicTree->clear();
				cout << "\t\t\t displaying..." << endl;
				DynamicTree->display();
				break;
			case'b':
				//sets values on index
				DynamicTree->setOnIndex();
				cout << "\t\t\t displaying..." << endl;
				DynamicTree->display();
				break;
			case',':
				//copies elements of array into second array
				DynamicTree->CopyContructor(secondDynamicTree);
				cout << "\t\t\t displaying..." << endl;
				std::cin.get();
				//displays it in second Dynamic Array
				std::cout << "Displaying in New Array" << std::endl;
				secondDynamicTree->display();
				NewArrayCreated = true;
				break;
			case's':
				//sorts the array
				cout << "\t\t\t Sorting..." << endl;
				DynamicTree->sort();
				//==============DISPLAY====================
				current = DynamicTree->returnRoot();
				cout << "Reached End" << endl;
				while (current->getRight() != nullptr)
				{
					i++;
					cout << "Data:" << i << " " << current->getData() << endl;
					current = current->getRight();
				}
				i = i + 1;
				cout << "Data:" << i << " " << current->getData() << endl;
				i = 0;
				//==============DISPLAY====================

				break;
			case'f':
				//displays searched id
				cout << "\t\t\t searching..." << endl;
				cout << "Enter Id To Look For: " << endl;
				cin >> searchId;
				while (cin.fail())
				{
					cout << "Error" << endl;
					cin.clear();
					cin.ignore(256, '\n');
					cout << endl;
					cout << "Enter a number please: " << endl;
					cin >> searchId;
				}
				DynamicTree->search(searchId);
				break;
			case'e':
				//exits the application
				cout << "Exiting..." << endl;
				return 0;
			default:
				//default, activated due to improper input
				cout << "Enter One Of The Listed Options" << endl;
				break;
			if (NewArrayCreated)
			{
			case'n':
				cout << "Switching Working Array" << endl;
				switchArray = true;
			}
			}
		}
		if (switchArray == true)
		{
			switch (choice)
			{
			case'd':
				//displays entire array
				cout << "\t\t\t displaying..." << endl;
				secondDynamicTree->display();
				break;
			case'c':
				//removes last element
				secondDynamicTree->popBack();
				cout << "\t\t\t displaying..." << endl;
				secondDynamicTree->display();
				break;
			case'x':
				//removes front element
				secondDynamicTree->popFront();
				cout << "\t\t\t displaying..." << endl;
				secondDynamicTree->display();
				break;
			case'z':
				//clears entire array
				secondDynamicTree->clear();
				cout << "\t\t\t displaying..." << endl;
				secondDynamicTree->display();
				break;
			case'b':
				//sets values on index
				secondDynamicTree->setOnIndex();
				cout << "\t\t\t displaying..." << endl;
				secondDynamicTree->display();
				break;
			case's':
				//sorts the array
				cout << "\t\t\t Sorting..." << endl;
				secondDynamicTree->sort();
				//==============DISPLAY====================
				current = secondDynamicTree->returnRoot();
				cout << "Reached End" << endl;
				while (current->getRight() != nullptr)
				{
					i++;
					cout << "Data:" << i << " " << current->getData() << endl;
					current = current->getRight();
				}
				i = i + 1;
				cout << "Data:" << i << " " << current->getData() << endl;
				i = 0;
				//==============DISPLAY====================

				break;
			case',':
				switchArray = false;
				break;
			case'f':
				//displays searched id
				cout << "\t\t\t searching..." << endl;
				cout << "Enter Id To Look For: " << endl;
				cin >> searchId;
				while (cin.fail())
				{
					cout << "Error" << endl;
					cin.clear();
					cin.ignore(256, '\n');
					cout << endl;
					cout << "Enter a number please: " << endl;
					cin >> searchId;
				}
				secondDynamicTree->search(searchId);
				break;
			case'e':
				//exits the application
				cout << "Exiting..." << endl;
				return 0;
			default:
				//default, activated due to improper input
				cout << "Enter One Of The Listed Options" << endl;
				break;
			}
		}
	}
}
//----Don't Hit-----


