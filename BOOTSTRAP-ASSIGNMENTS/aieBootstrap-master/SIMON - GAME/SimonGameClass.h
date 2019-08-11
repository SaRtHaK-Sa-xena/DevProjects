#pragma once
#include "Square.h"

class SimonGameClass
{
public:

	Square* ReturnRoot();


	SimonGameClass();
	~SimonGameClass();

	// used to insert colour
	void insert(string value);


private:
	Square* root;
};