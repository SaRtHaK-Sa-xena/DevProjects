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

Node dijkstrasSeatch(Node *startNode, Node *endNode, Agent* finder, std::vector<Node*>nodeWall)
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
		return Node();
	}

	std::vector<Node*>openList;
	std::vector<Node*>closedList;

	openList.push_back(startNode);

	//while openlist has anything
	while (openList.size() != 0)
	{

		for (int i = 0; i < openList.size(); i++)
		{
			Node *first = openList[0];
			Node *second = openList[1];
			if (openList[i]->gScore < openList[i + 1]->gScore)
			{
				if (first < second)
				{
					first = openList[0];
				}
				else
				{
					fi
				}
				//if less than second
				//move it back to the beginning
			}

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


		}


		Node* first = openList.front();
		//sort to have the lowest in the beginning
		for (int i = 0; i < openList.size(); i++)
		{
			if (first->gScore > openList[i + 1]->gScore)
			{
				openList[i + 1] = first;
				first = openList[i + 1];
			}
		}


		Node* currentNode = openList.front();
		


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

		//place startNode into closedList
		closedList.push_back(startNode);

		//delete startNode in openList
		for (int i = 0; i < openList.size(); i++)
		{
			delete openList[i];
		}

		for (int i = 0; i < nodeWall.size(); i++)
		{
			//check if leftNode wall
			if (startNode->getTopNode() != nodeWall[i])
			{
				Node* next = new Node();
				next = startNode->getTopNode();
				openList.push_back(next);
				
			}
			if (startNode->getBottomNode() != nodeWall[i])
			{
				Node* next = new Node();
				next = startNode->getBottomNode();
				openList.push_back(next);

			}
			if (startNode->getLeftNode() != nodeWall[i])
			{
				Node* next = new Node();
				next = startNode->getLeftNode();
				openList.push_back(next);

			}
			if (startNode->getRightNode() != nodeWall[i])
			{
				Node* next = new Node();
				next = startNode->getRightNode();
				openList.push_back(next);

			}
			
			//openList contains all openings



			nodeRight->position.m_x = startNode->position.m_x + 30;
			startNode->connections.push_back(nodeRight);

			startNode->connections.push_back(temporaryNode)

			temporaryNode
			if()

			Node* newNode;
			newNode->position = startNode->position;
		}

		startNode->connections.push_back(



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