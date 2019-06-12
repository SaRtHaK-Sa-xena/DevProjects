#pragma once
#include "Node.h"


class DynamicArrayClass
{
public:

	//Node* ReturnRoot();


	DynamicArrayClass();
	~DynamicArrayClass();

	//void Selector(aie::Renderer2D* renderer);
	//void insert(int x, int y, int z);
	void insert(int a_nValue);
	void remove(int a_nValue);
	//Square * CheckIfWon(string value);


private:
	Node* root;
};