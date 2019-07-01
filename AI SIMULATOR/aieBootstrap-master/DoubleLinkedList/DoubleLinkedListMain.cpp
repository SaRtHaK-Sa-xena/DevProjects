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
		cout << endl;
		cout << endl;
		std::cout << "Would You Like To: " << std::endl;
		std::cout << "|PUSHFRONT(A)--PUSHBACK(B)--INSERTAFTER(C)--BEGIN(D)--END(E)--FIRST(F)"
			<< "\n\n|LAST(G)--COUNT(H)--ERASE(I)--REMOVE(J)--POPBACK(K)--POPFRONT(L)--CLEAR(M)" << std::endl;
		
		std::cout << "Sort Data? (Y)" << std::endl;
		std::cin >> choice;
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
			BeginningOfIterator(doubleList, node);
			std::cout << "Printing After List: " << std::endl;
			doubleList->Print();
			break;

		case'e':
			std::cout << "\t\t\tDisplaying From End..." << endl;
			EndOfIterator(doubleList);
			std::cout << "Printing After List: " << std::endl;
			doubleList->Print();
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
			//====================Delete=========================
			/*node2 = doubleList->First();
			for (int i = 0; i < doubleList->Count(); i++)
			{
				if (node2->m_data == n)
				{
					j++;
				}
				node2 = node2->next;
			}
			for (int i = 0; i < j; i++)
			{
				doubleList->Remove(n);
			}*/
			//====================Delete=========================
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
	if (!list->Empty())
	{
		string input;
		cout << "From What Position In The List (FIRST) or (LAST)" << endl;
		cin >> input;
		if (input == "FIRST")
		{
			DoubleLinkedList::Iterator temp = list->First(); //sets to become an iterator, and sets position to FIRST
			int size;
			std::cout << "Enter" << "\n + : " << std::endl;
			std::cin >> size;
			while (cin.fail())
			{
				cout << "Error" << endl;
				cin.clear();
				cout << "Enter a Number: " << endl;
				cin.ignore(256, '\n');
				cin >> size;
			}
			//Increments forward depending on temp = temp->next
			for (int i = 0; i < size - 1; i++)
			{
				//temp = temp->next;
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
		else if (input == "LAST")
		{
			DoubleLinkedList::Iterator temp = list->Last();
			int size;

			cout << "Enter" << "\n - : " << endl;
			cin >> size;

			while (cin.fail())
			{
				cout << "Error" << endl;
				cin.clear();
				cout << "Enter a Number: " << endl;
				cin.ignore(256, '\n');
				cin >> size;
			}

			int NumberToBeInserted;
			//Increments forward depending on temp = temp->next
			for (int i = 0; i < size; i++)
			{
				//temp = temp->next;
				temp--;
			}
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
	}
	else
	{
		cout << "List Is Empty" << endl;
	}
}
void BeginningOfIterator(DoubleLinkedList *list, Node* temp)
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
void EndOfIterator(DoubleLinkedList *list)
{
	DoubleLinkedList::Iterator current = list->End();
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
		current--;
	}
	Node *temp = current.GetNode();
	std::cout << temp->m_data << endl;
}
