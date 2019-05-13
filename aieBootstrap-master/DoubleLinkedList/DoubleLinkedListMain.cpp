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


	//=====PUSHFRONT========
	doubleList->PushFront(23);
	doubleList->PushFront(24);
	doubleList->PushFront(25);
	doubleList->PushFront(26);
	//=====PUSHFRONT========

	//=====PUSHBACK========
	doubleList->PushBack(15);
	doubleList->PushBack(15);
	doubleList->PushBack(19);
	//=====PUSHBACK========

	//=====POPFRONT && POPBACK========
	//doubleList->PopFront();
	//doubleList->PopBack();
	//=====POPFRONT && POPBACK========

	//===========PRINT============
	std::cout << "Printing Before List: " << std::endl;
	doubleList->Print();
	//===========PRINT=============


	std::cin.get();
	//==========COUNT===================
	//std::cout << "COUNT : " << doubleList->Count() << std::endl;
	//==========COUNT===================


	//Node* temp = new Node();
	//doubleList->InsertAfter(temp,2);

	//===========CLEAR=============
	doubleList->Clear();
	//===========CLEAR=============

	//===========PRINT=============
	std::cout << "Printing After List: " << std::endl;
	doubleList->Print();
	//===========PRINT=============

}


