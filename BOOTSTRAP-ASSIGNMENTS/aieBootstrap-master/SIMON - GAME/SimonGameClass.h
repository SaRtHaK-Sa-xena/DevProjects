#pragma once
#include "Square.h"

class SimonGameClass
{
public:

	Square* ReturnRoot();


	SimonGameClass();
	~SimonGameClass();

	//void Selector(aie::Renderer2D* renderer);
	//void insert(int x, int y, int z);
	void insert(string value);
	//Square * CheckIfWon(string value);


private:
	Square* root;
};