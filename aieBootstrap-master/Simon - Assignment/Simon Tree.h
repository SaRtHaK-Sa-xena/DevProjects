#pragma once
#include "Bar.h"

class SimonTree
{
public:

	SimonTree();
	~SimonTree();

	void insert(Bar *current,int x, int y, int z, int c); //automatically input values, like red, red, blue

	void draw(aie::Renderer2D *renderer, Bar* selected = nullptr); //Selects colour for square

private:

	//Draws the Square at the Left,Right,Top, or Bottom ---Makes it flicker----
	void draw(aie::Renderer2D *renderer, 
		Bar* current, 
		int width, 
		int height, 
		int spacing, 
		Bar* selected = nullptr);

	Bar *Root; //the first Colour
};