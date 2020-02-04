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
	
	setupContinuousDemo();

	return true;
}

void PhysicsEngineApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void PhysicsEngineApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

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

void PhysicsEngineApp::setupContinuousDemo(glm::vec2 startPos, float inclination, float speed, float gravity)
{
	float t = 0;
	float tStep = 0.5f;
	float radius = 1.0f;
	int segments = 12;

	glm::vec4 colour = glm::vec4(1, 1, 0, 1);

	while (t <= 5)
	{
		//calculate the x,y position of the projectile at time t
		float x = speed * t + (1 / 2 * gravity) * (t * t);

		float y = sqrt(tan(inclination / x));

		aie::Gizmos::add2DCircle(glm::vec2(x, y), radius, segments, colour);
		t += tStep;
	}
}