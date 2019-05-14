// DoubleLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Node.h"
#include "DoubleLinkedList.h"
#include "time.h"
using namespace std;

void InsertValue(DoubleLinkedList *list);
void BeginningOfIterator(DoubleLinkedList *list, Node *temp);
void EndOfIterator(DoubleLinkedList *list);


int main()
{
	DoubleLinkedList *doubleList = new DoubleLinkedList();
	bool cont = true;
	char choice = '0';
	int n;
	Node *node = nullptr;
	DoubleLinkedList::Iterator  temp = nullptr;
	while (cont)
	{
		cout << endl;
		cout << endl;
		std::cout << "Would You Like To: " << std::endl;
		std::cout << "|PUSHFRONT(A)--PUSHBACK(B)--INSERTAFTER(C)--BEGIN(D)--END(E)--FIRST(F)"
			<< "\n\n|LAST(G)--COUNT(H)--ERASE(I)--REMOVE(J)--POPBACK(K)--POPFRONT(L)--CLEAR(M)" << std::endl;
		
		std::cin >> choice;
		switch (choice)
		{
		case'a':
			std::cout << "\t\t\tPushing Front..." << endl;
			cout << "Enter Value: " << endl;
			cin >> n;
			doubleList->PushFront(n);
			std::cout << "Printing After List: " << std::endl;
			doubleList->Print();
			break;

		case'b':
			std::cout << "\t\t\tPushing Back..." << endl;
			cout << "Enter Value: " << endl;
			cin >> n;
			doubleList->PushBack(n);
			std::cout << "Printing After List: " << std::endl;
			doubleList->Print();
			break;

		case'c':
			std::cout << "\t\t\tInserting After..." << endl;
			InsertValue(doubleList);
			std::cout << "Printing After List: " << std::endl;
			doubleList->Print();
			break;
			
		case'd':
			std::cout << "\t\t\tDisplaying From Begin..." << endl;
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
			std::cout << "COUNT : " << doubleList->Count() << std::endl;
			break;

		case'i':
			std::cout << "\t\t\tErasing From Iterator..." << endl;
			temp = doubleList->Begin();
			doubleList->Erase(temp);
			std::cout << "Printing After List: " << std::endl;
			doubleList->Print();
			break;

		case'j':
			std::cout << "\t\t\tRemoving Value..." << endl;
			cout << "Which Value To Remove: " << endl;
			cin >> n;
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
	DoubleLinkedList::Iterator temp = list->First(); //sets to become an iterator, and sets position to FIRST
	int size;
	std::cout << "Enter After Which Position: " << std::endl;
	std::cin >> size;
	//Increments forward depending on temp = temp->next
	for (int i = 0; i < size-1; i++)
	{
		//temp = temp->next;
		temp++;
	}
	int NumberToBeInserted;
	std::cout << "What Number To Place In Position: " << std::endl;
	std::cin >> NumberToBeInserted;
	list->InsertAfter(temp.GetNode(), NumberToBeInserted);
}
void BeginningOfIterator(DoubleLinkedList *list, Node* temp)
{
	DoubleLinkedList::Iterator current = list->Begin();
	int position;
	cout << "Enter Which Position To Display From the Beginning" << endl;
	cin >> position;
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
	for (int i = 0; i < position; i++)
	{
		current--;
	}
	Node *temp = current.GetNode();
	std::cout << temp->m_data << endl;
}



	//=====PUSHFRONT========
	//doubleList->PushFront(23);
	//doubleList->PushFront(24);
	//doubleList->PushFront(25);
	//doubleList->PushFront(26);
	//=====PUSHFRONT========

	//=====PUSHBACK========
	//doubleList->PushBack(15);
	//doubleList->PushBack(15);
	//doubleList->PushBack(19);
	//=====PUSHBACK========

	//=====POPFRONT && POPBACK========
	//doubleList->PopFront();
	//doubleList->PopBack();
	//=====POPFRONT && POPBACK========

	//===========PRINT============
	//std::cout << "Printing Before List: " << std::endl;
	//doubleList->Print();
	//===========PRINT=============


	//==========COUNT===================
	//std::cout << "COUNT : " << doubleList->Count() << std::endl;
	//==========COUNT===================


	//============INSERTAFTER=================
	//DoubleLinkedList::Iterator temp = doubleList->First(); //sets to become an iterator, and sets position to FIRST
	//int size;
	//std::cout << "Enter After Which Position: " << std::endl;
	//std::cin >> size;
	////Increments forward depending on temp = temp->next
	//for (int i = 0; i < size-1; i++)
	//{
	//	//temp = temp->next;
	//	temp++;
	//}
	//int NumberToBeInserted;
	//std::cout << "What Number To Place In Position: " << std::endl;
	//std::cin >> NumberToBeInserted;
	//doubleList->InsertAfter(temp.GetNode(), NumberToBeInserted);
	//===========PRINT=============
	//std::cout << "Printing After List: " << std::endl;
	//doubleList->Print();
	//===========PRINT=============
	//============INSERTAFTER=================


	//====================BEGIN========================
	//DoubleLinkedList::Iterator i = doubleList->Begin();
	//i++;
	//i++;
	//Node *temp = i.GetNode();
	//std::cout << temp->m_data;
	//====================BEGIN========================


	//====================LAST========================
	//DoubleLinkedList::Iterator i = doubleList->Last();
	//i--;
	//i--;
	//i--;
	//Node *temp = i.GetNode();
	//std::cout << temp->m_data;
	//====================LASt========================


	//===========CLEAR=============
	//doubleList->Clear();
	//===========CLEAR=============


	//===========PRINT=============
	//std::cout << "Printing After List: " << std::endl;
	//doubleList->Print();
	//===========PRINT=============


	//============FIRST==================
	//Node *node = doubleList->First();
	//std::cout << node->m_data;
	//============FIRST==================

	//============LAST==================
	//Node *node = doubleList->Last();
	//std::cout << node->m_data;
	//============LAST==================


	//===================ERASE====================
	//DoubleLinkedList::Iterator  temp = doubleList->Begin();
	//doubleList->Erase(temp);
	//std::cout << "Printing After List: " << std::endl;
	//doubleList->Print();
	//===================ERASE====================
	//solution. properties, common properties, add multiple start files