#include "NodeClass.h"
#include "AgentClass.h"
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

Node differentSeatch(Node *startNode, Node *endNode, Agent* finder)
{
	//startNode equal to finder's position
	startNode->position = finder->GetPosition();
	startNode->gScore = 1;
	startNode->parent = nullptr;

	if (startNode == nullptr || endNode == nullptr)
	{
		std::cout << "Error!!" << std::endl;
	}

	if (startNode == endNode)
	{
		return Node();
	}

	std::vector<Node*>openList;
	std::vector<Node*>closedList;

	openList.push_back(startNode);

	while (openList.size() != 0)
	{
		//sorting by gScore
		//Function To sort by gScore-----
		//|
		//|
		//|
		//|
		//|______________________________

		//if first item in openList != endNode
		for (int i = 0; i < openList.size(); i++)
		{
			if (openList[i] == endNode)
			{
				//break out off while loop
			}
		}


		//Questions-------
		//| 1. Does the connections in Node.connnections need to be set manually like connection.pushback(Node2,Node3)
		//|
		//| 2. Should it be like if(collector->getPosition().m_x - 30 equal to Node12, then do something)
		//|
		//| 3. If I make a for loop going through position checks with corresponding nodes on the map add it to openList
		//|	   and add it to connections vector
		//|
		//| 4. Do I have to create a connection of each node like, Node2.connections = Node 4 (to the right by 30),
		//|    Node 6 (above by 30), Node 1 (to the left by 30), Node 3 (below by 30). All in each Nodes.connection through
		//|    push_back().
		//|_______________
	}

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