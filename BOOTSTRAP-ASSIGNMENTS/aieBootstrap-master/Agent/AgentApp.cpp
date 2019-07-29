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

	srand(time(NULL)); //for randomizing

	walls.resize(16); //sets walls vector to 16
	contact.resize(4); //sets contact vector to 4
	collectibles.resize(10); //sets collectible vector to 10 
	Items.resize(10); //sets 10 items



	m_2dRenderer = new aie::Renderer2D();
	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_backgroundTexture = new aie::Texture("../bin/textures/Background.png");

	m_playerTexture = new aie::Texture("../bin/textures/ship.png");

	m_enemyTexture = new aie::Texture("../bin/textures/EnemyNuclear.png");

	m_mainMenuTexture = new aie::Texture("../bin/textures/MainMenu.png");

	m_itemTexture = new aie::Texture("../bin/textures/collectableItem.png");

	//Create Player
	m_player = new Agent();
	//m_player->SetPosition(Vector2(getWindowWidth() / 2.f, getWindowHeight() / 2.f));

	m_keyboardBehaviour = new KeyboardBehaviour();
	m_player->AddBehaviour(m_keyboardBehaviour); //adds behaviour of keyboard

	
	//Create enemy
	m_enemy = new Agent();
	//m_enemy->SetPosition(Vector2(500, 500));// sets starting position for enemy

	m_followBehaviour = new SeekBehaviour();
	m_followBehaviour->SetTarget(m_player); //sets target to follow player
	m_enemy->AddBehaviour(m_followBehaviour);//allows the behaviour to be processed by enemy


	m_collectibles = new Agent();
	m_collectibles->SetPosition(Vector2(80, 453));

	m_collectibles1 = new Agent();
	m_collectibles1->SetPosition(Vector2(427, 433));


	//ITEM NO 1
	Items.push_back({ {398,263},{398,312},leftSide, ItemNO1 });
	Items.push_back({ {398,263},{454,262},topSide, ItemNO1 });
	Items.push_back({ {454,263},{454,312},rightSide, ItemNO1 });
	Items.push_back({ {398,312},{454,313},bottomSide, ItemNO1 });

	//ITEM NO 2
	Items.push_back({ {585,483},{585,503},leftSide, ItemNO2 });
	Items.push_back({ {585,483},{651,453},topSide, ItemNO2 });
	Items.push_back({ {641,453},{641,503},rightSide, ItemNO2 });
	Items.push_back({ {587,502},{641,503},bottomSide, ItemNO2 });

	//ITEM NO 3
	Items.push_back({ {43,636},{43,685},leftSide, ItemNO3 });
	Items.push_back({ {43,636},{97,636},topSide, ItemNO3 });
	Items.push_back({ {98,636},{98,685},rightSide, ItemNO3 });
	Items.push_back({ {42,684},{97,685},bottomSide, ItemNO3 });

	//ITEM NO 4
	Items.push_back({ {588,631},{588,680},leftSide, ItemNO4 });
	Items.push_back({ {587,631},{643,630},topSide, ItemNO4 });
	Items.push_back({ {643,630},{643,680},rightSide, ItemNO4 });
	Items.push_back({ {588,680},{643,680},bottomSide, ItemNO4 });

	//ITEM NO 5
	Items.push_back({ {934,533},{934,583},leftSide, ItemNO5 });
	Items.push_back({ {934,533},{989,532},topSide, ItemNO5 });
	Items.push_back({ {988,533},{989,583},rightSide, ItemNO5 });
	Items.push_back({ {934,683},{989,582},bottomSide, ItemNO5 });

	//ITEM NO 6
	Items.push_back({ {1173,634},{1172,685},leftSide, ItemNO6 });
	Items.push_back({ {1173,634},{1226,634},topSide, ItemNO6 });
	Items.push_back({ {1227,635},{1227,684},rightSide, ItemNO6 });
	Items.push_back({ {1173,684},{1227,684},bottomSide, ItemNO6 });

	//ITEM NO 7
	Items.push_back({ {943,216},{943,265},leftSide, ItemNO7 });
	Items.push_back({ {943,216},{998,216},topSide, ItemNO7 });
	Items.push_back({ {998,216},{997,265},rightSide, ItemNO7 });
	Items.push_back({ {942,266},{997,265},bottomSide, ItemNO7 });


	//ITEM NO 8
	Items.push_back({ {1138,46},{1138,94},leftSide, ItemNO8 });
	Items.push_back({ {1138,46},{1192,45},topSide, ItemNO8 });
	Items.push_back({ {1192,46},{1193,94},rightSide, ItemNO8 });
	Items.push_back({ {1138,94},{1193,94},bottomSide, ItemNO8 });

	//ITEM NO 9
	Items.push_back({ {625,36},{625,85},leftSide, ItemNO9 });
	Items.push_back({ {625,36},{680,35},topSide, ItemNO9 });
	Items.push_back({ {679,35},{680,86},rightSide, ItemNO9 });
	Items.push_back({ {625,85},{680,85},bottomSide, ItemNO9 });

	//ITEM NO 10
	Items.push_back({ {52,245},{52,295},leftSide, ItemNO10 });
	Items.push_back({ {52,245},{107,246},topSide, ItemNO10 });
	Items.push_back({ {107,246},{107,295},rightSide, ItemNO10 });
	Items.push_back({ {52,295},{107,295},bottomSide, ItemNO10 });

	//m_collectibles2 = new Agent();
	//m_collectibles
	//m_enemyWander = new Agent();
	//m_enemyWander->SetPosition(Vector2(getWindowWidth() / 2.f, getWindowHeight() / 2.f));


	//m_wanderBehaviour = new WanderBehaviour();
	//m_enemyWander->AddBehaviour(m_wanderBehaviour);


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
	walls.push_back({ {971,664},{977,615}, leftSide });
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

	//ITEM NUMBER 1
	//collectibles.push_back({ {},{},leftSide });

	contact.push_back({ {0,0},{0,0}, topSide});

	return true;
}

void AgentApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete m_followBehaviour;
	delete m_enemy;
	delete m_keyboardBehaviour;
	delete m_player;
	delete m_enemyTexture;
	delete m_playerTexture;
	delete m_backgroundTexture;
}

void AgentApp::update(float deltaTime) {



	// input example
	aie::Input* input = aie::Input::getInstance();
	
	//Condition to start the game
	if (startGame == false)
	{
		std::cout << "Start Game Set To False" << std::endl;
		if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
		{
			startGame = true; //start game
			drawMainMenu = false; //don't draw Main Menu
			createdEntity = false; //set position of player, and enemy
		}
		else
		{
			startGame = false;
		}
	}

	//Checks If The Player And Enemy Should be Drawn
	if (createdEntity == false)
	{
		m_enemy->SetPosition(Vector2(500, 500));// sets starting position for enemy
		m_player->SetPosition(Vector2(getWindowWidth() / 2.f, getWindowHeight() / 2.f));
		createdEntity = true;
	}

	//Score Check



	//Starts Game
	if (startGame == true)
	{
		m_player->Update(deltaTime); //since player has keyboard behaviour there is no need for
		//							 //an input function in update
		
		//m_enemyWander->Update(deltaTime); //calls update on wanderingEnemy changing it's force
										 //and direction it's pointing

		m_enemy->Update(deltaTime);//calls update on enemy changing it's vector

		m_collectibles->Update(deltaTime);


		//Error Being Pulled Here
		if (Score > 5) //if score greater than 5 make enemy seek
		{
			m_enemy->AddBehaviour(m_wanderBehaviour); //for now will be wandering
		}


		//Under Enemy Update
		//Tracks Enemy Position For Collision
		contact[0].TopLeftposition = Vector2(m_enemy->GetPosition().m_x - 15, m_enemy->GetPosition().m_y + 25);
		contact[0].BottomRightPosition = Vector2(m_enemy->GetPosition().m_x + 10, m_enemy->GetPosition().m_y + 20);
		contact[0].sideOfWall = topSide;

		contact[1].TopLeftposition = Vector2(m_enemy->GetPosition().m_x - 15, m_enemy->GetPosition().m_y + 20);
		contact[1].BottomRightPosition = Vector2(m_enemy->GetPosition().m_x - 10, m_enemy->GetPosition().m_y - 20);
		contact[1].sideOfWall = leftSide;

		contact[2].TopLeftposition = Vector2(m_enemy->GetPosition().m_x - 15, m_enemy->GetPosition().m_y - 20);
		contact[2].BottomRightPosition = Vector2(m_enemy->GetPosition().m_x + 15, m_enemy->GetPosition().m_y - 23);
		contact[2].sideOfWall = bottomSide;

		contact[3].TopLeftposition = Vector2(m_enemy->GetPosition().m_x + 15, m_enemy->GetPosition().m_y + 23);
		contact[3].BottomRightPosition = Vector2(m_enemy->GetPosition().m_x + 19, m_enemy->GetPosition().m_y - 20);
		contact[3].sideOfWall = rightSide;
		//End of collision check function

		

		//Tracks Collectible Position For Collision
		collectibles[0].TopLeftposition = Vector2(m_collectibles->GetPosition().m_x - 15, m_collectibles->GetPosition().m_y + 25);
		collectibles[0].BottomRightPosition = Vector2(m_collectibles->GetPosition().m_x + 10, m_collectibles->GetPosition().m_y + 20);
		collectibles[0].sideOfWall = topSide;

		collectibles[1].TopLeftposition = Vector2(m_collectibles->GetPosition().m_x - 15, m_collectibles->GetPosition().m_y + 20);
		collectibles[1].BottomRightPosition = Vector2(m_collectibles->GetPosition().m_x - 10, m_collectibles->GetPosition().m_y - 20);
		collectibles[1].sideOfWall = leftSide;

		collectibles[2].TopLeftposition = Vector2(m_collectibles->GetPosition().m_x - 15, m_collectibles->GetPosition().m_y - 20);
		collectibles[2].BottomRightPosition = Vector2(m_collectibles->GetPosition().m_x + 15, m_collectibles->GetPosition().m_y - 23);
		collectibles[2].sideOfWall = bottomSide;

		collectibles[3].TopLeftposition = Vector2(m_collectibles->GetPosition().m_x + 15, m_collectibles->GetPosition().m_y + 23);
		collectibles[3].BottomRightPosition = Vector2(m_collectibles->GetPosition().m_x + 19, m_collectibles->GetPosition().m_y - 20);
		collectibles[3].sideOfWall = rightSide;
		//End of collision check function

		//Collectible Number 2
		collectibles[4].TopLeftposition = Vector2(m_collectibles1->GetPosition().m_x - 15, m_collectibles1->GetPosition().m_y + 25);
		collectibles[4].BottomRightPosition = Vector2(m_collectibles1->GetPosition().m_x + 10, m_collectibles1->GetPosition().m_y + 20);
		collectibles[4].sideOfWall = topSide;
		collectibles[5].TopLeftposition = Vector2(m_collectibles1->GetPosition().m_x - 15, m_collectibles1->GetPosition().m_y + 20);
		collectibles[5].BottomRightPosition = Vector2(m_collectibles1->GetPosition().m_x - 10, m_collectibles1->GetPosition().m_y - 20);
		collectibles[5].sideOfWall = leftSide;
		collectibles[6].TopLeftposition = Vector2(m_collectibles1->GetPosition().m_x - 15, m_collectibles1->GetPosition().m_y - 20);
		collectibles[6].BottomRightPosition = Vector2(m_collectibles1->GetPosition().m_x + 15, m_collectibles1->GetPosition().m_y - 23);
		collectibles[6].sideOfWall = bottomSide;
		collectibles[7].TopLeftposition = Vector2(m_collectibles1->GetPosition().m_x + 15, m_collectibles1->GetPosition().m_y + 23);
		collectibles[7].BottomRightPosition = Vector2(m_collectibles1->GetPosition().m_x + 19, m_collectibles1->GetPosition().m_y - 20);
		collectibles[7].sideOfWall = rightSide;



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

		//Checks for collision for PLAYER
		for (int i = 0; i < walls.size(); i++)
		{
			if ((m_player->GetPosition().m_x < walls[i].BottomRightPosition.m_x && m_player->GetPosition().m_x > walls[i].TopLeftposition.m_x)
				&& (m_player->GetPosition().m_y > walls[i].BottomRightPosition.m_y && m_player->GetPosition().m_y < walls[i].TopLeftposition.m_y))
				//This check is basically making sure the player is inside these parameters of topLeft (x,y) and bottomRight (x,y)
			{
				switch (walls[i].sideOfWall)
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
					m_player->SetPosition(Vector2(m_player->GetPosition().m_x, m_player->GetPosition().m_y + 15));
					m_player->SetVelocity(Vector2(m_player->GetVelocity().m_x, 0)); //only changes y not x
					break;

				case bottomSide:
					m_player->SetVelocity(Vector2(m_player->GetVelocity().m_x, 0)); //only changes y not x
					m_player->SetPosition(Vector2(m_player->GetPosition().m_x, m_player->GetPosition().m_y - 15));
					break;
				}

			}
		}


		//=============CHECKS COLLISION FOR OUTSIDE EDGE (ENEMY) ================
	//checks for OuterEdge (LEFT SIDE)
		if (m_enemy->GetPosition().m_x < 25)
		{
			m_enemy->SetVelocity(Vector2(0, m_enemy->GetVelocity().m_y)); //only changes x not y
			m_enemy->SetPosition(Vector2(m_enemy->GetPosition().m_x + 25, m_enemy->GetPosition().m_y));
		}
		//checks for OuterEdge (RIGHT SIDE)
		if (m_enemy->GetPosition().m_x > 1250)
		{
			m_enemy->SetVelocity(Vector2(0, m_enemy->GetVelocity().m_y)); //only changes x not y
			m_enemy->SetPosition(Vector2(m_enemy->GetPosition().m_x - 25, m_enemy->GetPosition().m_y));
		}
		//checks for OuterEdge (TOP SIDE)
		if (m_enemy->GetPosition().m_y > 700)
		{
			m_enemy->SetVelocity(Vector2(m_enemy->GetVelocity().m_x, 0)); //only changes y not x
			m_enemy->SetPosition(Vector2(m_enemy->GetPosition().m_x, m_enemy->GetPosition().m_y - 25));
		}
		//checks for OuterEdge (BOTTOM SIDE)
		if (m_enemy->GetPosition().m_y < 30)
		{
			m_enemy->SetVelocity(Vector2(m_enemy->GetVelocity().m_x, 0)); //only changes y not x
			m_enemy->SetPosition(Vector2(m_enemy->GetPosition().m_x, m_enemy->GetPosition().m_y + 25));
		}
		//=============CHECKS COLLISION FOR OUTSIDE EDGE (ENEMY) ================


		//Runnning Collision Tests for Enemy (SEEK)
		for (int i = 0; i < walls.size(); i++)
		{
			if ((m_enemy->GetPosition().m_x < walls[i].BottomRightPosition.m_x && m_enemy->GetPosition().m_x > walls[i].TopLeftposition.m_x)
				&& (m_enemy->GetPosition().m_y > walls[i].BottomRightPosition.m_y && m_enemy->GetPosition().m_y < walls[i].TopLeftposition.m_y))
				//This check is basically making sure the player is inside these parameters of topLeft (x,y) and bottomRight (x,y)
			{
				switch (walls[i].sideOfWall)
				{
				case rightSide:
					m_enemy->SetPosition(Vector2(m_enemy->GetPosition().m_x + 15, m_enemy->GetPosition().m_y));
					m_enemy->SetVelocity(Vector2(0, m_enemy->GetVelocity().m_y)); //only changes x not y
					break;

				case leftSide:
					m_enemy->SetPosition(Vector2(m_enemy->GetPosition().m_x - 15, m_enemy->GetPosition().m_y));
					m_enemy->SetVelocity(Vector2(0, m_enemy->GetVelocity().m_y)); //only changes x not y
					break;

				case topSide:
					m_enemy->SetPosition(Vector2(m_enemy->GetPosition().m_x, m_enemy->GetPosition().m_y + 15));
					m_enemy->SetVelocity(Vector2(m_enemy->GetVelocity().m_x, 0)); //only changes y not x
					break;

				case bottomSide:
					m_enemy->SetVelocity(Vector2(m_enemy->GetVelocity().m_x, 0)); //only changes y not x
					m_enemy->SetPosition(Vector2(m_enemy->GetPosition().m_x, m_enemy->GetPosition().m_y - 15));
					break;
				}
			}
		}
		

		//Collision Test for Player Contact With Enemy
		for (int i = 0; i < contact.size(); i++)
		{
			if ((m_player->GetPosition().m_x < contact[i].BottomRightPosition.m_x && m_player->GetPosition().m_x > contact[i].TopLeftposition.m_x)
				&& (m_player->GetPosition().m_y > contact[i].BottomRightPosition.m_y && m_player->GetPosition().m_y < contact[i].TopLeftposition.m_y))
				//This check is basically making sure the player is inside these parameters of topLeft (x,y) and bottomRight (x,y)
			{
				switch (contact[i].sideOfWall)
				{
				case rightSide:
					m_player->SetVelocity(Vector2(0, m_player->GetVelocity().m_y)); //only changes x not y
					std::cout << "Right Contact Enemy" << std::endl;
					break;

				case leftSide:
					m_player->SetVelocity(Vector2(0, m_player->GetVelocity().m_y)); //only changes x not y
					std::cout << "Left Contact Enemy" << std::endl;
					break;

				case topSide:
					m_player->SetVelocity(Vector2(m_player->GetVelocity().m_x, 0)); //only changes y not x
					std::cout << "Top Contact Enemy" << std::endl;
					break;

				case bottomSide:
					m_player->SetVelocity(Vector2(m_player->GetVelocity().m_x, 0)); //only changes y not x
					std::cout << "Bottom Contact Enemy" << std::endl;
					break;
				}

			}
		}


		//Player Collision With Collectibles Tests
		for (int i = 0; i < collectibles.size(); i++)
		{
			if ((m_player->GetPosition().m_x < collectibles[i].BottomRightPosition.m_x && m_player->GetPosition().m_x > collectibles[i].TopLeftposition.m_x)
				&& (m_player->GetPosition().m_y > collectibles[i].BottomRightPosition.m_y && m_player->GetPosition().m_y < collectibles[i].TopLeftposition.m_y))
				//This check is basically making sure the player is inside these parameters of topLeft (x,y) and bottomRight (x,y)
			{
				switch (collectibles[i].sideOfWall)
				{
				case rightSide:
					//m_player->SetVelocity(Vector2(0, m_player->GetVelocity().m_y)); //only changes x not y
					std::cout << "Right Contact Collectible" << std::endl;
					Score++;
					break;

				case leftSide:
					//m_player->SetVelocity(Vector2(0, m_player->GetVelocity().m_y)); //only changes x not y
					std::cout << "Left Contact Collectible" << std::endl;
					Score++;
					break;

				case topSide:
					//m_player->SetVelocity(Vector2(m_player->GetVelocity().m_x, 0)); //only changes y not x
					std::cout << "Top Contact Collectible" << std::endl;
					Score++;
					break;

				case bottomSide:
					//m_player->SetVelocity(Vector2(m_player->GetVelocity().m_x, 0)); //only changes y not x
					std::cout << "Bottom Contact Collectible" << std::endl;
					Score++;
					break;
				}

			}
		}

		//Condition To end game --> runs Check to see score

		//(while FALSE)
		//-->Update Game
		//-->Update Player
		//-->Update Enemy

		//(while TRYE)
		//Stop game
	}
}

void AgentApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	
	//Background Texture
	m_2dRenderer->drawSprite(m_backgroundTexture, getWindowWidth()/2, getWindowHeight() / 2, getWindowWidth(), getWindowHeight());
	
	//Draw Main Menu
	if(drawMainMenu)
		m_2dRenderer->drawSprite(m_mainMenuTexture, getWindowWidth() / 2, getWindowHeight() / 2, getWindowWidth(), getWindowHeight());
	//Seek Player (ENEMY)
	m_enemy->Draw(m_2dRenderer, m_enemyTexture);
	//Keyboard Movement (PLAYER)
	m_player->Draw(m_2dRenderer, m_playerTexture);

	m_collectibles->Draw(m_2dRenderer, m_itemTexture);
	m_collectibles1->Draw(m_2dRenderer, m_itemTexture);
	

	//Wander (ENEMY)
	//m_enemyWander->Draw(m_2dRenderer, m_enemyTexture);
	//m_2dRenderer->drawLine(m_enemyWander->GetPosition().m_x, m_enemyWander->GetPosition().m_y, m_enemyWander->GetVelocity().m_x * 1000 + m_enemyWander->GetPosition().m_x, m_enemyWander->GetVelocity().m_y * 1000 + m_enemyWander->GetPosition().m_y,5);
	
	//Seek Player (ENEMY)
	//m_enemy->Draw(m_2dRenderer,m_enemyTexture);

	char Var[256];
	sprintf(Var, "SCORE: %d", Score);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, Var, 18, 685);

	

	// done drawing sprites
	m_2dRenderer->end();
}