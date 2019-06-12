#pragma once

class Node
{
public:
	
	Node(int value);
	~Node();

	//Changes Colour To White
	void SetValue(float value);
	//changes Colour to White(-1 = White || 100 = Original)


	//To Set Values
	void setRight(Node* current);
	void setLeft(Node *current);

	//To Check Values 
	Node *getRight();
	Node *getLeft();



	void setData(int value);
	int getData();

	float current_value;

private:
	Node *m_right = nullptr;
	Node *m_left = nullptr;
	int m_value;
};