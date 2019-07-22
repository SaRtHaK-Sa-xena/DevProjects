#include "AgentApp.h"
#include "Texture.h"
#include "Font.h"
#include <chrono>
#include <Windows.h>
#include <iostream>

AgentApp::AgentApp() {

}

AgentApp::~AgentApp() {

}

bool AgentApp::startup() {
	
	srand(time(NULL));


	
	//Start Game

	//Starts by pressing 'Space'

	//Game Load

	//-->Map displayed
	
	//-->Player displayed
	
	//-->Enemy Displayed
	
	//-->Score Displayed

	//Finish Loading Game

	m_2dRenderer = new aie::Renderer2D();
	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_backgroundTexture = new aie::Texture("../bin/textures/Background.png");

	m_colliderTexture = new aie::Texture("../bin/textures/Enemy.png");

	m_playerTexture = new aie::Texture("../bin/textures/ship.png");

	m_collider = new Agent();
	m_collider->SetPosition(Vector2(25, 700));

	m_collider2 = new Agent();
	m_collider2->SetPosition(Vector2(40, 700));

	//setBackgroundColour(0.45, 1, 0.45);
	//setBackgroundColour(0.7, 0.9, 0.1);
	m_player = new Agent();
	//m_theBackground->load("../bin/textures/ship.png");
	m_player->SetPosition(Vector2(getWindowWidth() / 2.f, getWindowHeight() / 2.f));
	
	//m_player->SetPosition(Vector2(100.0f, 100.0f)); // set starting position

	//========================================Not being Used For Now==========================
	//m_player->SetPosition(Vector2(100,100)); // set starting position

	m_keyboardBehaviour = new KeyboardBehaviour();
	m_player->AddBehaviour(m_keyboardBehaviour); //adds behaviour of keyboard



	//m_enemy = new Agent();
	//m_enemy->SetPosition(Vector2(500, 500));// sets stating position for enemy

	//m_followBehaviour = new SeekBehaviour();
	//m_followBehaviour->SetTarget(m_player); //sets target to follow player
	//m_enemy->AddBehaviour(m_followBehaviour);//allows the behaviour to be processed by enemy
	////=====================================================================
	//m_enemyWander = new Agent();
	//m_enemyWander->SetPosition(Vector2(350, 350));

	//m_wanderBehaviour = new WanderBehaviour();
	//m_enemyWander->AddBehaviour(m_wanderBehaviour);
	//========================================Not being Used For Now==========================
	
	return true;
}

void AgentApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void AgentApp::update(float deltaTime) {




	// input example
	aie::Input* input = aie::Input::getInstance();

	//==============NOT BEING USED FOR NOW =====================================================
	m_player->Update(deltaTime); //since player has keyboard behaviour there is no need for
	//							 //an input function in update

	//m_enemy->Update(deltaTime);//calls update on enemy changing it's vector
	m_collider->Update(deltaTime);
	m_collider2->Update(deltaTime);
	//m_enemyWander->Update(deltaTime);

	/*if (m_player->GetPosition().m_x == m_collider->GetPosition().m_x && m_player->GetPosition().m_y == m_collider->GetPosition().m_y)
	{
		std::cout << "Collision Detected!" << std::endl;
	}*/

	float playerX = m_player->GetPosition().m_x;
	float playerY = m_player->GetPosition().m_y;

	float colliderX = m_collider->GetPosition().m_x;
	float colliderY = m_collider->GetPosition().m_y;

	float differenceX = playerX - colliderX;
	float differenceY = playerY - colliderY;

	if (differenceX < 0.5 && differenceY < 0.5)
	{
		std::cout << "Collision Detected!" << std::endl;
		m_player->SetVelocity(Vector2(-(m_player->GetVelocity().m_x), -(m_player->GetVelocity().m_y)));
	}

	float collider2X = m_collider2->GetPosition().m_x;
	float collider2Y = m_collider2->GetPosition().m_y;

	float difference2X = playerX - collider2X;
	float difference2Y = playerY - collider2Y;

	if (difference2X < 0.5 && difference2Y < 0.5)
	{
		std::cout << "Collision Detected!" << std::endl;
		m_player->SetVelocity(Vector2(-(m_player->GetVelocity().m_x), -(m_player->GetVelocity().m_y)));
	}


	//if(valueP1 > valueP2 && valueP1 - valueP2 < 10) ---> then collision detected

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
	//==============NOT BEING USED FOR NOW =====================================================

	//Run Update for Each

	//Condition To end game --> runs Check to see score

	//(while FALSE)
	//-->Update Game
	//-->Update Player
	//-->Update Enemy

	//(while TRYE)
	//Stop game

}

void AgentApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	
	m_2dRenderer->drawSprite(m_backgroundTexture, getWindowWidth()/2, getWindowHeight() / 2, getWindowWidth(), getWindowHeight());
	
	m_collider->Draw(m_2dRenderer, m_colliderTexture);
	m_collider2->Draw(m_2dRenderer, m_colliderTexture);
	m_player->Draw(m_2dRenderer, m_playerTexture);

	

	//m_background->draw
	
	//m_2dRenderer->drawSprite(m_background, 5, 5, 5, 5);

	//m_background->draw

	//Keyboard Movement (PLAYER)
	//m_player->Draw(m_2dRenderer);
	
	//Seek Player (ENEMY)
	//m_enemy->Draw(m_2dRenderer);

	//Wander (ENEMY)
	//m_enemyWander->Draw(m_2dRenderer);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}