#include "PhysicsEngineApp.h"
#include "PhysicsClass.h"
#include "RigidBodyClass.h"
#include "SphereClass.h"
#include "PlaneClass.h"
#include "AABBClass.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <Gizmos.h>
#include <glm\ext.hpp>
#include <vector>
#include <iostream>
#include <Windows.h>


#define _USE_MATH_DEFINES

#include <math.h>

const float ratioProportion = 900/900;

PhysicsEngineApp::PhysicsEngineApp() {

}

PhysicsEngineApp::~PhysicsEngineApp() {

}

bool PhysicsEngineApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_2dRendererGizmos = new aie::Renderer2D();

	//increase the 2d line count to maxmimize the number of objects we can draw
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	
	//	Initialize Sprites
	// background_sprite
	m_backgroundTexture = new aie::Texture("../bin/textures/CB_background_0.3.png");

	// white coin_sprite
	m_whiteCoinTexture = new aie::Texture("../bin/textures/CB_whiteCoin_0.2.png");

	// foul white coin_sprite
	m_whiteCoinFoulTexture = new aie::Texture("../bin/textures/CB_whiteFoulCoin_0.1.png");

	// Obstacles_sprite
	m_obstacleTexture = new aie::Texture("../bin/textures/CB_Obstacle_0.5.png");
	
	// Striker_sprite
	m_strikerTexture = new aie::Texture("../bin/textures/CB_StrikerCoin_0.1.png");

	#pragma region Projectile Tutorial
	//m_physicsScene = new PhysicsScene();
	//m_physicsScene->setGravity(glm::vec2(0, -10));
	//m_physicsScene->setTimeStep(0.5f);
	//float radius = 1.0f;
	//float speed = 30;
	//glm::vec2 startPos(-40, 0);
	////returns radian of 45 degrees
	//float inclination = (float)M_PI / 4.0f;
	//m_physicsScene->addActor(new SphereClass(startPos, inclination, speed, 1, radius, glm::vec4(1, 0, 0, 1)));
	//setupContinuousDemo(glm::vec2(-40,0), inclination, 30, 10);
	#pragma endregion Projectile Tutorial

	#pragma region SphereToSphere and SphereToPlane Collision [Testing Bounce]

	//m_physicsScene = new PhysicsScene();
	//m_physicsScene->setGravity(glm::vec2(0,0));

	//SphereClass *ball1 = new SphereClass(glm::vec2(0, 0), (glm::vec2(-10, -10)*15.f), 1, 2.5, 0.6, 0, 1, glm::vec4(1, 0, 0, 1));
	//SphereClass *ball2 = new SphereClass(glm::vec2(-10, 50), glm::vec2(5, 0), 1, 2.5, 0.6, 0, 1, glm::vec4(1, 0, 0, 1));
	//SphereClass *ball3 = new SphereClass(glm::vec2(0, 70), glm::vec2(-20, 0), 1, 1, 0.6, 0, 1, glm::vec4(1, 0, 0, 1));
	//SphereClass *ball4 = new SphereClass(glm::vec2(0, 60), glm::vec2(5, 0), 1, 1, 0.6, 0, 1, glm::vec4(1, 0, 0, 1));
	//sphere = new SphereClass(glm::vec2(0, 0), glm::vec2(0, 0), 1, 1, 0.6, 0, 1, glm::vec4(1, 0, 1, 1));

	//PlaneClass* plane1 = new PlaneClass(glm::normalize(glm::vec2(0, 1)), -50);
	//PlaneClass* plane2 = new PlaneClass(glm::normalize(glm::vec2(0, 1)), 50);
	//PlaneClass* plane3 = new PlaneClass(glm::normalize(glm::vec2(1, 0)), 90);
	//PlaneClass* plane4 = new PlaneClass(glm::normalize(glm::vec2(1, 0)), -90);
	////PlaneClass* plane2 = new PlaneClass(glm::normalize(glm::vec2(-1, 3)), -15);

	//m_physicsScene->addActor(ball1);
	////m_physicsScene->addActor(ball2);
	////m_physicsScene->addActor(ball3);
	////m_physicsScene->addActor(ball4);

	//m_physicsScene->addActor(plane1);
	//m_physicsScene->addActor(plane2);
	//m_physicsScene->addActor(plane3);
	//m_physicsScene->addActor(plane4);
	////m_physicsScene->addActor(plane2);

	#pragma endregion SphereToSphere and SphereToPlane Collision [Testing Bounce]

	#pragma region AABB Collision Tests

	#pragma region AABB -> Sphere Collision
	
	/*m_physicsScene = new PhysicsScene();
	m_physicsScene->setGravity(glm::vec2(0, 0));

	box = new AABBClass(glm::vec2(50,0), 20, 20);
	sphere = new SphereClass(glm::vec2(-30, 0), glm::vec2(30, 0), 10, 5, 0.8, 0, 1, glm::vec4(1, 0, 1, 1));

	m_physicsScene->addActor(sphere);
	m_physicsScene->addActor(box);*/

	#pragma endregion AABB -> Sphere Collision

	#pragma region AABB -> Plane Collision

	// set scene
	//m_physicsScene = new PhysicsScene();
	//m_physicsScene->setGravity(glm::vec2(0, -10));

	//// create box
	//box = new AABBClass(glm::vec2(20, 40), 10, 10);

	//// create plane
	//PlaneClass* plane = new PlaneClass(glm::normalize(glm::vec2(1, 1)), 20);

	////TemporaryTest
	////AABBClass* temp_box = new AABBClass(plane->getNormal() * box->getPosition() + plane->getDistance(), 1, 1);


	////m_physicsScene->addActor(temp_box);

	//// add into scene
	//m_physicsScene->addActor(box);
	//m_physicsScene->addActor(plane);


	#pragma endregion AABB -> Plane Collision

	#pragma endregion AABB Collision Tests

	#pragma region DragCheck

		#pragma region DragCollision
			
		/*m_physicsScene = new PhysicsScene();
		m_physicsScene->setGravity(glm::vec2(0, 0));

		sphere = new SphereClass(glm::vec2(0, 0), glm::vec2(0, 0), 10, 5, 0.8, 0, 1, glm::vec4(0, 0, 1, 1));
		striker = new SphereClass(glm::vec2(-50, 3), glm::vec2(40, 0), 10, 5, 0.8, 0, 1, glm::vec4(0, 1, 1, 1));

		m_physicsScene->addActor(sphere);
		m_physicsScene->addActor(striker);*/

		#pragma endregion DragCollision

		#pragma region BoxToPlaneCollision
		
		/*m_physicsScene = new PhysicsScene();
		m_physicsScene->setGravity(glm::vec2(0, -20));

		box = new AABBClass(glm::vec2(0, 10), 5, 5);
		PlaneClass* ground = new PlaneClass(glm::normalize(glm::vec2(0, 1)), -20);

		m_physicsScene->addActor(box);
		m_physicsScene->addActor(ground);*/

		#pragma endregion BoxToPlaneCollision

	#pragma endregion Rotational Velocity

	
	#pragma region Joint And Spring Tests

	//m_physicsScene = new PhysicsScene();
	//m_physicsScene->setGravity(glm::vec2(0, 0));
	//
	//sphere = new SphereClass(glm::vec2(0, 0), glm::vec2(0, 0), 10, 5, 0.6, 0, 1, glm::vec4(0, 0, 1, 1));
	//striker = new SphereClass(glm::vec2(30, 0), glm::vec2(-60,0), 1, 5, 0.6, 0, 1, glm::vec4(0, 1, 1, 1));

	////striker = new SphereClass(glm::vec2(-50, 0), 10, sin(90), 1, 5, glm::vec4(1, 0, 1, 1));

	//AABBClass* staticBox = new AABBClass(glm::vec2(0, 0), 5,5);
	//staticBox->setElasticity(0.9f);
	//staticBox->setKinematic(false);
	//sphere->setKinematic(true);

	//m_physicsScene->addActor(staticBox);
	//m_physicsScene->addActor(striker);

	#pragma endregion Joint and Spring Tests

	#pragma region GameSetup

	m_physicsScene = new PhysicsScene();
	m_physicsScene->setGravity(glm::vec2(0, 0));
	
	
	//Corners Of Board=========
	bottomLeftHole = new AABBClass(glm::vec2(-370, -370), 25, 25);
	bottomRightHole = new AABBClass(glm::vec2(370, -370), 25, 25);
	topLeftHole = new AABBClass(glm::vec2(-370, 370), 25, 25);
	topRightHole = new AABBClass(glm::vec2(370, 370), 25, 25);
	//Corners Of Board=========
	
	//Static Box Obstacles=====
	midLeftObs = new AABBClass(glm::vec2(-227, 0), 35, 35);
	midRightObs = new AABBClass(glm::vec2(230, 0), 35, 35);
	
	//=Set Kinematics to True==
	midLeftObs->setKinematic(true);
	midRightObs->setKinematic(true);
	//=========================

	//Set Kinematics To False==
	bottomLeftHole->setKinematic(false);
	bottomRightHole->setKinematic(false);
	topLeftHole->setKinematic(false);
	topRightHole->setKinematic(false);
	//Set Kinematics To False==

	
	//Edges Of Board===========
	PlaneClass* bottomPlane = new PlaneClass(glm::normalize(glm::vec2(0, 1)), -414);
	PlaneClass* topPlane = new PlaneClass(glm::normalize(glm::vec2(0, 1)), 419);
	PlaneClass* rightPlane = new PlaneClass(glm::normalize(glm::vec2(1, 0)), 427);
	PlaneClass* leftPlane = new PlaneClass(glm::normalize(glm::vec2(1, 0)), -419);
	//Edges Of Board===========
	
	
	//Sphere Variable Setter===
	m_physicsScene->addActor(sphere);
	sphere->setThisToStriker();
	sphere->setCollision(false);
	sphere->setFoul(false);
	sphere->setStartTurn(true);
	//Sphere Variable Setter===


	//Initialize For Coins In Centre=====
	m_physicsScene->addActor(centreSphere);
	m_physicsScene->addActor(sphereInner1);
	m_physicsScene->addActor(sphereInner2);
	/*m_physicsScene->addActor(sphereInner3);
	m_physicsScene->addActor(sphereInner4);
	m_physicsScene->addActor(sphereInner5);
	m_physicsScene->addActor(sphereInner6);
	m_physicsScene->addActor(sphereInner7);
	m_physicsScene->addActor(sphereInner8);*/
	//Initialize For Coins In Centre=====
	
	//add to vector=====================
	CoinsInScene.push_back(sphere);
	CoinsInScene.push_back(centreSphere);
	CoinsInScene.push_back(sphereInner1);
	CoinsInScene.push_back(sphereInner2);
	/*CoinsInScene.push_back(sphereInner3);
	CoinsInScene.push_back(sphereInner4);
	CoinsInScene.push_back(sphereInner5);
	CoinsInScene.push_back(sphereInner6);
	CoinsInScene.push_back(sphereInner7);
	CoinsInScene.push_back(sphereInner8);*/
	//add to vector=====================
	

	//Edges Of Board====================
	m_physicsScene->addActor(bottomPlane);
	m_physicsScene->addActor(topPlane);
	m_physicsScene->addActor(rightPlane);
	m_physicsScene->addActor(leftPlane);
	//Edges Of Board====================
	
	
	//Corner Holes======================
	m_physicsScene->addActor(bottomLeftHole);
	m_physicsScene->addActor(bottomRightHole);
	m_physicsScene->addActor(topLeftHole);
	m_physicsScene->addActor(topRightHole);
	//Corner Holes======================

	//Obstacles=========================
	m_physicsScene->addActor(midLeftObs);
	m_physicsScene->addActor(midRightObs);
	//Obstacles=========================
	

	#pragma endregion GameSetup

	return true;
}

void PhysicsEngineApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete m_2dRendererGizmos;
}

void PhysicsEngineApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	aie::Gizmos::clear();

	//Rocket Ship Exercise
	#pragma region RocketShip
	//Each Update
	//Repeated until mass depleted (fuel depleted)
	//check if mass greater than zero
	/*if (time > 0 && time < 10 || time > 20 && time < 30 || time > 40 && time < 50 || time > 60 && time < 70
		|| time > 80 && time < 90)
	{
		if (rocket_Ship->getMass() > 0)
		{
			Decrease mass of the rocket by M to simulate fuel being used
			fuel = fuel - 1;
			rocket_Ship->setMass(fuel);

			Create a particle sphere of mass M next to the rocket to simulate an exhaust gas particle
			SphereClass* exhaust_ptc = new SphereClass(glm::vec2(rocket_Ship->getPosition().x, (rocket_Ship->getPosition().y - 2)),
				glm::vec2(0, 0), 1, 1, glm::vec4(1, 1, 0, 1));

			m_physicsScene->addActor(exhaust_ptc);

			use ApplyForceToActor to the exhaust gas from the rocket (will be the opposite to the direction of the rocket)
			rocket_Ship->applyForceToActor(exhaust_ptc, glm::vec2(0, -1));

			 exit the application
			if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
				quit();
		}
	}*/
	#pragma endregion RocketShip
	

	m_physicsScene->update(deltaTime);
	m_physicsScene->updateGizmos();
	
	// Updates the rotational vector for each coin
	#pragma region RotationUpdate
	for (int i = 0; i < CoinsInScene.size(); i++)
	{
		CoinsInScene[i]->updateRotationVector();
	}
	#pragma endregion Updates Rotation For Each Coin

	//	If one of the player has won
	//	Display Event
	if (player1_winScreen || player2_winScreen)
	{
		winPhase();
	}
	// when game still running
	else
	{
		//	if it's time for player
		//	to take their turn
		if (playerTurnActivated)
			startPhase();
		else
			gamePhase();
	}
	

	#pragma region GameBuilding

	//std::cout << "Position X: " << sphereInner8->getPosition().x << " Y: " << sphereInner8->getPosition().y << std::endl;

	std::cout << "-----DATA OUT------" << std::endl;
	std::cout << "-------------------" << std::endl;
	if (sphere->returnPlayerTurn())
		std::cout << "-----Player Turn 1-----" << std::endl;
	else
		std::cout << "-----Player Turn 2-----" << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << std::endl;
	
	#pragma endregion GameBuilding Debug Log
	
}

