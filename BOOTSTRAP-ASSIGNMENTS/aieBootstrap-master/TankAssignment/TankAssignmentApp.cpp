#include "TankAssignmentApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "SceneObjectClass.h"

TankAssignmentApp::TankAssignmentApp() {

}

TankAssignmentApp::~TankAssignmentApp() {

}

bool TankAssignmentApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	//load sprites in
	m_tank.load("./textures/tank.png");
	m_turret.load("./textures/gunturret.png");

	//attach turret to top of tank
	m_tank.addChild(&m_turret);

	//center the tank
	m_tank.setPosition(getWindowWidth() / 2.f, getWindowHeight() / 2.f);

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

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
	/*else if (input->isKeyDown(aie::INPUT_KEY_W))
		auto facing = m_tank.getLocalTransform()[1] * deltaTime * 100;
	m_tank.translate(facing.x, facing.y);
	else if (input->isKeyDown(aie::INPUT_KEY_S))
		auto facing = m_tank.getLocalTransform()[1] *
		deltaTime * -100;
	m_tank.translate(facing.x, facing.y);
	else if (input->isKeyDown(aie::INPUT_LEY_LEFT))
		m_turret.rotate(deltaTime);
	else if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_turret.rotate(-deltaTime);*/

}

void TankAssignmentApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	
	// draw the tank
	m_tank.draw(m_2dRenderer);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}