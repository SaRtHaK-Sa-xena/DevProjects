#include "NodeClass.h"
#include "AgentClass.h"
#include <iostream>




Node::Node(Vector2 specificPosition, itemType NAME, int m_gScore)
{
	position = specificPosition;
	ofType = NAME;
	gScore = m_gScore;
}

Node* Node::getTopNode()
{
	Node *topNode = this;
	topNode->position.m_y = this->position.m_y + 30;
	return topNode; //star
}

Node* Node::getBottomNode()
{
	Node *bottomNode = this;
	bottomNode->position.m_y = this->position.m_y - 30;
	return bottomNode; //star
}

Node* Node::getLeftNode()
{
	Node *leftNode = this;
	leftNode->position.m_x = this->position.m_x - 30;
	return leftNode; //star
}

Node* Node::getRightNode()
{
	Node *rightNode = this;
	rightNode->position.m_x = this->position.m_x + 30;
	return rightNode; //star
}

void CreateGridOfNodes(Node *node, Node *FirstListOfNodes[1280][720])
{
	int rows = 1280;
	int columns = 720;

	//writes nodes in grid
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			Node* newNode = new Node((Vector2(i * 30, j *30)), clear, 1); //each node created with type,score,and position
			FirstListOfNodes[i][j] = newNode;
		}
	}

	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < columns; y++)
		{
			std::cout << "Position: " << "(" << FirstListOfNodes[x][y] << "," << ")";
		}
	}
	
}

std::vector<Node*> dijkstrasSeatch(Node *startNode, Node *endNode, Agent* finder, std::vector<Node*>nodeWall)
{
	//startNode equal to finder's position
	startNode->position = finder->GetPosition();
	
	//startNode will have gScore of 1
	startNode->gScore = 1;

	//will have no parent since it's the start
	startNode->parent = nullptr;

	if (startNode == nullptr || endNode == nullptr)
	{
		std::cout << "Error!!" << std::endl;
	}

	if (startNode == endNode)
	{
		std::vector<Node*>Default;
		return Default;
	}

	std::vector<Node*>openList;
	std::vector<Node*>closedList;

	openList.push_back(startNode);

	//while openlist has anything
	bool foundNode = false;

	while (openList.size() != 0 && foundNode )
	{

		for (int i = 0; i < openList.size(); i++)
		{
			Node* first = openList[i];
			//this sorts it
			if (first->gScore > openList[i + 1]->gScore)
			{
				Node* data = openList[i + 1];
				openList[i + 1]->gScore = first->gScore;
				first->gScore = data->gScore;
				i = 0;
			}
		}

		//current will equal first element in openList
		Node* currentNode = openList.front();

		//if first item in openList != endNode
		if (currentNode == endNode)
		{
			foundNode = true;
			break;
		}

		//place startNode into closedList
		closedList.push_back(currentNode);

		//delete startNode in openList
		delete openList.front();


		//to see if all conections have been set
		bool firstC = false;
		bool secondC = false;
		bool thirdC = false;
		bool fourthC = false;


		for (int i = 0; i < nodeWall.size(); i++)
		{
			//check if leftNode wall
			if (currentNode->getTopNode() != nodeWall[i] && firstC == false)
			{
				Node* next = new Node();
				next = currentNode->getTopNode();

				//set parent
				next->parent = currentNode;
				//set score
				next->gScore = next->gScore + currentNode->gScore;
				//place in openList
				openList.push_back(next);
				
				firstC = true;
			}
			if (currentNode->getBottomNode() != nodeWall[i] && secondC == false)
			{
				Node* next = new Node();
				next = currentNode->getBottomNode();

				//set parent
				next->parent = currentNode;
				//set score
				next->gScore = next->gScore + currentNode->gScore;
				//place in openList
				openList.push_back(next);

				secondC = true;

			}
			if (currentNode->getLeftNode() != nodeWall[i] && thirdC == false)
			{
				Node* next = new Node();
				next = currentNode->getLeftNode();

				//set parent
				next->parent = currentNode;
				//set score
				next->gScore = next->gScore + currentNode->gScore;
				//place in openList
				openList.push_back(next);

				thirdC = true;

			}
			if (currentNode->getRightNode() != nodeWall[i] && fourthC == false)
			{
				Node* next = new Node();
				next = currentNode->getRightNode();

				//set parent
				next->parent = currentNode;
				//set score
				next->gScore = next->gScore + currentNode->gScore;
				//place in openList
				openList.push_back(next);

				fourthC = true;
			}
			
			//Reaching here means that all connections has been set
		}

	}

	//Since we found the endNode

	//get the endNode
	Node* currentNode = endNode;

	//create a Path of Vector
	std::vector<Node*>Path;

	//reverse the order and find the patter through the parent
	while (currentNode != nullptr)
	{
		Path.push_back(currentNode);
		currentNode = currentNode->parent;
	}

	//return correct Path
	return Path;
}

//Node dijkstrasSearch(Node* startNode, Node* endNode)
//{
//	if (startNode == nullptr || endNode == nullptr)
//	{
//		std::cout << "Error:" << std::endl;
//	}
//
//	if (startNode == endNode)
//	{
//		return Node();
//	}
//
//	//Initialise the starting Node
//	startNode->gScore = 0;
//	startNode->parent = nullptr;
//
//	std::vector<Node*>openList;
//	std::vector<Node*>closedList;
//	
//	openList.push_back(startNode);
//
//	while (openList.size() != 0)
//	{
//		//basic Sort -> that may not work
//		for (int i = 0; i < openList.size(); i++)
//		{
//			if (openList[i]->gScore > openList[i + 1]->gScore)
//			{
//				openList[i] = openList[i + 1];
//			}
//		}
//
//		Node *currentNode = openList.front();
//		
//		if (currentNode == endNode)
//		{
//			break; /*Exit While Loop*/
//		}
//
//		Node* newNode = currentNode;
//
//		delete currentNode;
//
//		closedList.push_back(newNode);
//
//		for (int i = 0; i < newNode->connections.size(); i++)
//		{
//			if (endNode != closedList[i])
//			{
//				std::vector<Edge*>collection;
//				Node* differentNode = new Node();
//				collection.push_back(differentNode);
//
//				gScore = newNode->gScore + 
//			}
//		}
//
//	}
//
//}