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


	//Print
	doubleList->PushFront(23);
	doubleList->PushFront(24);
	doubleList->PushFront(25);
	doubleList->PushFront(26);

	doubleList->PushBack(15);
	doubleList->PushBack(15);
	doubleList->PushBack(19);

	doubleList->PopFront();
	doubleList->PopBack();
	doubleList->InsertAfter(head+2);
	//doubleList->PushBack(25);

	std::cout << "Printing: " << std::endl;
	doubleList->Print();

}


