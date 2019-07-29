#pragma once

#include "Application.h"
#include "SeekBehaviourClass.h"
#include "WanderBehaviourClass.h"
#include "ColliderWall.h"
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
	SeekBehaviour*		m_followBehaviour;

	Agent*				m_enemyWander;
	WanderBehaviour*	m_wanderBehaviour;

	aie::Texture*		m_playerTexture;
	aie::Texture*		m_enemyTexture;

	aie::Texture*		m_backgroundTexture;
	aie::Texture*		m_mainMenuTexture;

	//Holds Collision with walls
	std::vector<Collider>walls;

	//Holds Collision with Enemy
	std::vector<Collider>contact;

	//Check to Start the Game
	bool startGame = false;

	//To Draw MainMenu
	bool drawMainMenu = true;

	//Checks If Player and Enemy Created
	bool createdEntity = false;

};