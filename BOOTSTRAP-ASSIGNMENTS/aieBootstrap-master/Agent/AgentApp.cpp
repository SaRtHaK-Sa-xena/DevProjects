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

	m_colliderTexture = new aie::Texture("../bin/textures/Enemy.png");

	m_playerTexture = new aie::Texture("../bin/textures/ship.png");

	m_collider = new Agent();
	m_collider->SetPosition(Vector2(180, 550));

	m_collider2 = new Agent();
	m_collider2->SetPosition(Vector2(183, 110));

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

	//Collider Sets

	//Bar 1
	walls.push_back({ {182,615},{194,221}, rightSide });
	walls.push_back({ {156,615},{160,221}, leftSide });
	walls.push_back({ {156,516},{186,221}, bottomSide });
	walls.push_back({ {156,620},{436,616}, topSide });
	walls.push_back({ {182,627}, {297,625}, bottomSide });
	walls.push_back({ {297,625},{300,563},leftSide }); 
	walls.push_back({ {316,626},{320,575},rightSide });
	walls.push_back({ {320,574},{629,574},topSide });
	walls.push_back({ {302,561}, {609,562}, bottomSide });
	walls.push_back({ {607,560}, {608,443}, leftSide });
	walls.push_back({ {608, 442}, {629,442}, bottomSide });
	walls.push_back({ {632, 573}, {630, 443}, rightSide });


	//Bar 2 + 3
	walls.push_back({ {24,131},{375,128}, topSide });   //720 - 589
	walls.push_back({ {22,117},{375,117}, bottomSide });
	walls.push_back({ {375,128},{371,239},leftSide });
	walls.push_back({ {398, 241},{394,114}, rightSide });
	walls.push_back({ {371,240},{396,240},topSide });
	//divide velocity by 2

	//Bar 3
	walls.push_back({ {337,221},{514,219},topSide }); //minus 720
	walls.push_back({ {332,221},{332,231},leftSide });
	walls.push_back({ {337,233}, {513,213}, bottomSide });
	walls.push_back({ {513,219}, {514,232}, rightSide });

	//Bar 4
	walls.push_back({ {282,348}, {682,347}, topSide }); //minus 720
	walls.push_back({ {280,348}, {280, 359}, leftSide });
	walls.push_back({ {280,359}, {679,358}, bottomSide });
	walls.push_back({ {679,358}, {683,347}, rightSide });

	//Bar 5
	walls.push_back({ {485,538}, {749,536}, topSide }); //minus 720
	walls.push_back({ {485,538},{485,547}, leftSide });
	walls.push_back({ {485,538}, {749,547}, bottomSide });
	walls.push_back({ {751, 536}, {749,547}, rightSide });

	//Bar 6
	walls.push_back({ {732,240},{753,240},bottomSide }); //minus 720
	walls.push_back({ {754,240},{754,121},rightSide });
	walls.push_back({ {754,121},{944,118},bottomSide });
	walls.push_back({ {994,117},{996,56},rightSide });
	walls.push_back({ {974,57},{995,55},topSide });
	walls.push_back({ {732,240},{731,108},leftSide });
	walls.push_back({ {731,110},{973,105},bottomSide });
	walls.push_back({ {975,56},{975,105}, leftSide});
	walls.push_back({ {}, {996,55} })
})
})

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

	//keep Sake Below

	//============================Keepsake
	//for (int i = 0; i < walls.size(); i++)
	//{
	//	if (m_player->GetPosition().m_x < walls[i].BottomRightPosition.m_x)
	//	{
	//		m_player->SetVelocity(Vector2(0, m_player->GetVelocity().m_y)); //only changes x not y
	//		m_player->SetPosition(Vector2(m_player->GetPosition().m_x - 10, m_player->GetPosition().m_y));
	//	}

	//	if(m_player->GetPosition().m_x > walls[i].TopLeftposition.m_x)
	//	{

	//	}

	//	else if(m_player->GetPosition().m_y > walls[i].BottomRightPosition.m_y && m_player->GetPosition().m_y < walls[i].TopLeftposition.m_y)
	//	{
	//		
	//		m_player->SetVelocity(Vector2(-(m_player->GetVelocity().m_x), -(m_player->GetVelocity().m_y)));
	//		//m_player->SetVelocity(Vector2(0, m_player->GetVelocity().m_y)); //only changes x not y
	//		//m_player->SetPosition(Vector2(m_player->GetPosition().m_x - m_player->GetPosition().m_x, m_player->GetPosition().m_y));
	//		std::cout << "Collision Detected!" << std::endl;
	//	}
	//}
	//============================Keepsake

	for (int i = 0; i < walls.size(); i++)
	{
		if ((m_player->GetPosition().m_x < walls[i].BottomRightPosition.m_x && m_player->GetPosition().m_x > walls[i].TopLeftposition.m_x)
			&&(m_player->GetPosition().m_y > walls[i].BottomRightPosition.m_y && m_player->GetPosition().m_y < walls[i].TopLeftposition.m_y))
		{
			switch(walls[i].sideOfWall)
			{
			case rightSide:
				m_player->SetPosition(Vector2(m_player->GetPosition().m_x + 25, m_player->GetPosition().m_y));
				m_player->SetVelocity(Vector2(0, m_player->GetVelocity().m_y)); //only changes x not y
				break;

			case leftSide:
				m_player->SetPosition(Vector2(m_player->GetPosition().m_x - 25, m_player->GetPosition().m_y));
				m_player->SetVelocity(Vector2(0, m_player->GetVelocity().m_y)); //only changes x not y
				break;

			case topSide:
				m_player->SetPosition(Vector2(m_player->GetPosition().m_x, m_player->GetPosition().m_y +35));
				m_player->SetVelocity(Vector2(m_player->GetVelocity().m_x,0)); //only changes x not y
				break;

			case bottomSide:
				m_player->SetVelocity(Vector2(m_player->GetVelocity().m_x, 0)); //only changes x not y
				m_player->SetPosition(Vector2(m_player->GetPosition().m_x, m_player->GetPosition().m_y - 25));
				break;
			}
			
		}
	}


	//collider position is 250

	//							LESS THAN		//NEED MIDDLE		GREATER THAN

	//====================================AGENT COLLISION DETECTER====================================
	//if ((m_player->GetPosition().m_x < 190 && m_player->GetPosition().m_x > 170) && (m_player->GetPosition().m_y < 555 && m_player->GetPosition().m_y > 545))
	//{
	//	m_player->SetVelocity(Vector2(0, 0));
	//}
	//============================================================================================================

	//if(m_player->GetPosition().m_x < )

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