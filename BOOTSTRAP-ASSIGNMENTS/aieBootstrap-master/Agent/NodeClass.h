#pragma once
#include <Vector2.h>
#include <vector>

class Edge;

enum itemType
{
	item,wall,clear
};

struct Node
{

	Node()
	{
		position = Vector2();
		gScore = 1;
		parent = nullptr;
		ofType = clear;
	}

	Node(Vector2 specificPosition, itemType NAME, int m_gScore);

	Vector2 position;
	float gScore;
	Node* parent;
	itemType ofType;

	//std::vector<Edge>connections;


	Node *newNode = new Node();
	/*NODE-ENUM-BLACK (VECTOR2 Position) SCORE, NODE_ENUM-WHITE*/
	/*NODE-ENUM-WHITE, NODE_ENUM-WHITE, NODE_ENUM-BLUE*/
	/*NODE-ENUM-WHITE,*/
	/*NODE-ENUM-WHITE,*/
	/*NODE-ENUM-BLACK,*/
};



void CreateGridOfNodes(Node *node)
{
	int rows = 1280;
	int columns = 720;

	//writes nodes in grid
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			Node* newNode = new Node((Vector2(i * 10, j *10)), clear, 1);
		}
	}
}