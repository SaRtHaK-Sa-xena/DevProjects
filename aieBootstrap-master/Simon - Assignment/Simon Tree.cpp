#include "Simon Tree.h"

SimonTree::SimonTree()
{
}

SimonTree::~SimonTree()
{
}

void SimonTree::insert(Bar *current, int x, int y, int z, int c)
{
	if (Root == nullptr)
	{
		Root = new Bar(600,600,200,210);
	}
	else
	{
		current = nullptr;
		current = Root;
		if (current != nullptr)
		{
			current->SetRight(new Bar(x, y, z, c));
		}
	}
}

void SimonTree::draw(aie::Renderer2D * renderer, Bar * selected)
{
	draw(renderer, Root, 600, 600, 210, selected);
}

void SimonTree::draw(aie::Renderer2D * renderer, Bar * current, int width, int height, int spacing, Bar * selected)
{
	if (width == 600 && height == 600)
	{

	}
}
