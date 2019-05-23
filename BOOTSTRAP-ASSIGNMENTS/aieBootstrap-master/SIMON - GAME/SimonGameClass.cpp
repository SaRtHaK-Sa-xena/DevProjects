#include "SimonGameClass.h"


void SimonGameClass::Selector(aie::Renderer2D * renderer)
{

}

void SimonGameClass::insert(int x, int y, int z)
{
	if (root == nullptr)
	{
		root = new Square(x,y,z,210);
	}
	else
	{
		Square* Array[4] = {};
		Square* current = nullptr;
		current = root;

		current->setRight();
	}
}
