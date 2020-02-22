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

#define _USE_MATH_DEFINES

#include <math.h>

const float ratioProportion = 6.3;

PhysicsEngineApp::PhysicsEngineApp() {

}

PhysicsEngineApp::~PhysicsEngineApp() {

}

bool PhysicsEngineApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	//increase the 2d line count to maxmimize the number of objects we can draw
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	
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
		
		#pragma region GameSetup
		
		m_physicsScene = new PhysicsScene();
		m_physicsScene->setGravity(glm::vec2(0,0));
		

		SphereClass *crazySphere = new SphereClass(glm::vec2(-60, 30), (glm::vec2(10, -30)*3.3f), 1, 5, 0.6, 0, 1, glm::vec4(0, 0, 1, 1));
		SphereClass *crazySphere2 = new SphereClass(glm::vec2(60, -30), (glm::vec2(-10, 30)*3.3f), 1, 5, 0.6, 0, 1, glm::vec4(0, 0, 1, 1));
		
		SphereClass* striker = new SphereClass(glm::vec2(5, -20), (glm::vec2(0, 10) * 2.f), 1, 5, 0.8, 0, 1, glm::vec4(0, 0, 1, 1));

		//centre
		SphereClass *s1 = new SphereClass(glm::vec2(0, 0), glm::vec2(0, 0), 1, 5, 0.6, 0, 1, glm::vec4(0, 0, 1, 1));
		
		//first ring
		SphereClass *s2 = new SphereClass(glm::vec2(1, 2), glm::vec2(0, 0), 1, 1, 0.6, 0, 1, glm::vec4(0, 1, 1, 1));
		SphereClass *s3 = new SphereClass(glm::vec2(2, 0), glm::vec2(0, 0), 1, 1, 0.6, 0, 1, glm::vec4(0, 1, 1, 1));
		SphereClass *s4 = new SphereClass(glm::vec2(-1, 2), glm::vec2(0, 0), 1, 1, 0.6, 0, 1, glm::vec4(0, 1, 1, 1));
		SphereClass *s5 = new SphereClass(glm::vec2(-2, 0), glm::vec2(0, 0), 1, 1, 0.6, 0, 1,  glm::vec4(0, 1, 1, 1));
		SphereClass *s6 = new SphereClass(glm::vec2(-1, -2), glm::vec2(0, 0), 1, 1, 0.6, 0, 1, glm::vec4(0, 1, 1, 1));
		SphereClass *s7 = new SphereClass(glm::vec2(1, -2), glm::vec2(0, 0), 1, 1, 0.6, 0, 1,  glm::vec4(0, 1, 1, 1));



		box = new AABBClass(glm::vec2(0, -20), 5, 5);
		sphere = new SphereClass(glm::vec2(-40, 0), glm::vec2(0, 0), 1, 5, 0.6, 0, 1, glm::vec4(1, 1, 0, 1));
		SphereClass* sphere2 = new SphereClass(glm::vec2(0, 0), glm::vec2(0, 0), 1, 5, 0.6, 0, 1, glm::vec4(1, 1, 0, 1));

		AABBClass* box2 = new AABBClass(glm::vec2(0, -10), 5, 5);
		AABBClass* box3 = new AABBClass(glm::vec2(40, 10), 5, 5);
		PlaneClass* plane = new PlaneClass(glm::normalize(glm::vec2(0, 1)), -50);
		PlaneClass* plane1 = new PlaneClass(glm::normalize(glm::vec2(0, 1)), 50);
		PlaneClass* plane2 = new PlaneClass(glm::normalize(glm::vec2(1, 0)), 95);
		PlaneClass* plane3 = new PlaneClass(glm::normalize(glm::vec2(1, 0)), -95);
		
		
		m_physicsScene->addActor(box);

		
		//Sphere Variable Setter
		m_physicsScene->addActor(sphere);
		sphere->setThisToStriker();
		sphere->setCollision(false);

		m_physicsScene->addActor(sphere2);
		//m_physicsScene->addActor(box2);
		//m_physicsScene->addActor(box3);
		m_physicsScene->addActor(plane);
		m_physicsScene->addActor(plane1);
		m_physicsScene->addActor(plane2);
		m_physicsScene->addActor(plane3);

		//box->applyForce(glm::vec2(0,-20), box->getPosition());
		//box3->applyForce(glm::vec2(-20,-20), box->getPosition());

		//add to vector
		CoinsInScene.push_back(sphere);
		CoinsInScene.push_back(sphere2);
		CoinsInScene.push_back(s1);
		CoinsInScene.push_back(s2);
		CoinsInScene.push_back(s3);
		CoinsInScene.push_back(s4);
		CoinsInScene.push_back(s5);
		CoinsInScene.push_back(s6);
		CoinsInScene.push_back(s7);

		#pragma endregion GameSetup

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
	return true;
}

void PhysicsEngineApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
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
	
	//	if it's time for player
	//	to take their turn
	if (playerTurnActivated)
		startPhase();
	else
		gamePhase();

	#pragma region GameBuilding

	/*std::cout << "-----DATA OUT------" << std::endl;
	std::cout << "-------------------" << std::endl;
	if (sphere->returnPlayerTurn())
		std::cout << "-----Player Turn 1-----" << std::endl;
	else
		std::cout << "-----Player Turn 2-----" << std::endl;
	if (playerTurnActivated)
		std::cout << "Player (CAN) Move The Striker" << std::endl;
	if (playerTurnActivated == false)
		std::cout << "Player (CAN NOT) Move The Striker" << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << std::endl;*/

	#pragma endregion GameBuilding Debug Log
	
}

void PhysicsEngineApp::startPhase()
{
	//	list of inititalized
	aie::Input* input = aie::Input::getInstance();
	aie::Input* mousePos_x = aie::Input::getInstance();
	aie::Input* mousePos_y = aie::Input::getInstance();
	glm::vec2 xMove(0.5, 0);

	//	query mouse x and y position
	//	cast as float
	float x_value = mousePos_x->getMouseX();
	float y_value = mousePos_y->getMouseY();
	
	//	set it to location of sphere, depending on 
	//	it's x
	if (sphere->getPosition().x > 0)
	{
		x_value = (1280 / 2) - x_value;
		x_value = x_value / ratioProportion;
		//x_value = -x_value;

		//=============Y_value
		y_value = (720 / 2) - y_value;
		y_value = y_value / ratioProportion;
		//y_value = -y_value;

		x_value = x_value + sphere->getPosition().x;
		glm::vec2 tempPosition(x_value, -y_value);
		mouseCurrentPosition = tempPosition;
	}
	else
	{
		//=============X_value
		x_value = (1280 / 2) - x_value;
		x_value = x_value / ratioProportion;
		x_value = -x_value;

		//=============Y_value
		y_value = (720 / 2) - y_value;
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

		std::cout << "Slope: " << (end.y / end.x) << std::endl;

		//	check Line Direction
		//	prevent line from being directed below sphere
		if (-end.y < 0 || (end.y / end.x > -0.004 && end.y / end.x < 0.5) ||
			(end.y / end.x < 0 && end.y / end.x > -0.5)) //greater than 0.5 but less than < 0
		{
			aie::Gizmos::add2DLine(sphere->getPosition(), sphere->getPosition() + end, glm::vec4(1, 0, 0, 1)); //|EDITTED RED: 1,0,0,1|
		}

		//	clamp line to max
		if (lineDistance > 50)
		{
			//	can be shot at max
			aie::Gizmos::add2DLine(sphere->getPosition(), sphere->getPosition() + glm::normalize(end) * 50.f, glm::vec4(0, 80, 0, 1)); //|EDITTED RED: 1,0,0,1|
			//aie::Gizmos::add2DLine(sphere->getPosition(), sphere->getPosition() + end, glm::vec4(1, 0, 0, 1)); |ORIGINAL|
			lineDistance = 50;

			if (-end.y < 0 || (end.y / end.x > -0.004 && end.y / end.x < 0.5) ||
				(end.y / end.x < 0 && end.y / end.x > -0.5))
			{
				aie::Gizmos::add2DLine(sphere->getPosition(), sphere->getPosition() + end, glm::vec4(1, 0, 0, 1)); //|EDITTED RED: 1,0,0,1|
			}
			else
			{

				//	Player shot at Cap
				if (input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT))
				{
					//	normalize end and set scalar value to 80
					end = glm::normalize(end) * 80.f;
					sphere->setVelocity(-end);

					//	run game phase |Checks for any goal, and runs physics|
					playerTurnActivated = false;

					//set striker's collision on
					sphere->setCollision(true);

					// Condition to set for
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
			}
		}
		else
		{
			if (-end.y < 0 || (end.y / end.x > -0.004 && end.y / end.x < 0.5) ||
				(end.y / end.x < 0 && end.y / end.x > -0.5))
			{
				aie::Gizmos::add2DLine(sphere->getPosition(), sphere->getPosition() + end, glm::vec4(1, 0, 0, 1)); //|EDITTED RED: 1,0,0,1|
			}
			else
			{
				//otherwise can be shot, if under cap
				aie::Gizmos::add2DLine(sphere->getPosition(), sphere->getPosition() + end, glm::vec4(0, 80, 0, 1));
				if (input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT))
				{
					//set velocity
					sphere->setVelocity(-end * 2.f);

					//set striker's collision on
					sphere->setCollision(true);

					//run game phase |Checks for any goal, and runs physics|
					playerTurnActivated = false;

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
			}
		}
	}
	else
	{
		//	move along the x-axis within play area
		if (input->isKeyDown(aie::INPUT_KEY_A))
			//	if sphere inside of x boundaries
			//	let it move
			if (sphere->getPosition().x < 85 && sphere->getPosition().x > -85)
				sphere->setPosition(-xMove);
		//	if sphere outside of x boundary from LEFT
		//	clamp it's x position to max LEFT
		if (sphere->getPosition().x > 80)
			sphere->movePosition(glm::vec2(80, 0));
		if (input->isKeyDown(aie::INPUT_KEY_D))
			//	if sphere inside of x boundaries
			//	let it move
			if (sphere->getPosition().x < 85 && sphere->getPosition().x > -85)
				sphere->setPosition(xMove);
		//	if sphere outside of x boundary from RIGHT
		// clamp it's x position to max RIGHT
		if (sphere->getPosition().x < -80)
			sphere->movePosition(glm::vec2(-80, 0));
	}

}

