// DynamicArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Array.h"


using namespace std;

int main()
{
	ArrayClass* DynamicTree = new ArrayClass();
	ArrayClass * secondDynamicTree = new ArrayClass();
	int value;
	bool cont = true;
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
		cout << "(d)isplay---(s)ort---(f)ind---(c)popBack---(x)popFront---(m)anual---(z)clear---(b)setIndex---(,)copyConstructor---(e)xit---" << endl;
		cin >> choice;
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
		}
	}
}


