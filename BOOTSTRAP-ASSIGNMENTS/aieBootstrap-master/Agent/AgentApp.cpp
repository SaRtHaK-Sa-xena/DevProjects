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

	walls.resize(16);

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

	//m_colliderTexture = new aie::Texture("../bin/textures/Enemy.png");

	m_playerTexture = new aie::Texture("../bin/textures/ship.png");

	//m_collider = new Agent();
	//m_collider->SetPosition(Vector2(180, 550));

	//m_collider2 = new Agent();
	//m_collider2->SetPosition(Vector2(183, 110));

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

	
	//Collider Walls Sets Configuration
	//Notes While Coding-
	//Keep top left position --> x LOWER than bottom right position --> x
	//Keep top left position --> y GREATER than bottom right position --> y

	//==========================Bar 1==========================
	walls.push_back({ {182,615},{194,221}, rightSide });
	walls.push_back({ {156,615},{160,221}, leftSide });
	walls.push_back({ {156,516},{186,221}, bottomSide });
	walls.push_back({ {156,620},{436,616}, bottomSide }); 
	walls.push_back({ {182,627}, {297,625}, topSide }); 
	walls.push_back({ {297,625},{300,563},leftSide }); 
	walls.push_back({ {316,626},{320,575},rightSide });
	walls.push_back({ {320,583},{629,574},topSide }); 
	walls.push_back({ {302,568}, {609,560}, bottomSide });
	walls.push_back({ {602,560}, {608,443}, leftSide });
	walls.push_back({ {608, 452}, {629,448}, bottomSide });
	walls.push_back({ {630, 573}, {634, 443}, rightSide });
	walls.push_back({ {319,642},{437,639}, topSide }); 
	walls.push_back({ {432,639},{437,627}, rightSide }); 
	//----> Diagram
	//      _________
	//	   |     |_______
	//	   |	         |
	//	   |             |
	//	   |
	//	   |
	//==========================Bar 1==========================

	//==========================Bar 2 ==========================
	walls.push_back({ {24,131},{375,128}, topSide });
	walls.push_back({ {22,120},{395,117}, bottomSide });
	walls.push_back({ {365,239},{371,128},leftSide });
	walls.push_back({ {394, 241},{398,114}, rightSide });
	walls.push_back({ {371,240},{396,240},topSide });
	//----> Diagram	
	//      ______|
	//==========================Bar 2 ==========================

	//==========================Bar 3==========================
	walls.push_back({ {337,509},{514,499},topSide }); 
	walls.push_back({ {330,499},{332,489},leftSide });
	walls.push_back({ {337,507}, {513,487}, bottomSide });
	walls.push_back({ {511,501}, {514,488}, rightSide });
	//----> Diagram
	//      ___
	//==========================Bar 3==========================

	//==========================Bar 4==========================
	walls.push_back({ {282,373}, {682,365}, topSide }); 
	walls.push_back({ {278,349}, {280, 361}, leftSide });
	walls.push_back({ {280,365}, {679,361}, bottomSide });
	walls.push_back({ {679,362}, {683,373}, rightSide });
	//----> Diagram
	//      __________
	//==========================Bar 4==========================

	//==========================Bar 5==========================
	walls.push_back({ {485,185}, {749,182}, topSide });
	walls.push_back({ {485,182},{485,173}, leftSide });
	walls.push_back({ {485,182}, {749,173}, bottomSide });
	walls.push_back({ {751, 184}, {749,173}, rightSide });
	//----> Diagram
	//      _____
	//==========================Bar 5==========================

	//==========================Bar 6==========================
	walls.push_back({ {732,485},{753,480},bottomSide }); 
	walls.push_back({ {750,599},{754,480},rightSide });
	walls.push_back({ {754,602},{994,598},bottomSide }); 
	walls.push_back({ {992,664},{996,603},rightSide });
	walls.push_back({ {974,665},{995,662},topSide });
	walls.push_back({ {728,612},{731,480},leftSide });
	walls.push_back({ {731,615},{973,610},topSide });
	walls.push_back({ {971,664},{977,615}, leftSide});
	//----> Diagram
	//       ____| 
	//		|
	//==========================Bar 6==========================

	//==========================Bar 7==========================
	walls.push_back({ {844,546},{848,399}, leftSide });
	walls.push_back({ {847,550}, {868,543}, topSide });
	walls.push_back({ {862,548},{867,398}, rightSide });
	walls.push_back({ {844,400},{865,397},bottomSide });
	//----> Diagram
	//      | 
	//		|
	//==========================Bar 7==========================

	//==========================Bar 8==========================
	walls.push_back({ {1071,560},{1092,560},topSide });
	walls.push_back({ {1065,558}, {1071,205},leftSide });
	walls.push_back({ {1070,205},{1091,204 }, bottomSide });
	walls.push_back({ {1087,559},{1093,205}, rightSide });
	//----> Diagram
	//		|
	//      | 
	//		|
	//==========================Bar 8==========================

	//=======================Bar 9==========================
	walls.push_back({ {862,287}, {884,284}, topSide });
	walls.push_back({ {860,284}, {865,90}, leftSide });
	walls.push_back({ {863,95},{1145,90},bottomSide });
	walls.push_back({ {1143,100},{1145, 89}, rightSide });
	walls.push_back({ {880,284},{884,101},rightSide });
	walls.push_back({ {884,111}, {1142,100},topSide });
	//----> Diagram
	//      | 
	//		|____
	//=======================Bar 9==========================

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

	//another implementation of the collision system
	//=============CHECKS COLLISION FOR OUTSIDE EDGE================
	//checks for OuterEdge (LEFT SIDE)
	if (m_player->GetPosition().m_x < 25)
	{
		m_player->SetVelocity(Vector2(0, m_player->GetVelocity().m_y)); //only changes x not y
		m_player->SetPosition(Vector2(m_player->GetPosition().m_x + 25, m_player->GetPosition().m_y));
	}
	//checks for OuterEdge (RIGHT SIDE)
	if (m_player->GetPosition().m_x > 1250)
	{
		m_player->SetVelocity(Vector2(0, m_player->GetVelocity().m_y)); //only changes x not y
		m_player->SetPosition(Vector2(m_player->GetPosition().m_x - 25, m_player->GetPosition().m_y));
	}
	//checks for OuterEdge (TOP SIDE)
	if (m_player->GetPosition().m_y > 700)
	{
		m_player->SetVelocity(Vector2(m_player->GetVelocity().m_x, 0)); //only changes y not x
		m_player->SetPosition(Vector2(m_player->GetPosition().m_x, m_player->GetPosition().m_y - 25));
	}
	//checks for OuterEdge (BOTTOM SIDE)
	if (m_player->GetPosition().m_y < 30)
	{
		m_player->SetVelocity(Vector2(m_player->GetVelocity().m_x, 0)); //only changes y not x
		m_player->SetPosition(Vector2(m_player->GetPosition().m_x, m_player->GetPosition().m_y + 25));
	}
	//=============CHECKS COLLISION FOR OUTSIDE EDGE================

	for (int i = 0; i < walls.size(); i++)
	{
		if ((m_player->GetPosition().m_x < walls[i].BottomRightPosition.m_x && m_player->GetPosition().m_x > walls[i].TopLeftposition.m_x)
			&&(m_player->GetPosition().m_y > walls[i].BottomRightPosition.m_y && m_player->GetPosition().m_y < walls[i].TopLeftposition.m_y))
		{
			switch(walls[i].sideOfWall)
			{
			case rightSide:
				m_player->SetPosition(Vector2(m_player->GetPosition().m_x + 15, m_player->GetPosition().m_y));
				m_player->SetVelocity(Vector2(0, m_player->GetVelocity().m_y)); //only changes x not y
				break;

			case leftSide:
				m_player->SetPosition(Vector2(m_player->GetPosition().m_x - 15, m_player->GetPosition().m_y));
				m_player->SetVelocity(Vector2(0, m_player->GetVelocity().m_y)); //only changes x not y
				break;

			case topSide:
				m_player->SetPosition(Vector2(m_player->GetPosition().m_x, m_player->GetPosition().m_y +15));
				m_player->SetVelocity(Vector2(m_player->GetVelocity().m_x,0)); //only changes y not x
				break;

			case bottomSide:
				m_player->SetVelocity(Vector2(m_player->GetVelocity().m_x, 0)); //only changes y not x
				m_player->SetPosition(Vector2(m_player->GetPosition().m_x, m_player->GetPosition().m_y - 15));
				break;
			}
			
		}
	}

	//							LESS THAN		//NEED MIDDLE		GREATER THAN

	//====================================AGENT COLLISION DETECTER====================================
	//if ((m_player->GetPosition().m_x < 190 && m_player->GetPosition().m_x > 170) && (m_player->GetPosition().m_y < 555 && m_player->GetPosition().m_y > 545))
	//{
	//	m_player->SetVelocity(Vector2(0, 0));
	//}
	//============================================================================================================

	//m_enemyWander->Update(deltaTime);

	/*if (m_player->GetPosition().m_x == m_collider->GetPosition().m_x && m_player->GetPosition().m_y == m_collider->GetPosition().m_y)
	{
		std::cout << "Collision Detected!" << std::endl;
	}*/

	//==================================== COLLISION SYSTEM Sort of Works=======================================
	//float playerX = m_player->GetPosition().m_x;
	//float playerY = m_player->GetPosition().m_y;

	//float colliderX = m_collider->GetPosition().m_x;
	//float colliderY = m_collider->GetPosition().m_y;

	//float differenceX = playerX - colliderX;
	//float differenceY = playerY - colliderY;

	//if (differenceX < 0.5 && differenceY < 0.5)
	//{
	//	std::cout << "Collision Detected!" << std::endl;
	//	m_player->SetVelocity(Vector2(-(m_player->GetVelocity().m_x), -(m_player->GetVelocity().m_y)));
	//}

	//float collider2X = m_collider2->GetPosition().m_x;
	//float collider2Y = m_collider2->GetPosition().m_y;

	//float difference2X = playerX - collider2X;
	//float difference2Y = playerY - collider2Y;

	//if (difference2X < 0.5 && difference2Y < 0.5)
	//{
	//	std::cout << "Collision Detected!" << std::endl;
	//	m_player->SetVelocity(Vector2(-(m_player->GetVelocity().m_x), -(m_player->GetVelocity().m_y)));
	//}

	//==================================== COLLISION SYSTEM Sort of Works=======================================



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
	
	m_player->Draw(m_2dRenderer, m_playerTexture);


	//drawing Boxes rectangles

	//for (int i = 0; i < walls.size(); i++)
	//{
	//	switch (walls[i].sideOfWall)
	//	{
	//	case rightSide:
	//		m_2dRenderer->setRenderColour(1, 0, 0);
	//		break;
	//	case leftSide:
	//		m_2dRenderer->setRenderColour(0, 1, 0);
	//		break;
	//	case topSide:
	//		m_2dRenderer->setRenderColour(0, 0, 1);
	//		break;
	//	case bottomSide:
	//		m_2dRenderer->setRenderColour(1, 1, 0);
	//		break;
	//	}
	//	m_2dRenderer->drawBox((walls[i].TopLeftposition.m_x - walls[i].BottomRightPosition.m_x), walls[i].TopLeftposition.m_y - walls[i].BottomRightPosition.m_y, walls)
	//}

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