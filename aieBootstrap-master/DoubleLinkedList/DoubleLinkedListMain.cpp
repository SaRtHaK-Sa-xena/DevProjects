// DoubleLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Node.h"
#include "DoubleLinkedList.h"
#include <string>
#include "time.h"
using namespace std;

void InsertValue(DoubleLinkedList *list);
void BeginningOfIterator(DoubleLinkedList *list, Node *temp);
void EndOfIterator(DoubleLinkedList *list);
void EraseThroughIterator(DoubleLinkedList* list);

int main()
{
	//=====================Initializing=======================
	DoubleLinkedList *doubleList = new DoubleLinkedList();
	bool cont = true;
	char choice = '0';
	int n;
	Node *node = nullptr;
	Node *node2 = nullptr;
	DoubleLinkedList::Iterator  temp = nullptr;
	int j = 0;
	int removeNumbers = doubleList->Count();
	//========================================================


	while (cont)
	{
		//display menu
		cout << endl;
		cout << endl;
		std::cout << "Would You Like To: " << std::endl;
		std::cout << "|PUSHFRONT(a)-			-PUSHBACK(b)" << "\n" << "INSERTAFTER(c)-			-BEGIN(d)" << "\n" << "END(e)-				-FIRST(f)"
			<< "\n\n|LAST(g)-			-COUNT(h)" << "\n" << "--ERASE(i)-			-REMOVE(j)" << "\n" << "-POPBACK(k)-			-POPFRONT(l)" << "\n" << "-CLEAR(m)" << std::endl;
		
		std::cout << "=============================" << endl;
		std::cout << "Sort Data? (y)" << std::endl;
		std::cin >> choice;

		//input function
		switch (choice)
		{
		case'a':
			std::cout << "\t\t\tPushing Front..." << endl;
			cout << "Enter Value: " << endl;
			cin >> n;
			while (cin.fail())
			{
				cout << "Error" << endl;
				cin.clear();
				cout << "Enter a Number: " << endl;
				cin.ignore(256, '\n');
				cin >> n;
			}
			doubleList->PushFront(n);
			std::cout << "Printing After List: " << std::endl;
			doubleList->Print();
			break;

		case'b':
			std::cout << "\t\t\tPushing Back..." << endl;//value moves to end
			cout << "Enter Value: " << endl;
			cin >> n;
			while (cin.fail())
			{
				cout << "Error" << endl;
				cin.clear();
				cout << "Enter a Number: " << endl;
				cin.ignore(256, '\n');
				cin >> n;
			}
			doubleList->PushBack(n);
			std::cout << "Printing After List: " << std::endl;
			doubleList->Print();
			break;

		case'c':
			std::cout << "\t\t\tInserting After..." << endl;//value inserted after node
			InsertValue(doubleList);
			std::cout << "Printing After List: " << std::endl;
			doubleList->Print();
			break;
			
		case'd':
			std::cout << "\t\t\tDisplaying From Begin..." << endl;//iterates
			if (doubleList->Count() > 1)
			{
				BeginningOfIterator(doubleList, node);
				std::cout << "Printing After List: " << std::endl;
				doubleList->Print();
			}
			break;

		case'e':
			std::cout << "\t\t\tDisplaying From End..." << endl;
			if (doubleList->Count() > 1)
			{
				EndOfIterator(doubleList);
				std::cout << "Printing After List: " << std::endl;
				doubleList->Print();
			}
			break;

		case'f':
			std::cout << "\t\t\tReturning First Value..." << endl;
			node = doubleList->First();
			std::cout << node->m_data << endl;
			break;

		case'g':
			std::cout << "\t\t\tReturning Last Value..." << endl;
			node = doubleList->Last();
			std::cout << node->m_data << endl;
			break;

		case'h':
			std::cout << "\t\t\tDisplaying Number Of Elements In List..." << endl;
			std::cout << "COUNT : " << doubleList->Count() << std::endl; //counts elements in list
			break;

		case'i':
			std::cout << "\t\t\tErasing From Iterator..." << endl;
			//temp = doubleList->Begin();
			doubleList->Erase(temp);
			std::cout << "Printing After List: " << std::endl;
			doubleList->Print();
			// takes in begin() and end()
			break;

		case'j':
			std::cout << "\t\t\tRemoving Value..." << endl;
			cout << "Which Value To Remove: " << endl;
			cin >> n;
			while (cin.fail())
			{
				cout << "Error" << endl;
				cin.clear();
				cout << "Enter a Number: " << endl;
				cin.ignore(256, '\n');
				cin >> n;
			}
			doubleList->Remove(n);
			std::cout << "Printing After List: " << std::endl;
			doubleList->Print();
			break;

		case'k':
			std::cout << "\t\t\tRemoving Last Element In List..." << endl;
			doubleList->PopBack();
			std::cout << "Printing After List: " << std::endl;
			doubleList->Print();
			break;

		case'l':
			std::cout << "\t\t\tRemoving First Element in List..." << endl;
			doubleList->PopFront();
			std::cout << "Printing After List: " << std::endl;
			doubleList->Print();
			break;

		case'm':
			std::cout << "\t\t\tClearing All elements in List..." << endl;
			doubleList->Clear();
			std::cout << "Printing After List: " << std::endl;
			doubleList->Print();
			break;

		case'y':
			std::cout << "\t\t\t Sorting List..." << endl;
			doubleList->Sort();
			std::cout << "======================" << endl;
			std::cout << "Printing List After: " << endl;
			doubleList->Print();
			cout << endl;
			break;

		case'p':
			return 0;

		default:
			cout << "Please Choose One Of The Options Listed" << endl;
			break;

		}
	}
	cont = false;
	return 0;


}

