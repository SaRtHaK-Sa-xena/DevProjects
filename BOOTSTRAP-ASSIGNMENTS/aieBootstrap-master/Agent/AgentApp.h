#pragma once

#include "Application.h"
#include "SeekBehaviourClass.h"
#include "WanderBehaviourClass.h"
#include "ColliderWall.h"
#include "ItemCollision.h"
#include "PathfindingBehaviour.h"
#include "NodeClass.h"
#include <vector>

class AgentApp : public aie::Application {
public:

	AgentApp();
	virtual ~AgentApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	//Function to find the closest Node then compare it
	Node* FindClosestNode(Vector2 Position);

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	// reates player; able to move through keyboard behaviour
	Agent*				m_player;
	KeyboardBehaviour*	m_keyboardBehaviour;

	// creates enemy; unable to move, but uses seek to move
	Agent*				m_enemy;
	SeekBehaviour*		m_followBehaviour; // follow behaviour

	Agent*				m_enemyCollector;// uses Seek to follow the paths
	PathfindBehaviour*  m_findPathBehaviour;// returns the shortest path

	WanderBehaviour*	m_wanderBehaviour; //wandering behaviour


	Agent*				m_collectibles;
	Agent*				m_collectibles1;
	Agent*				m_collectibles2;
	Agent*				m_collectibles3;
	Agent*				m_collectibles4;
	Agent*				m_collectibles5;
	Agent*				m_collectibles6;


	aie::Texture*		m_playerTexture; //player 
	aie::Texture*		m_enemyTexture; //enemy
	aie::Texture*		m_enemyCollectorTexture; //enemyCollector

	aie::Texture*		m_backgroundTexture; //background
	aie::Texture*		m_mainMenuTexture; //main menu
	aie::Texture*		m_itemTexture; //collectibles
	aie::Texture*		m_winTexture; //Win Screen

	// Holds Collision with walls
	std::vector<Collider>walls;

	// Holds Collision with Enemy
	std::vector<Collider>contact;

	// Holds Collision with Item
	std::vector<Collider>collectibles;
	std::vector<Collider>collectibles1;
	std::vector<Collider>collectibles2;
	std::vector<Collider>collectibles3;
	std::vector<Collider>collectibles4;



	// Holds Collision with Items In ItemCollision.h
	std::vector<collectCollision>Items;

	//===================NODES====================
	// Holds all nodes
	std::vector<Node*>nodesList;

	// Holds Nodes With Wall Points
	std::vector<Node*>Wall;

	// Holds current path returned from Dijkstra
	std::vector<Node*>currentPath;
	//===================NODES====================

	//iterator for items Vector in  ItemCollectibles
	int currentItem = 0;

	//iterator for node Vector in curentPath
	int currentNode = 0;

	//temporary Node
	Node* temporaryNode = new Node();

	//Waits for path to be made
	bool pathMade = false;


	//Checks if Path Found, then increment ItemCollectibles
	bool pathFound = false;

	// Check to Start the Game
	bool startGame = false;

	// To Draw MainMenu
	bool drawMainMenu = true;

	// To Draw Enemy
	bool drawEnemy = false;

	// Checks If Player and Enemy Created
	bool createdEntity = true;

	// Score Tally
	int Score = 0;

	// For Debug Purposes
	bool drawNodesOnScreen = true;

	//checks If endNode has changed
	bool pathChanged = false;

	//Change In Behavior
	bool startPathfinding = false;

	//Items To Draw
	bool drawItem = false;
	bool drawItem2 = false;
	bool drawItem3 = false;
	bool drawItem4 = false;
	bool drawItem5 = false;

	// To Find If Pathfinding Needs to be activated
	bool check = false;

	//Check For Collision
	bool checkCollisionForEnemy = true;

	//Check To Draw Player And Enemy
	bool drawPlayerAndEnemy = false;

	//Check to draw win screen
	bool drawWinScreen = false;



};