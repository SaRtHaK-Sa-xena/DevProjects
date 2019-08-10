// DynamicArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Array.h"


using namespace std;

int main()
{
	ArrayClass* DynamicTree = new ArrayClass();
	int value;
	bool cont = true;
	char choice = '0';
	int i = 0;
	int t1 = 555;
	int t2 = 222;
	int searchId;
	NodeClass* current;
	NodeClass* currentRight;
	
	while (cont)
	{
		cout << "What Do you want to Do? " << endl;
		cout << "---(a)dd---(d)isplay---(s)ort--(f)ind--(e)xit---" << endl;
		cin >> choice;
		switch (choice)
		{
		case'a':
			cout << "\t\t\t adding..." << endl;
			cout << "Enter Value To Insert" << endl;
			cin >> value;
			while (cin.fail())
			{
				cout << "Error" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cout << endl;
				cout << "Enter a number please: " << endl;
				cin >> value;
			}
			DynamicTree->insert(value);
			break;
		case'd':
			cout << "\t\t\t displaying..." << endl;
			DynamicTree->display();
			break;
		case's':
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
			cout << "Exiting..." << endl;
			DynamicTree->popFront();
			//return 0;
		default:
			cout << "Enter One Of The Listed Options" << endl;
			break;
		}
	}
}