void InsertValue(DoubleLinkedList *list)
{
	//checks if list is empty
	if (!list->Empty())
	{
		//Function Attempt 1:
		//Asks for position, asks for value, adds it after that position and appends the array


		//value to be used as position
		int position;

		//value to be inserted after position
		int NumberToBeInserted;

		//ask for position

		cout << "Enter Position:" << endl;
		cin >> position;
		while (cin.fail())
		{
			cout << "Error" << endl;
			cin.clear();
			cout << "Enter a Number: " << endl;
			cin.ignore(256, '\n');
			cin >> position;
		}

		//check if the position equal to list
		if (position == list->Count())
		{
			int NumberToBeInserted;
			std::cout << "What Number To Place In That Position: " << std::endl;
			std::cin >> NumberToBeInserted;
			while (cin.fail())
				{
					cout << "Error" << endl;
					cin.clear();
					cout << "Enter a Number: " << endl;
					cin.ignore(256, '\n');
					cin >> NumberToBeInserted;
				}
			list->PushBack(NumberToBeInserted);
		}
		else if (position > list->Count())
		{
			std::cout << "Number entered exceeds list size by more than one..." << std::endl;
			std::cout << "---------------------------------------------------" << std::endl;
		}
		else
		{
			DoubleLinkedList::Iterator temp = list->First();
			
			//...move iterator up
			for (int i = 0; i < position-1; i++)
				{
					temp++;
				}

			int NumberToBeInserted;
			std::cout << "What Number To Place In That Position: " << std::endl;
			std::cin >> NumberToBeInserted;
			while (cin.fail())
				{
					cout << "Error" << endl;
					cin.clear();
					cout << "Enter a Number: " << endl;
					cin.ignore(256, '\n');
					cin >> NumberToBeInserted;
				}
			list->InsertAfter(temp.GetNode(), NumberToBeInserted);
		}


		//else
		//{
		//	//set iterator to First
		//	//move iterator to the position
		//	for (int i = 0; i < position; i++)
		//	{
		//		temp++;
		//	}
		//	cout << "What Number To Add: " << endl;
		//	cin >> NumberToBeInserted;
		//	while (cin.fail())
		//	{
		//		cout << "Error" << endl;
		//		cin.clear();
		//		cout << "Enter a Number: " << endl;
		//		cin.ignore(256, '\n');
		//		cin >> NumberToBeInserted;
		//	}
		//	list->InsertAfter(temp.GetNode(), NumberToBeInserted);
		//}
		//===========================================================



		//=Previous Attempt: 
		
		
		//value to be used
		//int value;

		////create string to take input
		//string inputFromUser;

		////call for input
		//cout << "Enter + if you wish to start from the beginning" << endl;
		//cout << "Enter - if you wish to start from the end" << endl;
		//cout << "Examples include: +2, -3" << endl;
		//cin >> inputFromUser;
		//
		//	if (inputFromUser[0] == '+')
		//	{
		//		//If it a plus
		//		DoubleLinkedList::Iterator temp = list->First(); //sets to become an iterator, and sets position to FIRST

		//		
		//		//string without the plus or minus
		//		string stringWithoutThePlusOrMinus = inputFromUser.erase(0, 1);

		//		
		//		//convert to an integer
		//		value = std::stoi(stringWithoutThePlusOrMinus);

		//		if (list->Count() >= value)
		//		{
		//			if (value == list->Count())
		//			{
		//				int NumberToBeInserted;
		//				std::cout << "What Number To Place In That Position: " << std::endl;
		//				std::cin >> NumberToBeInserted;
		//				while (cin.fail())
		//				{
		//					cout << "Error" << endl;
		//					cin.clear();
		//					cout << "Enter a Number: " << endl;
		//					cin.ignore(256, '\n');
		//					cin >> NumberToBeInserted;
		//				}
		//				list->PushBack(NumberToBeInserted);
		//			}
		//			else
		//			{
		//				//...move iterator up
		//				for (int i = 0; i < value; i++)
		//				{
		//					temp++;
		//				}

		//				int NumberToBeInserted;
		//				std::cout << "What Number To Place In That Position: " << std::endl;
		//				std::cin >> NumberToBeInserted;
		//				while (cin.fail())
		//				{
		//					cout << "Error" << endl;
		//					cin.clear();
		//					cout << "Enter a Number: " << endl;
		//					cin.ignore(256, '\n');
		//					cin >> NumberToBeInserted;
		//				}
		//				list->InsertAfter(temp.GetNode(), NumberToBeInserted);
		//			}
		//		}
		//		else
		//		{
		//			std::cout << "Number entered exceeds list size by more than one..." << std::endl;
		//			std::cout << "---------------------------------------------------" << std::endl;
		//		}
		//	}

		//	// if there is a minus at the beginning
		//	else if (inputFromUser[0] == '-')
		//	{
		//		//If it a minus
		//		DoubleLinkedList::Iterator temp = list->Last(); //sets to become an iterator, and sets position to FIRST
		//		
		//		//string without the plus or minus
		//		string stringWithoutThePlusOrMinus = inputFromUser.erase(0, 1);

		//		//convert to an integer
		//		value = std::stoi(stringWithoutThePlusOrMinus);

		//		if (list->Count() >= value)
		//		{
		//			if (value == list->Count())
		//			{
		//				int NumberToBeInserted;
		//				std::cout << "What Number To Place In That Position: " << std::endl;
		//				std::cin >> NumberToBeInserted;
		//				while (cin.fail())
		//				{
		//					cout << "Error" << endl;
		//					cin.clear();
		//					cout << "Enter a Number: " << endl;
		//					cin.ignore(256, '\n');
		//					cin >> NumberToBeInserted;
		//				}
		//				list->PushFront(NumberToBeInserted);
		//			}
		//			//since iterator doesn't need to move
		//			else if (value == 0)
		//			{
		//				int NumberToBeInserted;
		//				std::cout << "What Number To Place In That Position: " << std::endl;
		//				std::cin >> NumberToBeInserted;
		//				while (cin.fail())
		//				{
		//					cout << "Error" << endl;
		//					cin.clear();
		//					cout << "Enter a Number: " << endl;
		//					cin.ignore(256, '\n');
		//					cin >> NumberToBeInserted;
		//				}
		//				list->PushBack(NumberToBeInserted);
		//			}
		//			else
		//			{
		//				//...move iterator up using that integer
		//				for (int i = 0; i < (value); i++)
		//				{
		//					temp--;
		//				}

		//				int NumberToBeInserted;
		//				std::cout << "What Number To Place In That Position: " << std::endl;
		//				std::cin >> NumberToBeInserted;
		//				while (cin.fail())
		//				{
		//					cout << "Error" << endl;
		//					cin.clear();
		//					cout << "Enter a Number: " << endl;
		//					cin.ignore(256, '\n');
		//					cin >> NumberToBeInserted;
		//				}
		//				list->InsertAfter(temp.GetNode(), NumberToBeInserted);
		//			}
		//		}
		//		else
		//		{
		//			std::cout << "Number entered exceeds list size by more than one..." << std::endl;
		//			std::cout << "---------------------------------------------------" << std::endl;
		//		}
		//	}
		//	else
		//	{
		//		std::cout << "Number entered exceeds list size..." << std::endl;
		//		std::cout << "---------------------------------------------------" << std::endl;
		//	}
			//===============================================================================================
	}
	else
	{
		cout << "List Is Empty" << endl;
	}
}

