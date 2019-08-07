#pragma once
#include "BehaviourClass.h"
struct Edge;

enum itemType
{
	item,wall,clear
};



struct Node
{

	Node()
	{
		position = Vector2(); //holds position
		gScore = 1; //g score of 1
		parent = nullptr; //no parent
		ofType = clear; //type
		isChecked = false;
	}

	//manually set the node's position, type, score
	Node(Vector2 specificPosition, itemType NAME, int m_gScore);

	// Sets the type to Walls
	Node(Vector2 specificPosition, itemType Name)
	{

		position = specificPosition;
		ofType = wall;
	}

	bool CheckInList(std::vector<Node*>List, int &index);

	bool operator==(Node &other)
	{
		return this->position.m_x == other.position.m_x && this->position.m_y == other.position.m_y;
	}

	bool operator!=(Node &other)
	{
		return !( this->position.m_x == other.position.m_x && this->position.m_y == other.position.m_y) ;
	}

	//returns topNode
	Node* getTopNode();

	//returns bottomNode
	Node* getBottomNode();

	//returns leftNode
	Node* getLeftNode();

	//returns rightNode
	Node* getRightNode();


	void wallSetter()
	{
		//amount to be incremented by
		int incrementer = 30;

		//how many nodes
		int amount = 4;
		for (int i = 0; i < amount; i++)
		{
			for (int x = 0; x < 1280; x++)
			{
				for (int y = 0; y < 720; y++)
				{
					//node sets for position of walls, and gives type of wall
					Node *setterNode = new Node((Vector2(14 * incrementer, y)), wall);
				}
			}
			//for(int)
		}



	}

	Vector2 position;
	float gScore;
	Node* parent;
	itemType ofType;
	bool isChecked;

	//holds connections
	std::vector<Edge*>connections;


	//has the amount of openList
	std::vector<Node*>openList;


	// has the amount of closedList
	std::vector<Node*>closedList;

	// Vector with walls


	//SetArray

	/*NODE-ENUM-BLACK (VECTOR2 Position) SCORE, NODE_ENUM-WHITE*/
	/*NODE-ENUM-WHITE, NODE_ENUM-WHITE, NODE_ENUM-BLUE*/
	/*NODE-ENUM-WHITE,*/
	/*NODE-ENUM-WHITE,*/
	/*NODE-ENUM-BLACK,*/
};


//retuns path to final Node
std::vector<Node*> dijkstrasSeatch(Node *startNode, Node *endNode, Agent* finder, std::vector<Node*>nodeWall);
