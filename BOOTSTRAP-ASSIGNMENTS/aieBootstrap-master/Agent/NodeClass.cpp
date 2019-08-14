#include "NodeClass.h"
#include "AgentClass.h"
#include <iostream>




void Node::CreateAllNodes(std::vector<Node*>&listOfNodes)
{
	int rows = 44;
	int columns = 25;
	int spacesInBetween = 30;

	for (int x = 1; x < rows; x++)
	{
		for (int y = 1; y < columns; y++)
		{
			//pre-generate all nodes
			Node* newNode = new Node(Vector2(x * spacesInBetween, y * spacesInBetween), clear, false, false, 1);
			//store them in List of all nodes
			listOfNodes.push_back(newNode);
		}
	}
}

void Node::setAllWalls(std::vector<Node*> &listOfNodes, std::vector<Node*> listOfWalls)
{
	for (int i = 0; i < listOfWalls.size(); i++)
	{
		for (int j = 0; j < listOfNodes.size(); j++)
		{
			if (listOfWalls[i]->position.m_x == listOfNodes[j]->position.m_x && listOfWalls[i]->position.m_y == listOfNodes[j]->position.m_y)
			{
				listOfNodes[j]->ofType = wall;
			}
		}
	}
}

void Node::setAllConnections(std::vector<Node*>&listOfNodes, std::vector<Node*>wallNodes)
{
	//iterate through List
	for (int current = 0; current < listOfNodes.size(); current++)
	{
		for (int connectionNode = 0; connectionNode < listOfNodes.size(); connectionNode++)
		{
			if (listOfNodes[current]->position.m_x + 30 == listOfNodes[connectionNode]->position.m_x && listOfNodes[current]->position.m_y == listOfNodes[connectionNode]->position.m_y)
			{
				listOfNodes[current]->connections.push_back(listOfNodes[connectionNode]);
			}
			if (listOfNodes[current]->position.m_x - 30 == listOfNodes[connectionNode]->position.m_x && listOfNodes[current]->position.m_y == listOfNodes[connectionNode]->position.m_y)
			{
				listOfNodes[current]->connections.push_back(listOfNodes[connectionNode]);
			}
			if (listOfNodes[current]->position.m_x == listOfNodes[connectionNode]->position.m_x && listOfNodes[current]->position.m_y + 30 == listOfNodes[connectionNode]->position.m_y)
			{
				listOfNodes[current]->connections.push_back(listOfNodes[connectionNode]);
			}
			if (listOfNodes[current]->position.m_x == listOfNodes[connectionNode]->position.m_x && listOfNodes[current]->position.m_y - 30 == listOfNodes[connectionNode]->position.m_y)
			{
				listOfNodes[current]->connections.push_back(listOfNodes[connectionNode]);
			}
		}
	}
}


	



Node::Node(Vector2 specificPosition, itemType NAME, int m_gScore)
{
	position = specificPosition;
	ofType = NAME;
	gScore = m_gScore;
}

bool Node::CheckInList(std::vector<Node*> List, int &index)
{
	for (int i = 0; i < List.size(); i++)
	{
		if (*List[i] == *this)
		{
			index = i;
			return true;
		}
	}

	return false;
}

Node* Node::getTopNode(std::vector<Node*>wallNodes)
{
	//make newNode hold current
	Node* newNode = new Node(*this);
	//plus its y value
	newNode->position.m_y = this->position.m_y + 30;

	//for size of NodeList
	for (int i = 0; i < wallNodes.size(); i++)
	{
		//if their positions match
		if (newNode->position.m_x == wallNodes[i]->position.m_x && newNode->position.m_y == wallNodes[i]->position.m_y)
		{
			//make that newNode equal to that node
			newNode = wallNodes[i];
			return newNode;
		}
	}
	return newNode;
}

Node* Node::getBottomNode(std::vector<Node*>wallNodes)
{
	//make newNode hold current
	Node* newNode = new Node(*this);
	//plus its y value
	newNode->position.m_y = this->position.m_y - 30;

	//for size of NodeList
	for (int i = 0; i < wallNodes.size(); i++)
	{
		//if their positions match
		if (newNode->position.m_x == wallNodes[i]->position.m_x && newNode->position.m_y == wallNodes[i]->position.m_y)
		{
			//make that newNode equal to that node
			newNode = wallNodes[i];
			return newNode;
		}
	}
	return newNode;
}

Node* Node::getLeftNode(std::vector<Node*>wallNodes)
{
	//make newNode hold current
	Node* newNode = new Node(*this);
	//plus its y value
	newNode->position.m_y = this->position.m_x - 30;

	//for size of NodeList
	for (int i = 0; i < wallNodes.size(); i++)
	{
		//if their positions match
		if (newNode->position.m_x == wallNodes[i]->position.m_x && newNode->position.m_y == wallNodes[i]->position.m_y)
		{
			//make that newNode equal to that node
			newNode = wallNodes[i];
			return newNode;
		}
	}
	return newNode;
}

