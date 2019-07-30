#pragma once
#include <Vector2.h>
#include <vector>

class Edge;

struct Node
{
	Node();

	Vector2 position;

	float gScore;
	Node* parent;

	std::vector<Edge>connections;



};

Vector2 dijkstrasSearch(Node *startNode, Node *endNode)
{
	if (startNode == nullptr || endNode == nullptr)
	{
		std::cout << "Error!!!" << std::endl;
	}
	if (startNode == endNode)
	{
		return Vector2();
	}

	//Initialize the starting node
	startNode->gScore = 0;
	startNode->parent = nullptr;

	//Create our temporary lists for storing nodes we're visiting/visited
	Node* openList;
	Node* closedList;

	//How to add startNode to openList

	while (openList /*not empty*/)
	{
		/*sort open list by node.gscore*/

		Node *currentNode = /*first item in openList*/
		
		//If we visit the endNode, then we can exit early.
		//Sorting the openList guarantees the shortest path is found,
		//given no negative costs (a prerequisite of the algorithm).

		if (currentNode == endNode)
		{
			break; /*exit while loop*/
		}
			
		Node* newCurrentNode = new Node();
		newCurrentNode = currentNode;

		delete currentNode;

		/*some sort of insert function to insert 
		  newCurrentNode into closed list*/

		for (auto c : currentNode.connections)
		{
			if (c.target != closedList) /*not in closed list*/
			{
				gScore = currentNode->gScore + c.cost;
			}

			//Have not yet visited the node.
			//So calculate the Score and Update its parent.
			//Also add it to the openList for processing.

			if (c.target != openList) /*not in open List*/
			{
				c.target.gScore = gScore;
				c.target.parent = currentNode;
				/*insert c.target to openList*/
			}

			//Node is already in the openList with a valid Score.
			//So compare the calculated Score with the existing
			//To find the shorter path.
			else if (gScore < c.target.gScore)
			{
				c.target.gScore = gScore;
				c.target.parent = currentNode;
			}
		}

		//Create a path in reverse from endNode to startNode
		/*Let Path be a list of Nodes*/
		Node* path = new Node();
		currentNode = endNode;

		while (currentNode != nullptr)
		{
			/*function to add it to the beginning of path*/ /*possibly have way to get front and set front (like 'head')*/
			currentNode = currentNode.parent;
		}

		//Return the path for navigation between startNode/endNode
		return path->position;

		
	}

}