void PhysicsEngineApp::startPhase()
{
	//	list of inititalized
	aie::Input* input = aie::Input::getInstance();
	aie::Input* mousePos_x = aie::Input::getInstance();
	aie::Input* mousePos_y = aie::Input::getInstance();
	glm::vec2 xMove(5, 0);


	
	
	//	query mouse x and y position
	//	cast as float
	float x_value = mousePos_x->getMouseX();
	float y_value = mousePos_y->getMouseY();
	
	//	set it to location of sphere, depending on 
	//	it's x
	if (sphere->getPosition().x > 0)
	{
		x_value = (900 / 2) - x_value;
		x_value = x_value / ratioProportion;
		//x_value = -x_value;

		//=============Y_value
		y_value = (900 / 2) - y_value*2;
		y_value = y_value / ratioProportion;
		//y_value = -y_value;
		

		x_value = x_value + sphere->getPosition().x;

		x_value = -x_value;

		//	create position from given query
		glm::vec2 tempPosition(-x_value, -y_value);
		mouseCurrentPosition = tempPosition;

	}
	else
	{
		//=============X_value
		x_value = (900 /2) - x_value;
		x_value = x_value / ratioProportion;
		x_value = -x_value;

		//=============Y_value
		y_value = (900 / 2) - y_value*2;
		y_value = y_value / ratioProportion;
		y_value = -y_value;


		x_value = x_value - sphere->getPosition().x;
		
		//	create position from given query
		glm::vec2 tempPosition(x_value, y_value);
		mouseCurrentPosition = tempPosition;
	}


	//player setup turn
	if (input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_RIGHT) && sphere->isPlaceble())
	{
		//	create vector, of scale directed towards the mouse
		glm::vec2 end = mouseCurrentPosition - sphere->getPosition() * glm::normalize(mouseCurrentPosition);

		//	track lineDistance to set find Max
		float lineDistance = glm::length((sphere->getPosition() + end) - sphere->getPosition());
		glm::vec2 LineDirCheck = sphere->getPosition() + glm::normalize(end) * 50.f;

		//	check Line Direction
		//	prevent line from being directed below sphere
		if (-end.y < 0 || (end.y / end.x > -0.004 && end.y / end.x < 0.5) ||
			(end.y / end.x < 0 && end.y / end.x > -0.5)) //greater than 0.5 but less than < 0
		{
			invalidAim = true;
			aie::Gizmos::add2DLine(sphere->getPosition(), sphere->getPosition() + end, glm::vec4(1, 0, 0, 1)); //|EDITTED RED: 1,0,0,1|
		}

		//	clamp line to max
		if (lineDistance > 350)
		{
			//	can be shot at max
			maxLine = true;
			aie::Gizmos::add2DLine(sphere->getPosition(), sphere->getPosition() + glm::normalize(end) * 350.f, glm::vec4(0, 80, 0, 1)); //|EDITTED RED: 1,0,0,1|

			//Check if Gradient of line, pointing down, and directly horizontal
			if (-end.y < 0 || (end.y / end.x > -0.004 && end.y / end.x < 0.5) ||
				(end.y / end.x < 0 && end.y / end.x > -0.5))
			{
				invalidAim = true;
				aie::Gizmos::add2DLine(sphere->getPosition(), sphere->getPosition() + glm::normalize(end) * 350.f, glm::vec4(1, 0, 0, 1)); //|EDITTED RED: 1,0,0,1|
			}
			else
			{
				//To Draw it as normal
				invalidAim = false;

				//	Player shot at Cap
				if (input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT))
				{
					//	normalize end and set scalar value to 80
					end = glm::normalize(end) * (600.f);
					sphere->setVelocity(-end);
					
					//	run game phase |Checks for any goal, and runs physics|
					playerTurnActivated = false;

					//	set player in StartTurn to false
					sphere->setStartTurn(false);

					//set striker's collision on
					sphere->setCollision(true);
				}
			}
		}
		else
		{
			//Not at max so no need to clamp
			maxLine = false;

			//Check if Gradient of line, pointing down, and directly horizontal
			if (-end.y < 0 || (end.y / end.x > -0.004 && end.y / end.x < 0.5) ||
				(end.y / end.x < 0 && end.y / end.x > -0.5))
			{
				//To Allow Draw Function to know to draw it red
				invalidAim = true;
				aie::Gizmos::add2DLine(sphere->getPosition(), sphere->getPosition() + end, glm::vec4(1, 0, 0, 1)); //|EDITTED RED: 1,0,0,1|
			}
			else
			{
				//To Draw it as normal
				invalidAim = false;

				//otherwise can be shot, if under cap
				aie::Gizmos::add2DLine(sphere->getPosition(), sphere->getPosition() + end, glm::vec4(0, 80, 0, 1));
				if (input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT))
				{
					//set velocity
					sphere->setVelocity(-end);

					//set striker's collision on
					sphere->setCollision(true);

					//run game phase |Checks for any goal, and runs physics|
					playerTurnActivated = false;

					//	set player in StartTurn to false
					sphere->setStartTurn(false);
				}
			}
		}
	}
	else
	{
		//	move along the x-axis within play area
		if (input->isKeyDown(aie::INPUT_KEY_A))
			//	if sphere inside of x boundaries
			//	let it move
			if (sphere->getPosition().x < 270 && sphere->getPosition().x > -270)
				sphere->setPosition(-xMove);
				//	if sphere outside of x boundary from LEFT
				//	clamp it's x position to max LEFT
				if (sphere->getPosition().x <= -260)
					sphere->movePosition(glm::vec2(-260, sphere->getPosition().y));
		if (input->isKeyDown(aie::INPUT_KEY_D))
			//	if sphere inside of x boundaries
			//	let it move
			if (sphere->getPosition().x < 270 && sphere->getPosition().x > -270)
				sphere->setPosition(xMove);
				//	if sphere outside of x boundary from RIGHT
				// clamp it's x position to max RIGHT
				if (sphere->getPosition().x >= 260)
					sphere->movePosition(glm::vec2(260, sphere->getPosition().y));
	}


	//	Checks If Pieces On Board Are Touching Play Area
	setFoulPieces(CoinsInScene);
	
	//	set streak off
	sphere->setStreak(false);
}

