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

	/*m_physicsScene = new PhysicsScene();
	m_physicsScene->setGravity(glm::vec2(0,-10));

	SphereClass *ball1 = new SphereClass(glm::vec2(0, 50), glm::vec2(-5, 0), 1, 1, glm::vec4(1, 0, 0, 1));
	SphereClass *ball2 = new SphereClass(glm::vec2(0, 40), glm::vec2(10, 0), 1, 1, glm::vec4(1, 0, 0, 1));
	SphereClass *ball3 = new SphereClass(glm::vec2(0, 70), glm::vec2(-20, 0), 1, 1, glm::vec4(1, 0, 0, 1));
	SphereClass *ball4 = new SphereClass(glm::vec2(0, 60), glm::vec2(5, 0), 1, 1, glm::vec4(1, 0, 0, 1));
	sphere = new SphereClass(glm::vec2(0, 0), glm::vec2(0, 0), 1, 1, glm::vec4(1, 0, 1, 1));

	PlaneClass* plane1 = new PlaneClass(glm::normalize(glm::vec2(1, 3)), 15);
	PlaneClass* plane2 = new PlaneClass(glm::normalize(glm::vec2(-2, 3)), 15);

	m_physicsScene->addActor(ball1);
	m_physicsScene->addActor(ball2);
	m_physicsScene->addActor(ball3);
	m_physicsScene->addActor(ball4);

	m_physicsScene->addActor(plane1);
	m_physicsScene->addActor(plane2);*/

	#pragma endregion SphereToSphere and SphereToPlane Collision [Testing Bounce]

	#pragma region AABB Collision Tests

	#pragma region AABB -> Sphere Collision
	/*m_physicsScene = new PhysicsScene();
	m_physicsScene->setGravity(glm::vec2(0, 0));

	box = new AABBClass(glm::vec2(20,-10), 20, 20);
	sphere = new SphereClass(glm::vec2(-10, +20), glm::vec2(+10, -10), 10, 1, glm::vec4(1, 0, 1, 1));

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

	m_physicsScene = new PhysicsScene();
	m_physicsScene->setGravity(glm::vec2(0, 0));

	sphere =						   new SphereClass(glm::vec2(5, 25), glm::vec2(0, 0), 10, 5, 0.8, 0, 1, glm::vec4(0, 0, 1, 1));
	SphereClass *sphere1 =			   new SphereClass(glm::vec2(10, 35), glm::vec2(0, 0), 10, 5, 0.8, 0, 1, glm::vec4(0, 0, 1, 1));
	SphereClass *sphere2 =			   new SphereClass(glm::vec2(20, 35), glm::vec2(0, 0), 10, 5, 0.8, 0, 1, glm::vec4(0, 0, 1, 1));
	SphereClass *sphere3 =			   new SphereClass(glm::vec2(30, 35), glm::vec2(0, 0), 10, 5, 0.8, 0, 1, glm::vec4(0, 0, 1, 1));
	SphereClass *sphere4 =			   new SphereClass(glm::vec2(0, 35), glm::vec2(0, 0), 10, 5, 0.8, 0, 1, glm::vec4(0, 0, 1, 1));
	SphereClass *sphere5 =			   new SphereClass(glm::vec2(-10, 35), glm::vec2(0, 0), 10, 5, 0.8, 0, 1, glm::vec4(0, 0, 1, 1));
	SphereClass *sphere6 =			   new SphereClass(glm::vec2(-20, 35), glm::vec2(0, 0), 10, 5, 0.8, 0, 1, glm::vec4(0, 0, 1, 1));

	//================================
	//second row
	SphereClass* s7 = new SphereClass(glm::vec2(45, 25), glm::vec2(0, 0), 10, 5, 0.8, 0, 1, glm::vec4(0, 0, 1, 1));
	
	striker =			   new SphereClass(glm::vec2(0, -20), glm::vec2(0, 40), 10, 5, 1, 0, 1, glm::vec4(0, 1, 1, 1));

	AABBClass* box = new AABBClass(glm::vec2(0, 0), 10, 10);
	PlaneClass* ground = new PlaneClass(glm::normalize(glm::vec2(0,1)), -50);
	PlaneClass* ground1 = new PlaneClass(glm::normalize(glm::vec2(0,1)), 50);

	//set Elasticity Value
	//sphere->setElasticity(0.8);
	//striker->setElasticity(1.0);

	//m_physicsScene->addActor(sphere);
	//m_physicsScene->addActor(striker);

	m_physicsScene->addActor(sphere);
	m_physicsScene->addActor(sphere1);
	m_physicsScene->addActor(sphere2);
	m_physicsScene->addActor(sphere3);
	m_physicsScene->addActor(sphere4);
	m_physicsScene->addActor(sphere5);
	m_physicsScene->addActor(sphere6);

	m_physicsScene->addActor(s7);

	m_physicsScene->addActor(striker);

	m_physicsScene->addActor(ground);
	m_physicsScene->addActor(ground1);
	//m_physicsScene->addActor(box);

	#pragma endregion DragCheck + ElasticityCheck

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

	std::cout << "Sphere Dark Blue: " << sphere->getRotation() << std::endl;
	std::cout << "Sphere Light Blue: " << striker->getRotation() << std::endl;

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
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