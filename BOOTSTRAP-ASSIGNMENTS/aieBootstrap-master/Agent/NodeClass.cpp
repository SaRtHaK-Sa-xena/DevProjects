#include "NodeClass.h"
#include "AgentClass.h"
#include <iostream>




void Node::CreateAllNodes(std::vector<Node*>&listOfNodes)
{
	int rows = 44;
	int columns = 25;
	int spacesInBetween = 30;

	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < columns; y++)
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
		if (listOfWalls[i] == listOfNodes[i])
		{
			listOfNodes[i]->ofType = wall;
		}
	}
}

void Node::setAllConnections(std::vector<Node*>&listOfNodes, std::vector<Node*>wallNodes)
{
	int x, y;
	for (int i = 1; i < listOfNodes.size(); i++)
	{

		//if (listOfNodes[i]->position.m_x < listOfNodes[i]->position.m_x + 30 && listOfNodes[i]->position.m_x <//< listOfNodes[i]->position.m_x + 31)
		//{

		//}
		
		//iterate through List
		for(int i = 0 ; i < listOfNodes.size(); i++)
		{
			for(int j = 0; j < listOfNodes.size(); j++)
			{
				if (listOfNodes[i]->position.m_x + 30 == listOfNodes[j]->position.m_x && listOfNodes[i]->position.m_y == listOfNodes[j]->position.m_y)
				{
					listOfNodes[i]->connections.push_back(listOfNodes[j]);
				}
				if (listOfNodes[i]->position.m_x - 30 == listOfNodes[j]->position.m_x && listOfNodes[i]->position.m_y == listOfNodes[j]->position.m_y)
				{
					listOfNodes[i]->connections.push_back(listOfNodes[j]);
				}
				if (listOfNodes[i]->position.m_x == listOfNodes[j]->position.m_x && listOfNodes[i]->position.m_y + 30 == listOfNodes[j]->position.m_y)
				{
					listOfNodes[i]->connections.push_back(listOfNodes[j]);
				}
				if (listOfNodes[i]->position.m_x == listOfNodes[j]->position.m_x && listOfNodes[i]->position.m_y - 30 == listOfNodes[j]->position.m_y)
				{
					listOfNodes[i]->connections.push_back(listOfNodes[j]);
				}
			}
		}




		Node* one = new Node();
		Node* two = new Node();
		Node* three = new Node();
		Node* four = new Node();

		one->position = Vector2((listOfNodes[i]->position.m_x+30), listOfNodes[i]->position.m_y);
		two->position = Vector2((listOfNodes[i]->position.m_x - 30), listOfNodes[i]->position.m_y);
		three->position = Vector2(listOfNodes[i]->position.m_x, (listOfNodes[i]->position.m_y + 30));
		four->position = Vector2(listOfNodes[i]->position.m_x, (listOfNodes[i]->position.m_y-30));

		bool checkOne = false;
		bool checkTwo = false;
		bool checkThree = false;
		bool checkFour = false;

		for (int i = 0; i < wallNodes.size(); i++)
		{
			if (checkOne == false && wallNodes[i]->position.m_x == one->position.m_x && wallNodes[i]->position.m_y == one->position.m_y)
			{
				one->ofType = wall;
				checkOne = true;
			}
			if (checkTwo == false && wallNodes[i]->position.m_x == two->position.m_x && wallNodes[i]->position.m_y == two->position.m_y)
			{
				two->ofType = wall;
				checkTwo = true;
			}
			if (checkThree == false && wallNodes[i]->position.m_x == three->position.m_x && wallNodes[i]->position.m_y == three->position.m_y)
			{
				three->ofType = wall;
				checkThree = true;
			}
			if (checkFour == false && wallNodes[i]->position.m_x == four->position.m_x && wallNodes[i]->position.m_y == four->position.m_y)
			{
				four->ofType = wall;
				checkFour = true;
			}
		}
		//if statement if wall don;t push
		//add it in later
		
		//boolean checks to add
		bool addOne = true;
		bool addTwo = true;
		bool addThree = true;
		bool addFour = true;

		if (one->ofType == wall)
		{
			delete one;
			addOne = false;
		}
		if (two->ofType == wall)
		{
			delete two;
			addTwo = false;
		}
		if (three->ofType == wall)
		{
			delete three;
			addThree = false;
		}
		if (four->ofType == wall)
		{
			delete four;
			addFour = false;
		}

		if (addOne)
		{
			listOfNodes[i]->connections.push_back(one);
		}
		if (addTwo)
		{
			listOfNodes[i]->connections.push_back(two);
		}
		if (addThree)
		{
			listOfNodes[i]->connections.push_back(three);
		}
		if (addFour)
		{
			listOfNodes[i]->connections.push_back(four);
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
 	startNode->position = finder->GetPosition();

	//startNode will have gScore of 1
	startNode->gScore = 1;

	//will have no parent since it's the start
	startNode->parent = nullptr;

	/*Node* first = new Node((Vector2(90, 60)), clear, false,false,1);
	Node* second = new Node((Vector2(30, 60)), clear, false, false, 1);
	Node* third = new Node((Vector2(60, 30)), clear, false, false, 1);
	Node* fourth = new Node((Vector2(60, 90)), clear, false, false, 1);*/


	/*startNode->connections.push_back(first);
	startNode->connections.push_back(second);
	startNode->connections.push_back(third);
	startNode->connections.push_back(fourth);*/

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

	//for debug purposes
	//--checked Nodes--
	//std::vector<Node*>checkedNodeList;


	openList.push_back(startNode);
	//checkedNodeList.push_back(startNode);

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

		//----------[JUST ADDED] 10:18 AM 8/13/2019 find which node in listOfNodes then store its connection--

		//for (int i = 0; i < listOfNodes.size(); i++)
		//{
		//	if (currentNode->position.m_x == listOfNodes[i]->position.m_x && currentNode->position.m_y == listOfNodes[i]->position.m_y)
		//	{
		//		currentNode->connections = listOfNodes[i]->connections;
		//		//iterate through checkedNodeList
		//		for (int iterate = 0; iterate < checkedNodeList.size(); iterate++)
		//		{
		//			//check if first element matches the connections all elements
		//			for (int j = 0; j < currentNode->connections.size(); j++)
		//			{
		//				//
		//				if (checkedNodeList[iterate] == currentNode->connections[j])
		//				{
		//					currentNode->connections[j] = checkedNodeList[iterate];
		//				}
		//			}
		//			
		//		}

		//	}
		//}

		//need nodesList
		//need currentNode
		//need a way to search through nodes List
		//need a way to add to currentNode.connections


		//----------------------------------------------------------------------------------------------------


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
		int foundIndex = 0;

		bool firstC = false;
		bool secondC = false;
		bool thirdC = false;
		bool fourthC = false;


		

		for (int i = 0; i < currentNode->connections.size(); i++)
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
					//checkedNodeList.push_back(currentNode->connections[i]);
				}

				//problem may occur here															<-------------MAYBE-------------->
				else if (gScore < currentNode->connections[i]->gScore)
				{
					currentNode->connections[i]->gScore = gScore;
					currentNode->connections[i]->parent = currentNode;
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

		
	

