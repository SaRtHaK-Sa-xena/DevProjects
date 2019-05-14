// DoubleLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Node.h"
#include "DoubleLinkedList.h"
#include "time.h"



int main()
{
	DoubleLinkedList *doubleList = new DoubleLinkedList();
	std::cin.get();



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