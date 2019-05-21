#pragma once
#include "Bar.h"



class Array
{
private:
	//string Array[4] = { "red", "blue", "green","yellow" };
	//Node *head, *tail;
	//int m_size;
	Bar* m_pRoot;


public:
	//void getArray();
	//void setNewArray();

	//int DifficultySet();

	//void Insert(string Value);
//============================================
	Array();
	~Array();

	//void draw(aie::Renderer2D *renderer, Bar *selected = nullptr);

	bool isEmpty() const;
	void insert(string value);

	//void InputInsert(string value);
	Bar *  CheckifWon(string value);

	//void draw(aie::Renderer2D *renderer, Bar *pNode, int x, int y, int horizontalSpacing, Node *selected = nullptr);

	//Bar *root;
};
