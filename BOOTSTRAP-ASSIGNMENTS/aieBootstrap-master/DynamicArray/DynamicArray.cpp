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
	NodeClass* current;
	NodeClass* currentRight;
	
	while (cont)
	{
		cout << "What Do you want to Do? " << endl;
		cout << "---(a)dd---(d)isplay---(s)ort---(e)xit---" << endl;
		cin >> choice;
		switch (choice)
		{
		case'a':
			cout << "\t\t\t adding..." << endl;
			cout << "Enter Value To Insert" << endl;
			cin >> value;
			DynamicTree->insert(value);
			break;
		case'd':
			cout << "\t\t\t displaying..." << endl;
			current = DynamicTree->returnRoot();
			while (current->getRight() != nullptr)
			{
				i++;
				cout << "Data:" << i << " " << current->getData() << endl;
				current = current->getRight();
			}
			cout << "Last Entered Data: " << current->getData() << endl;
			i = 0;
			//cout << "Node Data 1:" << current->getData() << endl;
			break;
		case's':
			cout << "\t\t\t Sorting..." << endl;
			DynamicTree->sort();

			//================SORT====================
			//current = DynamicTree->returnRoot();
			//currentRight = current->getRight();
			//
	
			//while (current->getRight() != nullptr)
			//{
			//	if (current->getData() > currentRight->getData())
			//	{
			//		t1 = current->getData(); // t1 = 5
			//		t2 = currentRight->getData(); // t2 = 1


			//		current->setData(t2); //set first to second data
			//		currentRight->setData(t1); //set second data to first data
			//		std::cout << "Set..." << std::endl;
			//		//t3->setData(t1->getData());

			//		//current->getRight()->setData(t1->getData());
			//	}
			//	else
			//	{
			//		current = current->getRight();
			//	}
			//}
			//================SORT====================

			/*t1 = current->getData();
			t2 = currentRight->getData();*/

			
			

			//==============DISPLAY====================
			current = DynamicTree->returnRoot();
			cout << "Reached End" << endl;
			while (current->getRight() != nullptr)
			{
				i++;
				cout << "Data:" << i << " " << current->getData() << endl;
				current = current->getRight();
			}
			cout << "Data: " << current->getData() << endl;
			i = 0;
			//==============DISPLAY====================

			break;
		case'e':
			cout << "Exiting..." << endl;
			return 0;
		default:
			cout << "Enter One Of The Listed Options" << endl;
			break;
		}
	}
}


