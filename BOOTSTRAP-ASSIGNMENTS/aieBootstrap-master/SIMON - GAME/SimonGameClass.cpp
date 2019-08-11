#include "SimonGameClass.h"
#include <string>
#include <iostream>

using namespace std;

//helper function used to retrieve root
Square* SimonGameClass::ReturnRoot()
{
	return root;
}


SimonGameClass::SimonGameClass()
{
	root = nullptr;
}


SimonGameClass::~SimonGameClass()
{
}


//used to insert colour
void SimonGameClass::insert(string a_nValue)
{
	


	if (root == nullptr)
	{
		root = new Square(0, 0, 0, 210, a_nValue);
	}
	else
	{
		Square* current = nullptr;
		current = root;

		//iterate towards the right until the right == null, then insert node there
		while (current != nullptr)
		{
			if (current->getRight() == nullptr)
			{
				current->setRight(new Square(0, 0, 0, 0, a_nValue)); //has position 0, and string colour of something
				break;
			}
			current = current->getRight();
		}
	}
}
