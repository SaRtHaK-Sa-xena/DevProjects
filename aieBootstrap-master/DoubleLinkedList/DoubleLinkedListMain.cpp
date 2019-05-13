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

	//doubleList->PopFront();
	//doubleList->PopBack();
	std::cout << "Printing Before Array: " << std::endl;
	doubleList->Print();
	std::cin.get();
	doubleList->Remove(24);
	//Node* temp = new Node();
	//doubleList->InsertAfter(temp,2);
	//doubleList->PushBack(25);

	std::cout << "Printing After Array: " << std::endl;
	doubleList->Print();

}


