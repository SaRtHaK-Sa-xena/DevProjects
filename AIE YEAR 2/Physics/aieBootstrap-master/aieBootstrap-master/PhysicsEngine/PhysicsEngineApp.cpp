#include "PhysicsEngineApp.h"
#include "PhysicsClass.h"
#include "RigidBodyClass.h"
#include "SphereClass.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <Gizmos.h>
#include <glm\ext.hpp>
#include <vector>

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

	//create physics scene
	m_physicsScene = new PhysicsScene();
	
	//set gravity to zero
	m_physicsScene->setGravity(glm::vec2(0, 0));
	m_physicsScene->setTimeStep(0.01f);
	
	//create actors
	rocket_Ship = new SphereClass(glm::vec2(0, -20), glm::vec2(0, 0), fuel, 4, glm::vec4(1, 0, 0, 1));
	
	//apply force 
	rocket_Ship->applyForce(glm::vec2(0, -2));

	//add actors
	m_physicsScene->addActor(rocket_Ship);

	return true;
}

void PhysicsEngineApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void PhysicsEngineApp::update(float deltaTime) {

	time = time - 1;

	// input example
	aie::Input* input = aie::Input::getInstance();

	aie::Gizmos::clear();

	m_physicsScene->update(deltaTime);
	m_physicsScene->updateGizmos();

	//Each Update
	//Repeated until mass depleted (fuel depleted)
	//check if mass greater than zero
	if (time > 0 && time < 10 || time > 20 && time < 30 || time > 40 && time < 50 || time > 60 && time < 70
		|| time > 80 && time < 90)
	{
		if (rocket_Ship->getMass() > 0)
		{
			//Decrease mass of the rocket by M to simulate fuel being used
			fuel = fuel - 1;
			rocket_Ship->setMass(fuel);
			rocket_Ship->applyForce(glm::vec2(0, 2));
		}
	}

	//Create a particle sphere of mass M next to the rocket to simulate an exhaust gas particle
	SphereClass* exhaust_ptc = new SphereClass(glm::vec2(rocket_Ship->getPosition().x, (rocket_Ship->getPosition().y - 2)),
		glm::vec2(0, 0), 1, 1, glm::vec4(1, 1, 0, 1));

	m_physicsScene->addActor(exhaust_ptc);

	//use ApplyForceToActor to the exhaust gas from the rocket (will be the opposite to the direction of the rocket)
	rocket_Ship->applyForceToActor(exhaust_ptc, glm::vec2(0, -1));

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void PhysicsEngineApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	static float aspectRatio = 16 / 9.f;
	aie::Gizmos::draw2D(glm::ortho<float>(-100, 100,
		-100 / aspectRatio, 100 / aspectRatio, -1.0f, 1.0f));


	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}