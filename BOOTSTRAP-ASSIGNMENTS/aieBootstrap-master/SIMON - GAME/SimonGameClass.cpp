#include "SimonGameClass.h"
#include <string>
#include <iostream>

using namespace std;

SimonGameClass::SimonGameClass()
{
	root = nullptr;
}


SimonGameClass::~SimonGameClass()
{
}


//void SimonGameClass::insert(int x, int y, int z)
//{
//	if (root == nullptr)
//	{
//		root = new Square(x,y,z,210);
//	}
//	else
//	{
//		Square* Array[4] = {};
//		Square* current = nullptr;
//		current = root;
//
//		current->setRight();
//	}
//}


void SimonGameClass::insert(string a_nValue)
{
	/*int x;
	int y;
	int z;
	if (a_nValue == "RED")
	{
		x = 600;
		y = 150;
		z = 200;
	}
	else if (a_nValue == "BLUE");
	{
		x = 600;
		y = 150;
		z = 200;
	}*/


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
				//current->SetValue(-1);
				break;
			}
			current = current->getRight();
		}
	}
}
