#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "TankAssignmentApp.h"


TankAssignmentApp::TankAssignmentApp() {

}

TankAssignmentApp::~TankAssignmentApp() {

}

bool TankAssignmentApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	//load sprites in
	m_tank.load("../bin/textures/tank.png");
	m_turret.load("../bin/textures/gunturret.png");
	m_bullet.load("../bin/textures/m_bullet.png");

	//attach turret to top of tank
	m_tank.addChild(&m_turret);
	
	//m_tank.getPosition(); //retrieves current tank position;

	//m_bullet.setPosition = m_tank.getPosition();

	//center the tank
	m_tank.setPosition(getWindowWidth() / 2.f, getWindowHeight() / 2.f);	
	//Tracker = m_tank.setPosition(getWindowHeight() / 2.f, getWindowHeight()/2.f);

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void TankAssignmentApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void TankAssignmentApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	m_tank.update(deltaTime);
	bulletFired = false;
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		auto facing = m_tank.getLocalTransform()[1] * deltaTime * 100;
		m_tank.translate(facing.m_x, facing.m_y);//facing.x, facing.y)
	}
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		m_tank.rotate(deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		auto facing = m_tank.getLocalTransform()[1] * deltaTime * -100;
		m_tank.translate(facing.m_x, facing.m_y);//facing.x, facing.y)
	}
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		m_tank.rotate(-deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_Q))
	{
		m_turret.rotate(deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_E))
	{
		m_turret.rotate(-deltaTime);
	}
	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		new_bullet;//set transform matrix
		//transform matrix includes
		//location - 
		//rotation -
		//speed -

		new_bullet.

		auto facing = m_turret.getLocalTransform()[1] * deltaTime * 100; //moves with turret
		bulletFired = true;
		bulletFiredAnimate = true;
		if(bulletFiredAnimate)
		auto facing = m_turret.getLocalTransform()[1] * deltaTime * 100; //moving each frame upwards
		m_bullet.translate(facing.m_x, facing.m_y); //facing up
	}
}

void TankAssignmentApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	
	// draw the tank
	m_tank.draw(m_2dRenderer);

	if (bulletFired)
	{
		m_bullet.draw(m_2dRenderer);
	}

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}