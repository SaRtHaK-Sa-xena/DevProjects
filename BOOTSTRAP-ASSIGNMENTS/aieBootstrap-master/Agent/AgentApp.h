#pragma once

#include "Application.h"
#include "SeekBehaviourClass.h"
#include "WanderBehaviourClass.h"
#include "ColliderWall.h"
#include "ItemCollision.h"
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

	//creates player; able to move through keyboard behaviour
	Agent*				m_player;
	KeyboardBehaviour*	m_keyboardBehaviour;

	//creates enemy; unable to move, but uses seek to move
	Agent*				m_enemy;
	SeekBehaviour*		m_followBehaviour; //follow behaviour

	Agent*				m_collectibles;
	Agent*				m_collectibles1;
	Agent*				m_collectibles2;
	Agent*				m_collectibles3;
	Agent*				m_collectibles4;
	Agent*				m_collectibles5;
	Agent*				m_collectibles6;
	Agent*				m_collectibles7;
	Agent*				m_collectibles8;
	Agent*				m_collectibles9;
	Agent*				m_collectibles10;

	Agent* amountCollectibles[10];

	WanderBehaviour*	m_wanderBehaviour; //wandering behaviour

	aie::Texture*		m_playerTexture; //player 
	aie::Texture*		m_enemyTexture; //enemy

	aie::Texture*		m_backgroundTexture; //background
	aie::Texture*		m_mainMenuTexture; //main menu
	aie::Texture*		m_itemTexture; //collectibles

	//Holds Collision with walls
	std::vector<Collider>walls;

	//Holds Collision with Enemy
	std::vector<Collider>contact;

	//Holds Collision with Item
	std::vector<Collider>collectibles;

	//Holds Collision with Items In ItemCollision.h
	std::vector<collectCollision>Items;


	//Check to Start the Game
	bool startGame = false;

	//To Draw MainMenu
	bool drawMainMenu = true;

	//To Draw Enemy
	bool drawEnemy = false;

	//Checks If Player and Enemy Created
	bool createdEntity = true;

	//Score Tally
	int Score = 0;

};