void PhysicsEngineApp::gamePhase()
{
	// Checks If Pieces Have Stored Enough Time to score
	#pragma region Score Check
	for (int i = 0; i < CoinsInScene.size(); i++)
	{
		if (CoinsInScene[i]->isThisStriker())
		{
			break;
		}
		else
		{
			if (CoinsInScene[i]->getTimeStored() > 30)
			{

				//if it is the striker decrement score isntead of breaking out of this

				//Add Score to Player
				bool playerTurn = CoinsInScene[i]->returnPlayerTurn();
				//if playerTurn == 'PLAYER 1'
				if (playerTurn)
					ScorePlayer1++;
				else
					ScorePlayer2++;
				
				sphere->setStreak(true);

				//delete from scene
				delete CoinsInScene[i];
			}
		}
		
	}
	#pragma endregion Checks If Score gets added


	//	Checks If Pieces On Board Are Touching Play Area
	setFoulPieces(CoinsInScene);

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
		sphere->movePosition(glm::vec2(0, 0));
		
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

	}
	#pragma endregion Checks if pieces have stopped moving
}

void PhysicsEngineApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	//static float aspectRatio = 16 / 9.f;
	static float aspectRatio = 16 / 9.f;
	aie::Gizmos::draw2D(glm::ortho<float>(-100, 100,
		-100 / aspectRatio, 100 / aspectRatio, -1.0f, 1.0f));

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}

void PhysicsEngineApp::setupContinuousDemo(glm::vec2 startPos, float inclination, float speed, float gravity)
{
	float t = 0;
	float tStep = 0.5f;
	float radius = 0.5f;
	int segments = 12;

	glm::vec4 colour = glm::vec4(1, 1, 0, 1);

	while (t <= 5)
	{
		//calculate the x,y position of the projectile at time t
		//-------------------KEY----------------------|
		//ini velocity of x = speed * cos(inclination)| 
		//ini velocity of y = speed * sin(inclination)|
		//--------------------------------------------|

		//x = ini x pos + ini vel of x times t 
		float x = startPos.x + (speed * t * cos(inclination));
		
		//y = ini y pos + ini vel of y times t plus half of g times squared t
		float y = startPos.y + (speed * t * sin(inclination)) - (0.5 * gravity * pow(t,2));

		//create a circle if position, radius, segment, colour 
		aie::Gizmos::add2DCircle(glm::vec2(x, y), radius, segments, colour);
		
		//increment time to be by timeStep of 0.5
		t += tStep;
	}
}

void setFoulPieces(std::vector <SphereClass*> arrayOfPieces)
{
	for (int i = 0; i < arrayOfPieces.size(); i++)
	{
		if (arrayOfPieces[i]->isThisStriker())
		{
			break;
		}
		else
		{
			//continue search
			//	if in play area, or touching play area
			if (arrayOfPieces[i]->getPosition().y > -5 && arrayOfPieces[i]->getPosition().y < 5)
			{
				//found by testing y position
				//	sets it to foul
				arrayOfPieces[i]->setFoul(true);
			}
		}
	}
}
