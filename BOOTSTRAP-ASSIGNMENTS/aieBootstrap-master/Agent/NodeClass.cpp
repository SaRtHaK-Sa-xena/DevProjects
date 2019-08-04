#include "NodeClass.h"
#include <iostream>


Node::Node(Vector2 specificPosition, itemType NAME, int m_gScore)
{
	position = specificPosition;
	ofType = NAME;
	gScore = m_gScore;
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

Node differentSeatch(Node *target, Node *);

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