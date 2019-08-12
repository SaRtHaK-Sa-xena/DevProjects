#include "NodeClass.h"
#include "AgentClass.h"
#include <iostream>




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

Node* Node::getTopNode()
{
	Node *topNode = new Node(*this);
	topNode->position.m_y = this->position.m_y + 30;
	return topNode; //star
}

Node* Node::getBottomNode()
{
	Node *bottomNode = new Node(*this);
	bottomNode->position.m_y = this->position.m_y - 30;
	return bottomNode; //star
}

Node* Node::getLeftNode()
{
	Node *leftNode = new Node(*this);
	leftNode->position.m_x = this->position.m_x - 30;
	return leftNode; //star
}

Node* Node::getRightNode()
{
	Node *rightNode = new Node(*this);
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

	//create two lists
	std::vector<Node*>openList;
	std::vector<Node*>closedList;

	openList.push_back(startNode);

	//while openlist has anything
	bool foundNode = false;

	while (openList.size() != 0 && foundNode == false)
	{

		for (int i = 0; i < openList.size()-1; i++)
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
		openList.erase(openList.begin(),openList.begin()+1);


		//to see if all conections have been set
		

		//Reference
		int foundIndex = 0;

		bool firstC = false;
		bool secondC = false;
		bool thirdC = false;
		bool fourthC = false;
		//if first,second,third,fourth == false
		//{
		for (int i = 0; i < nodeWall.size(); i++)
		{
			Node* next = currentNode->getTopNode();
			//check if topNode wall
			if (firstC == false && next->CheckInList(nodeWall,foundIndex)==false && next->CheckInList(closedList,foundIndex)==false)
			{

				float gScore = currentNode->gScore + next->gScore;

				if (next->CheckInList(openList, foundIndex) == false)
				{
					//set parent
					next->parent = currentNode;
					//set score
					//next->gScore = next->gScore + currentNode->gScore;
					next->gScore = gScore;
					//place in openList
					openList.push_back(next);

					firstC = true;
				}
				else if (gScore < openList[foundIndex]->gScore)
				{
					openList[foundIndex]->gScore = gScore;
					openList[foundIndex]->parent = currentNode;
				}
			}
			next = currentNode->getBottomNode();
			if (secondC == false && next->CheckInList(nodeWall, foundIndex) == false && next->CheckInList(closedList, foundIndex) == false)
			{

				float gScore = currentNode->gScore + next->gScore;

				if (next->CheckInList(openList, foundIndex) == false)
				{
					//set parent
					next->parent = currentNode;
					//set score
					//next->gScore = next->gScore + currentNode->gScore;
					next->gScore = gScore;
					//place in openList
					openList.push_back(next);

					secondC = true;
				}
				else if (gScore < openList[foundIndex]->gScore)
				{
					openList[foundIndex]->gScore = gScore;
					openList[foundIndex]->parent = currentNode;
				}

			}
			next = currentNode->getLeftNode();
			if (thirdC == false && next->CheckInList(nodeWall, foundIndex) == false && next->CheckInList(closedList, foundIndex) == false)
			{
				
				float gScore = currentNode->gScore + next->gScore;

				if (next->CheckInList(openList, foundIndex) == false)
				{
					//set parent
					next->parent = currentNode;
					//set score
					//next->gScore = next->gScore + currentNode->gScore;
					next->gScore = gScore;
					//place in openList
					openList.push_back(next);

					thirdC = true;
				}
				else if (gScore < openList[foundIndex]->gScore)
				{
					openList[foundIndex]->gScore = gScore;
					openList[foundIndex]->parent = currentNode;
				}

			}
			next = currentNode->getRightNode();
			if (fourthC == false && next->CheckInList(nodeWall, foundIndex) == false && next->CheckInList(closedList, foundIndex) == false)
			{
			
				float gScore = currentNode->gScore + next->gScore;

				if (next->CheckInList(openList, foundIndex) == false)
				{
					//set parent
					next->parent = currentNode;
					//set score
					//next->gScore = next->gScore + currentNode->gScore;
					next->gScore = gScore;
					//place in openList
					openList.push_back(next);

					fourthC = true;
				}
				else if (gScore < openList[foundIndex]->gScore)
				{
					openList[foundIndex]->gScore = gScore;
					openList[foundIndex]->parent = currentNode;
				}
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