Node* Node::getRightNode(std::vector<Node*>wallNodes)
{
	//make newNode hold current
	Node* newNode = new Node(*this);
	//plus its y value
	newNode->position.m_y = this->position.m_x + 30;

	//for size of NodeList
	for (int i = 0; i < wallNodes.size(); i++)
	{
		//if their positions match
		if (newNode->position.m_x == wallNodes[i]->position.m_x && newNode->position.m_y == wallNodes[i]->position.m_y)
		{
			//make that newNode equal to that node
			newNode = wallNodes[i];
			return newNode;
		}
	}
	return newNode;
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

std::vector<Node*> dijkstrasSeatch(Node *startNode, Node *endNode, Agent* finder, std::vector<Node*>listOfNodes)
{

	//startNode equal to finder's position

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

	//create two lists
	std::vector<Node*>openList;
	std::vector<Node*>closedList;


	openList.push_back(startNode);

	//while openlist has anything
	bool foundNode = false;

	while (openList.size() != 0 && foundNode == false)
	{

		for (int i = 0; i < openList.size() - 1; i++)
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
		if (currentNode->position.m_x == endNode->position.m_x && currentNode->position.m_y == endNode->position.m_y)
		{
			//sets the endNode to currentNode's parent, which makes the parents the same
			endNode->parent = currentNode->parent;
			foundNode = true;
			break;
		}

		//place startNode into closedList
		closedList.push_back(currentNode);

		//delete startNode in openList
		openList.erase(openList.begin(), openList.begin() + 1);


		//to see if all conections have been set


		//Reference
		//int foundIndex = 0;

		//bool firstC = false;
		//bool secondC = false;
		//bool thirdC = false;
		//bool fourthC = false;


		

		for (int i = 0; i < currentNode->connections.size(); i++)
		{
			if (currentNode->connections[i]->ofType != wall)
			{
				if (currentNode->connections[i]->inClosedList == false)
				{
					float gScore = currentNode->gScore + currentNode->connections[i]->gScore;

					if (currentNode->connections[i]->inOpenList == false)
					{
						currentNode->connections[i]->parent = currentNode;
						currentNode->connections[i]->gScore = gScore;
						currentNode->connections[i]->inOpenList = true;
						openList.push_back(currentNode->connections[i]);
					}

																			
					else if (gScore < currentNode->connections[i]->gScore)
					{
						currentNode->connections[i]->gScore = gScore;
						currentNode->connections[i]->parent = currentNode;
					}
				}
			}
		}
		currentNode->inClosedList = true;




			//Node* next = currentNode->getTopNode(listOfNodes);
			//if (firstC == false && next->ofType != wall && next->inClosedList == false)
			//{
			//	float gScore = currentNode->gScore + next->gScore;

			//	if (next->inOpenList == false)
			//	{
			//		//set parent
			//		next->parent = currentNode;
			//		//set score
			//		//next->gScore = next->gScore + currentNode->gScore;
			//		next->gScore = gScore;

			//		//set checks
			//		next->inOpenList = true;

			//		//place in openList
			//		openList.push_back(next);

			//		firstC = true;
			//	}
			//	else if (gScore < openList[foundIndex]->gScore)
			//	{
			//		openList[foundIndex]->gScore = gScore;
			//		openList[foundIndex]->parent = currentNode;
			//	}
			//}
			//next = currentNode->getBottomNode(listOfNodes);
			//if (secondC == false && next->ofType != wall && next->inClosedList == false)
			//{
			//	float gScore = currentNode->gScore + next->gScore;

			//	if (next->inOpenList == false)
			//	{
			//		//set parent
			//		next->parent = currentNode;
			//		//set score
			//		//next->gScore = next->gScore + currentNode->gScore;
			//		next->gScore = gScore;
			//		//place in openList
			//		openList.push_back(next);

			//		secondC = true;
			//	}
			//	else if (gScore < openList[foundIndex]->gScore)
			//	{
			//		openList[foundIndex]->gScore = gScore;
			//		openList[foundIndex]->parent = currentNode;
			//	}
			//}
			//next = currentNode->getLeftNode(listOfNodes);
			//if (thirdC == false && next->ofType != wall && next->inClosedList == false)
			//{
			//	float gScore = currentNode->gScore + next->gScore;

			//	if (next->inOpenList == false)
			//	{
			//		//set parent
			//		next->parent = currentNode;
			//		//set score
			//		//next->gScore = next->gScore + currentNode->gScore;
			//		next->gScore = gScore;
			//		//place in openList
			//		openList.push_back(next);

			//		thirdC = true;
			//	}
			//	else if (gScore < openList[foundIndex]->gScore)
			//	{
			//		openList[foundIndex]->gScore = gScore;
			//		openList[foundIndex]->parent = currentNode;
			//	}
			//}
			//next = currentNode->getRightNode(listOfNodes);
			//if (fourthC == false && next->ofType != wall && next->inClosedList == false)
			//{
			//	float gScore = currentNode->gScore + next->gScore;

			//	if (next->inOpenList == false)
			//	{
			//		//set parent
			//		next->parent = currentNode;
			//		//set score
			//		//next->gScore = next->gScore + currentNode->gScore;
			//		next->gScore = gScore;
			//		//place in openList
			//		openList.push_back(next);

			//		fourthC = true;
			//	}
			//	else if (gScore < openList[foundIndex]->gScore)
			//	{
			//		openList[foundIndex]->gScore = gScore;
			//		openList[foundIndex]->parent = currentNode;
			//	}
			//}

			////after it has been checked
			//currentNode->inClosedList = true;
			
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
	std::cout << "Path returned..." << std::endl;
}
		//	for (int i = 0; i < nodeWall.size(); i++)
		//	{
		//		Node* next = currentNode->getTopNode();
		//		//check if topNode wall
		//		if (firstC == false && next->CheckInList(nodeWall,foundIndex)==false && next->CheckInList(closedList,foundIndex)==false)
		//		{

		//			float gScore = currentNode->gScore + next->gScore;

		//			if (next->CheckInList(openList, foundIndex) == false)
		//			{
		//				//set parent
		//				next->parent = currentNode;
		//				//set score
		//				//next->gScore = next->gScore + currentNode->gScore;
		//				next->gScore = gScore;
		//				//place in openList
		//				openList.push_back(next);

		//				firstC = true;
		//			}
		//			else if (gScore < openList[foundIndex]->gScore)
		//			{
		//				openList[foundIndex]->gScore = gScore;
		//				openList[foundIndex]->parent = currentNode;
		//			}
		//		}
		//		next = currentNode->getBottomNode();
		//		if (secondC == false && next->CheckInList(nodeWall, foundIndex) == false && next->CheckInList(closedList, foundIndex) == false)
		//		{

		//			float gScore = currentNode->gScore + next->gScore;

		//			if (next->CheckInList(openList, foundIndex) == false)
		//			{
		//				//set parent
		//				next->parent = currentNode;
		//				//set score
		//				//next->gScore = next->gScore + currentNode->gScore;
		//				next->gScore = gScore;
		//				//place in openList
		//				openList.push_back(next);

		//				secondC = true;
		//			}
		//			else if (gScore < openList[foundIndex]->gScore)
		//			{
		//				openList[foundIndex]->gScore = gScore;
		//				openList[foundIndex]->parent = currentNode;
		//			}

		//		}
		//		next = currentNode->getLeftNode();
		//		if (thirdC == false && next->CheckInList(nodeWall, foundIndex) == false && next->CheckInList(closedList, foundIndex) == false)
		//		{
		//			
		//			float gScore = currentNode->gScore + next->gScore;

		//			if (next->CheckInList(openList, foundIndex) == false)
		//			{
		//				//set parent
		//				next->parent = currentNode;
		//				//set score
		//				//next->gScore = next->gScore + currentNode->gScore;
		//				next->gScore = gScore;
		//				//place in openList
		//				openList.push_back(next);

		//				thirdC = true;
		//			}
		//			else if (gScore < openList[foundIndex]->gScore)
		//			{
		//				openList[foundIndex]->gScore = gScore;
		//				openList[foundIndex]->parent = currentNode;
		//			}

		//		}
		//		next = currentNode->getRightNode();
		//		if (fourthC == false && next->CheckInList(nodeWall, foundIndex) == false && next->CheckInList(closedList, foundIndex) == false)
		//		{
		//		
		//			float gScore = currentNode->gScore + next->gScore;

		//			if (next->CheckInList(openList, foundIndex) == false)
		//			{
		//				//set parent
		//				next->parent = currentNode;
		//				//set score
		//				//next->gScore = next->gScore + currentNode->gScore;
		//				next->gScore = gScore;
		//				//place in openList
		//				openList.push_back(next);

		//				fourthC = true;
		//			}
		//			else if (gScore < openList[foundIndex]->gScore)
		//			{
		//				openList[foundIndex]->gScore = gScore;
		//				openList[foundIndex]->parent = currentNode;
		//			}
		//		}
		//		
		//		//Reaching here means that all connections has been set
		//	}

		//}

		
	

