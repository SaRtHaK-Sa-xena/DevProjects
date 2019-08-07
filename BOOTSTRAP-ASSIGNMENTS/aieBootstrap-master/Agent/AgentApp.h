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

	Agent*				m_collectibles;
	Agent*				m_collectibles1;


	WanderBehaviour*	m_wanderBehaviour; //wandering behaviour

	aie::Texture*		m_playerTexture; //player 
	aie::Texture*		m_enemyTexture; //enemy
	aie::Texture*		m_enemyCollectorTexture; //enemyCollector

	aie::Texture*		m_backgroundTexture; //background
	aie::Texture*		m_mainMenuTexture; //main menu
	aie::Texture*		m_itemTexture; //collectibles

	// Holds Collision with walls
	std::vector<Collider>walls;

	// Holds Collision with Enemy
	std::vector<Collider>contact;

	// Holds Collision with Item
	std::vector<Collider>collectibles;

	// Holds Collision with Items In ItemCollision.h
	std::vector<collectCollision>Items;

	//===================NODES====================
	// Holds Nodes With Wall Points
	std::vector<Node*>Wall;

	// Holds Nodes With Item Points
	std::vector<Node*>ItemCollectibles;

	// Holds current path returned from Dijkstra
	std::vector<Node*>currentPath;
	//===================NODES====================

	//iterator for items Vector in  ItemCollectibles
	int currentItem = 0;

	//iterator for node Vector in curentPath
	int currentNode = 0;

	//temporary Node
	Node* temporaryNode = new Node();


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

};