#include "pch.h"
#include "Array.h"
#include <string>

// constructor
ArrayClass::ArrayClass()
{
	root = nullptr;
}


//helper function returning root
NodeClass* ArrayClass::returnRoot()
{
	return root;
}


//adds new element in array
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
				//adds another right to current
				current->setRight(new NodeClass(value));
				break;
			}
			current = current->getRight();
		}
	}
}


// displays the values of each element
void ArrayClass::display()
{
	if (!Empty())
	{
		NodeClass* current = returnRoot();

		if (current == nullptr)
		{
			std::cout << "No elements in array...\n" << std::endl;
			std::cout << "--------------------------------------" << std::endl;
		}
		else
		{
			//displays entire array
			int i = 0;
			while (current->getRight() != nullptr)
			{
				i++;
				std::cout << "Data:" << i << " " << current->getData() << std::endl;
				current = current->getRight();
			}
			i = i + 1; //iterate through array
			std::cout << "Data:" << i << " " << current->getData() << std::endl;
		}
	}
	else
	{
		std::cout << "No elements in array\n" << std::endl;
		std::cout << "-------------------------------" << std::endl;
	}
}


//finds value using value
void ArrayClass::search(int a_value)
{
	if (!Empty())
	{
		int i = 1;
		NodeClass *current = returnRoot();
		bool found = false;

		//while not at end
		while (current->getRight() != nullptr)
		{
			//if value equal to inputed value
			if (current->getData() == a_value)
			{
				//return that index position with value
				std::cout << "found in position " << i << ":" << std::endl;
				std::cout << current->getData() << std::endl;
				found = true;
			}
			//otherwise increment
			i++;
			current = current->getRight();
		}
		//finds if curren value equal to value
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
				//only case where list appends to add new value
				std::cout << "Increased Size of Array to include value" << std::endl;
				insert(a_value);
			}
			else
			{
				//otherwise just display the array
				display();
			}
		}
	}
	else
	{
		std::cout << "No elements in array\n" << std::endl;
		std::cout << "-------------------------------" << std::endl;
	}
}


//sorts elements by value held
void ArrayClass::sort()
{
	if (!Empty())
	{
		int temp;
		int temp2;

		NodeClass* current = root;
		NodeClass* currentRight = current->getRight();
		bool swap = false;
		
		//uses a bubbleSort
		//while not at end
		while (current->getRight() != nullptr)
		{
			//commit swap if swap needed
			if (swap)
			{
				current = root;
				currentRight = current->getRight();
			}
			//if value greater than next value
			if (current->getData() > currentRight->getData())
			{
				temp = current->getData();
				temp2 = currentRight->getData();


				current->setData(temp2);
				currentRight->setData(temp);
				//commit swap
				swap = true;
			}
			else //otherwise continue iterating through
			{
				current = current->getRight();
				currentRight = current->getRight();
				//don't commit swap
				swap = false;
			}
		}
	}
	else //if no elements leave
	{
		std::cout << "No elements in array\n" << std::endl;
		std::cout << "-------------------------------" << std::endl;
	}
}


//removes last element in array
void ArrayClass::popBack()
{

	if (!Empty())
	{

		NodeClass *current = returnRoot();

		// iterates until the second last element
		while (current->getRight()->getRight() != nullptr)
		{
			// current goes down the line
			current = current->getRight();
		}
		// after current =to second last element set last item
		// to nullptr
		current->setRight(nullptr);

		// then delete it
		delete current->getRight();
	}
	else
	{
		std::cout << "No elements in array\n" << std::endl;
		std::cout << "-------------------------------" << std::endl;
	}
}


//removes first element in array
void ArrayClass::popFront()
{
	if (!Empty())
	{

		//current will = first item in array
		NodeClass* current = returnRoot();

		//make root equal to item after first
		root = current->getRight();

		//delete previous root
		delete current;
	}
	else
	{
		std::cout << "No elements in array\n" << std::endl;
		std::cout << "-------------------------------" << std::endl;
	}
}


//checks if there is an element in the array
bool ArrayClass::Empty()
{
	NodeClass* current = returnRoot();

	//first element =to nullptr
	if (current == nullptr)
	{
		//if no elements in array
		return true;
	}

	else
	{
		return false;
	}
}

//Sets Values on selected index
void ArrayClass::setOnIndex()
{
	int index;
	NodeClass* current = returnRoot();

	std::cout << "Enter which index to input value on..." << std::endl;
	std::cout << "Index: ";
	std::cin >> index;

	//sets index to chosen input
	for (int i = 1; i < index; i++)
	{
		current = current->getRight();
	}

	int newAmount;

	std::cout << "Enter Which value to enter in that index: " << std::endl;
	std::cin >> newAmount;

	//sets that new amount on selected index
	current->setData(newAmount);

}

//copies contents of array and transfers them onto the other array
void ArrayClass::CopyContructor(ArrayClass * dynamicArray)
{

	NodeClass* current = returnRoot();
	dynamicArray->root = current;
	NodeClass* dynamicCurrent = root;

	//while not at end of list
	while (current->getRight() != nullptr)
	{
		//iterate
		current = current->getRight();
		//set each element to corresponding element in other array
		dynamicCurrent->setRight(current);
		//iterate through other array
		dynamicCurrent = dynamicCurrent->getRight();
	}
}

//clears entire array
void ArrayClass::clear()
{
	if (!Empty())
	{
		// while root points to an element
		while (root->getRight() != nullptr)
		{
			//let current = root
			NodeClass* current = returnRoot();

			//root will move to second item
			root = current->getRight();

			//delete the previous root
			delete current;
		}

		//after root is left
		//root will be null
		root = nullptr;

		//then deleted
		delete root;
	}
	else
	{
		std::cout << "No elements in array\n" << std::endl;
		std::cout << "-------------------------------" << std::endl;
	}
}


//manually set array size
void ArrayClass::manualSetter()
{
	int amount = 0;
	std::cout << "Enter size of array:" << std::endl;

	//appends to that many elements
	std::cin >> amount;
	
	//sets default for all
	for (int i = 0; i < amount; i++)
	{
		insert(0);
	}
}