void PhysicsEngineApp::gamePhase()
{
	// Checks If Game Ended, Tallies Score
	#pragma region Tally Score
	
	// amount that can be added to players
	// minus one due to striker
	float scalar = CoinsInScene.size()-1;

	// If Player1 Score plus all pieces on board
	// less than Player2 Score, Player1 can't win
	if (ScorePlayer1 + scalar < ScorePlayer2)
	{
		// Player 2 Wins
		player2_winScreen = true;
	}
	
	// If Player2 Score plus all pieces on board
	// less than Player1 Score, Player2 can't win
	if (ScorePlayer2 + scalar < ScorePlayer1)
	{
		//Player 1 Wins
		player1_winScreen = true;
	}

	//minus 1 to ignore striker
	if (CoinsInScene.size()-1 == 0)
	{
		if (ScorePlayer1 > ScorePlayer2)
		{
			//Display Player 1 Wins
			player1_winScreen = true;
		}
		else if(ScorePlayer2 > ScorePlayer1)
		{
			//Display Player 2 Wins
			player2_winScreen = true;
		}
	}
	#pragma endregion Tallies Score and Checks if Game Ended

	// Checks If Striker Holds Condition to reset foul pieces
	#pragma region Foul Check
	if(sphere->returnResetFoulPieces())
	{
		for (int i = 0; i < CoinsInScene.size(); i++)
		{
			if (CoinsInScene[i]->isFoul() && CoinsInScene[i]->isThisStriker() == false)
			{
				CoinsInScene[i]->setFoul(false);
			}
		}

		//	don't reset unless changed through functionality
		sphere->resetFoulPieces(false);
	}
	#pragma endregion Checks If Foul Has Occured

	// Checks If Pieces Have Stored Enough Time to score
	#pragma region Score Check
	for (int i = 0; i < CoinsInScene.size(); i++)
	{
		
		if (CoinsInScene[i]->getTimeStored() > 30)
		{
			//Add Score to Player
			bool playerTurn = CoinsInScene[i]->returnPlayerTurn();

			//if it is the striker decrement score isntead of breaking out of this
			if (CoinsInScene[i]->isThisStriker())
			{
				//if playerTurn == 'PLAYER 1'
				if (playerTurn)
					ScorePlayer1--;
				else
					ScorePlayer2--;

				sphere->setStreak(true);
				for (int i = 0; i < CoinsInScene.size(); i++)
				{
					CoinsInScene[i]->rewindTime();
					CoinsInScene[i]->setVelocity(glm::vec2(0, 0));
				}
			}
			else
			{
				//if playerTurn == 'PLAYER 1'
				if (playerTurn)
					ScorePlayer1++;
				else
					ScorePlayer2++;
				
				sphere->setStreak(true);
				
				
				m_physicsScene->removeActor(CoinsInScene[i]);
				
				// store value of last position
				SphereClass* temp_value = CoinsInScene[CoinsInScene.size() - 1];
				
				// make the last position hold value of the one to delete
				CoinsInScene[CoinsInScene.size() - 1] = CoinsInScene[i];

				// make that position equal to the last value that was stored
				CoinsInScene[i] = temp_value;

				// remove from list
				CoinsInScene.pop_back();
			}
		}
	}
	#pragma endregion Checks If Score gets added
	
	// Checks If Pieces On Board Have Stopped Moving
	#pragma region Movement Check
	int valueToCheck = 0;

	//check if every piece has stopped moving, has a velocity of zero
	for (int i = 0; i < CoinsInScene.size(); i++)
	{
		//iterate through and check if velocity is zero
		if (CoinsInScene[i]->getVelocity() != glm::vec2(0, 0))
		{
			break;
		}
		else
		{
			valueToCheck++;
		}
	}
	if (valueToCheck == CoinsInScene.size())
	{
		//set position of sphere to (0,0)
		sphere->movePosition(glm::vec2(-10, -240));
		
		//reset rotation
		sphere->resetRotation();

		//reset angualar
		sphere->resetAngular();

		//reset it to collidable false
		sphere->setCollision(false);

		//reset all timeStored for objects in scene
		//set all their positions, rotation, angular velocity for prev_variables
		for (int i = 0; i < CoinsInScene.size(); i++)
		{
			//reset the time stored
			CoinsInScene[i]->resetTimeStored();
			
			//set the prev_variables
			CoinsInScene[i]->setPrevAng_vel(CoinsInScene[i]->getAngularVelocity());
			CoinsInScene[i]->setPrevRot(CoinsInScene[i]->getRotation());
			CoinsInScene[i]->setPrevPos(CoinsInScene[i]->getPosition());
		}

		//Start Player Phase again
		playerTurnActivated = true;
		
		//	set player in StartTurn to true
		sphere->setStartTurn(true);

		// Change Turn Basis--------------------
		// Condition to set for striker
		bool condition;

		//if there is no streak then switch turns
		if (sphere->ifStreak() == false)
		{
			//	set Player Turn
			if (sphere->returnPlayerTurn())
			{
				//	set it to 'PLAYER 2'
				condition = false;
				for (int i = 0; i < CoinsInScene.size(); i++)
				{
					CoinsInScene[i]->setPlayerTurn(condition);
				}
			}
			else
			{
				//	set it to 'PLAYER 2'
				condition = true;
				for (int i = 0; i < CoinsInScene.size(); i++)
				{
					CoinsInScene[i]->setPlayerTurn(condition);
				}
			}
		}
	}
	#pragma endregion Checks if pieces have stopped moving
}

