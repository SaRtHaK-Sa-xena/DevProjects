#include "pch.h"
#include "Array.h"
#include <string>

ArrayClass::ArrayClass()
{
	root = nullptr;
}

NodeClass* ArrayClass::returnRoot()
{
	return root;
}

void ArrayClass::insert(int value)
{
	if (root == nullptr)
	{
		root = new NodeClass(value);
	}
	else
	{
		NodeClass* current = nullptr;
		current = root;

		while (current != nullptr)
		{
			if (current->getRight() == nullptr)
			{
				current->setRight(new NodeClass(value));
				break;
			}
			current = current->getRight();
		}
	}
}

void ArrayClass::display()
{
	NodeClass* current = returnRoot();
	int i = 0;
	while (current->getRight() != nullptr)
	{
		i++;
		std::cout << "Data:" << i  << " " << current->getData() << std::endl;
		current = current->getRight();
	}
	i = i + 1;
	std::cout << "Data:" << i << " " << current->getData() << std::endl;
}

void ArrayClass::search(int a_value)
{
	int i = 1;
	NodeClass *current = returnRoot();
	bool found = false;


	while (current->getRight() != nullptr)
	{
		if (current->getData() == a_value)
		{
			std::cout << "found in position " << i << ":" << std::endl;
			std::cout << current->getData() << std::endl;
			found = true;
		}
		i++;
		current = current->getRight();
	}
	if (current->getData() == a_value)
	{
		std::cout << "found in position " << i << ":" << std::endl;
		std::cout << current->getData() << std::endl;
		found = true;
	}
	if (found == false)
	{
		std::cout << "The Number: " << "[" << a_value << "]" << " Does not exist in the list" << std::endl;
		std::cout << "Would You Like To Add it to the list? " << "\t\t (y/n)" << std::endl;
		std::string option;
		std::cin >> option;
		if (option == "y")
		{
			insert(a_value);
		}
		else
		{
			display();
		}
	}
}


void ArrayClass::sort()
{
	/*NodeClass *begin = returnRoot();
	NodeClass *temp = begin->getRight();
	NodeClass* temp2 = temp->getRight();
	bool reset = true;

	while (begin->getRight() != nullptr)
	{
		if (reset == true)
		{
			begin = returnRoot();
			temp = begin->getRight();
			temp2 = temp->getRight();
		}

		if (begin->getData() > temp->getData())
		{
			begin->setRight(temp2);

		}
	}*/


	//NodeClass* current = returnRoot();
	//NodeClass* currentRight = current->getRight();
	//int t1;
	//int t2;

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
	int temp;
	int temp2;

	NodeClass* current = root;
	NodeClass* currentRight = current->getRight();
	bool swap = false;
	//NodeClass* current = root; // current = 1
	//NodeClass* currentRight; // current = 2 // currentRight = current->getRight()
	//int t2 = current->getData(); // t2 = 1
	//int t1 = current->getRight()->getData(); // t1 = 2

	//current->setData(t1); // 1 = 2
	//currentRight = current->getRight(); // which is equal to 2
	//currentRight->setData(t2); // t2 = 1 so 1

	while (current->getRight() != nullptr)
	{
		if (swap)
		{
			current = root;
			currentRight = current->getRight();
		}
		if (current->getData() > currentRight->getData())
		{
			temp = current->getData();
			temp2 = currentRight->getData();


			current->setData(temp2);
			currentRight->setData(temp);
			swap = true;
		}
		else
		{
			current = current->getRight();
			currentRight = current->getRight();
			swap = false;
		}
	}
}
