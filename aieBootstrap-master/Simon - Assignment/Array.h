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

	Bar *ReturnRoot();

	Array();
	~Array();

	//void draw(aie::Renderer2D *renderer, Bar *selected = nullptr);

	Bar CheckIfLost(Bar *Data, Bar*current, bool checkedTrue);

	bool isEmpty() const;
	void insert(string value);

	void CheckIfWon(Bar *Data, bool checkedTrue);
	void Remove()
	{
		Bar* Data = new Bar(0, 0, 0, 0, "");
		Bar* current = nullptr;
		current = ReturnRoot();
		while (current->getRight() != nullptr)
		{
			current->setData(Data->getData());
			current = current->getRight();
		}
		current->setData(Data->getData());
		//current->setData(Data->getData());
	}

	//void InputInsert(string value);
	//Bar *  CheckifWon(string value);

	//void draw(aie::Renderer2D *renderer, Bar *pNode, int x, int y, int horizontalSpacing, Node *selected = nullptr);

	//Bar *root;
};