void PhysicsEngineApp::winPhase()
{
	//	Get input
	aie::Input* input = aie::Input::getInstance();

	//	Check If Game Won and needs to be reset
	if (player1_winScreen || player2_winScreen)
	{
		//	Get Input To Restart
		if (input->wasKeyPressed(aie::INPUT_KEY_R))
		{
			//	set player win to false
			player1_winScreen = false;
			player2_winScreen = false;

			//Reset all initializations==========

			//Striker Variable Setter
			//m_physicsScene->addActor(sphere);
			sphere->setThisToStriker();
			sphere->setCollision(true);
			sphere->setFoul(false);
			sphere->setStartTurn(true);

			//Initialize For Coins In Centre=====
			m_physicsScene->addActor(centreSphere);
			m_physicsScene->addActor(sphereInner1);
			m_physicsScene->addActor(sphereInner2);
			m_physicsScene->addActor(sphereInner3);
			m_physicsScene->addActor(sphereInner4);
			m_physicsScene->addActor(sphereInner5);
			m_physicsScene->addActor(sphereInner6);
			m_physicsScene->addActor(sphereInner7);
			m_physicsScene->addActor(sphereInner8);
			//Initialize For Coins In Centre=====

			//add to vector=====================
			CoinsInScene.push_back(sphere);
			CoinsInScene.push_back(centreSphere);
			CoinsInScene.push_back(sphereInner1);
			CoinsInScene.push_back(sphereInner2);
			CoinsInScene.push_back(sphereInner3);
			CoinsInScene.push_back(sphereInner4);
			CoinsInScene.push_back(sphereInner5);
			CoinsInScene.push_back(sphereInner6);
			CoinsInScene.push_back(sphereInner7);
			CoinsInScene.push_back(sphereInner8);
			//add to vector=====================
		}
	}
}

void PhysicsEngineApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_2dRenderer->setCameraPos(-450, -450);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	//Win Condition
	//	Draws Win Screen For Respective Player
	if (player1_winScreen) {
		m_2dRenderer->drawText(m_font, "Player 1 WINS", getWindowWidth() / 2, getWindowHeight() / 2);
		m_2dRenderer->drawText(m_font, "Press R to reset", getWindowWidth() / 2, getWindowHeight() / 2 - 100);
	}
	if (player2_winScreen) {
		m_2dRenderer->drawText(m_font, "Player 2 WINS", getWindowWidth() / 2, getWindowHeight() / 2);
		m_2dRenderer->drawText(m_font, "Press R to reset", getWindowWidth() / 2, getWindowHeight() / 2 - 100);
	}
	
	//	If any player has not won 
	//	only then draw
	//	otherwise don't draw at all
	if (player1_winScreen == false || player2_winScreen == false)
	{
		//	Create Background Texture
		m_2dRenderer->drawSprite(m_backgroundTexture, 0, 0, getWindowWidth(), getWindowHeight());

		//Draw White Coins
		for (int i = 0; i < CoinsInScene.size(); i++)
		{
			// if this striker
			if (CoinsInScene[i]->isThisStriker())
			{
				//draw striker
				m_2dRenderer->drawSprite(m_strikerTexture, CoinsInScene[i]->getPosition().x, CoinsInScene[i]->getPosition().y,
					52, 52);
			}
			else
			{
				if (CoinsInScene[i]->isFoul())
				{
					m_2dRenderer->drawSprite(m_whiteCoinFoulTexture, CoinsInScene[i]->getPosition().x, CoinsInScene[i]->getPosition().y, 45, 45);
				}
				else
				{
					//Draw White Coin
					m_2dRenderer->drawSprite(m_whiteCoinTexture, CoinsInScene[i]->getPosition().x, CoinsInScene[i]->getPosition().y, 45, 45);
				}
			}

			//Create Vector2 of rotationVector + Coin.position
			glm::vec2 spherePlusr_end = CoinsInScene[i]->getPosition() + CoinsInScene[i]->getRotationVector();

			// This is the rotation line
			m_2dRenderer->drawLine(CoinsInScene[i]->getPosition().x, CoinsInScene[i]->getPosition().y, spherePlusr_end.x, spherePlusr_end.y, 1);
		}

		//Render in Obstacle_mid_left
		m_2dRenderer->drawSprite(m_obstacleTexture, midLeftObs->getPosition().x, midLeftObs->getPosition().y, midLeftObs->getWidth() * 2.2 - 5, midLeftObs->getHeight() * 2.2 - 5);

		//Render in Obstacle_mid_right
		m_2dRenderer->drawSprite(m_obstacleTexture, midRightObs->getPosition().x, midRightObs->getPosition().y, midRightObs->getWidth() * 2.2 - 5, midRightObs->getHeight() * 2.2 - 5);

		//draw only if right click held
		aie::Input* input = input->getInstance();
		if (input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_RIGHT))
		{
			//	create vector, of scale directed towards the mouse
			glm::vec2 end = mouseCurrentPosition - sphere->getPosition() * glm::normalize(mouseCurrentPosition);

			if (invalidAim)
			{
				m_2dRenderer->setRenderColour(1, 0, 0);
			}
			if (maxLine)
			{
				//Clamp Line Distance
				glm::vec2 end_normalized = glm::normalize(mouseCurrentPosition);
				end_normalized = end_normalized * 300.f;
				m_2dRenderer->drawLine(sphere->getPosition().x, sphere->getPosition().y, sphere->getPosition().x + end_normalized.x, sphere->getPosition().y + end_normalized.y, 10);
			}
			else
			{
				m_2dRenderer->drawLine(sphere->getPosition().x, sphere->getPosition().y, sphere->getPosition().x + mouseCurrentPosition.x, sphere->getPosition().y + mouseCurrentPosition.y, 10);
			}
		}

		m_2dRenderer->setRenderColour(0, 0, 1);


		// draw output text Player1  Score
		char Var_player1[256];
		sprintf(Var_player1, "Player1 Score: %d", ScorePlayer1);
		m_2dRenderer->drawText(m_font, Var_player1, -450, -445);

		// draw output text Player2  Score
		Var_player1[256];
		sprintf(Var_player1, "Player2 Score: %d", ScorePlayer2);
		m_2dRenderer->drawText(m_font, Var_player1, 100, -445);

		// output some text, uses the last used colour
		m_2dRenderer->drawText(m_font, Var_player1, 18, 685);

		// done drawing sprites	
		m_2dRenderer->end();


		// begin drawing Gizmos
		m_2dRendererGizmos->begin();

		static float aspectRatio = 16 / 9.f;
		aie::Gizmos::draw2D(glm::ortho<float>(-450, 450,
			-800 / aspectRatio, 800 / aspectRatio, -1.0f, 1.0f));


		m_2dRendererGizmos->end();
	}
}

//	Sets foul pieces depending on their position on the board
void setFoulPieces(std::vector <SphereClass*> arrayOfPieces)
{
	for (int i = 0; i < arrayOfPieces.size(); i++)
	{
		if (arrayOfPieces[i]->isThisStriker())
		{
			//	do nothing
			//break;
		}
		else
		{
			//continue search
			//	if in play area, or touching play area

			//	Check against y value		>>>less than the top				>>>greater than the bottom
			if (arrayOfPieces[i]->getPosition().y < -190 && arrayOfPieces[i]->getPosition().y > -290)
			{
				//	Check against x value				right								    left
				if (arrayOfPieces[i]->getPosition().x < 300 && arrayOfPieces[i]->getPosition().x > -280)
				{
					//found by testing y position
					//	sets it to foul
					arrayOfPieces[i]->setFoul(true);
				}
					
			}
		}
	}
}