void EraseThroughIterator(DoubleLinkedList *list)
{
	//checks if list is empty
	if (!list->Empty())
	{
		//value to be used
		int value;

		//create string to take input
		string inputFromUser;

		//call for input
		cout << "Enter + if you wish to start from the beginning" << endl;
		cout << "Enter - if you wish to start from the end" << endl;
		cout << "Examples include: +2, -3" << endl;
		cin >> inputFromUser;

		if (inputFromUser[0] == '+')
		{
			//If it a plus
			DoubleLinkedList::Iterator temp = list->Begin(); //sets to become an iterator, and sets position to FIRST


			//string without the plus or minus
			string stringWithoutThePlusOrMinus = inputFromUser.erase(0, 1);


			//convert to an integer
			value = std::stoi(stringWithoutThePlusOrMinus);

			if (list->Count() >= value)
			{
				if (value == list->Count())
				{
					list->PopBack();
				}
				else
				{
					//...move iterator up
					for (int i = 0; i < value; i++)
					{
						temp++;
					}

					list->Erase(temp.GetNode());
				}
			}
			else
			{
				std::cout << "Number entered exceeds list size by more than one..." << std::endl;
				std::cout << "---------------------------------------------------" << std::endl;
			}
		}

		// if there is a minus at the beginning
		else if (inputFromUser[0] == '-')
		{
			//If it a minus
			DoubleLinkedList::Iterator temp = list->End(); //sets to become an iterator, and sets position to FIRST

			//string without the plus or minus
			string stringWithoutThePlusOrMinus = inputFromUser.erase(0, 1);

			//convert to an integer
			value = std::stoi(stringWithoutThePlusOrMinus);

			if (list->Count() >= value)
			{
				if (value == list->Count())
				{
					list->PopFront();
				}
				//since iterator doesn't need to move
				else if (value == 0)
				{
					list->PopBack();
				}
				else
				{
					//...move iterator up using that integer
					for (int i = 0; i < (value); i++)
					{
						temp--;
					}

					list->Erase(temp.GetNode());
				}
			}
			else
			{
				std::cout << "Number entered exceeds list size by more than one..." << std::endl;
				std::cout << "---------------------------------------------------" << std::endl;
			}
		}
		else
		{
			std::cout << "Number entered exceeds list size..." << std::endl;
			std::cout << "---------------------------------------------------" << std::endl;
		}
	}
	else
	{
		cout << "List Is Empty" << endl;
	}
}


void BeginningOfIterator(DoubleLinkedList *list, Node* temp)
{
	if (!list->Empty())
	{
		DoubleLinkedList::Iterator current = list->Begin();
		int position;
		cout << "Enter Which Position To Display From the Beginning" << endl;
		cin >> position;
		while (cin.fail())
		{
			cout << "Error" << endl;
			cin.clear();
			cout << "Enter a Number: " << endl;
			cin.ignore(256, '\n');
			cin >> position;
		}
		for (int i = 0; i < position; i++)
		{
			current++;
		}
		temp = current.GetNode();
		std::cout << temp->m_data << endl;
	}
}

void EndOfIterator(DoubleLinkedList *list)
{
	if (!list->Empty())
	{
		DoubleLinkedList::Iterator current = list->End();
		int position;
		cout << "Enter Which Position To Display From the End" << endl;
		cin >> position;
		while (cin.fail())
		{
			cout << "Error" << endl;
			cin.clear();
			cout << "Enter a Number: " << endl;
			cin.ignore(256, '\n');
			cin >> position;
		}
		for (int i = 0; i < position; i++)
		{
			current--;
		}
		Node *temp = current.GetNode();
		std::cout << temp->m_data << endl;
	}
}
