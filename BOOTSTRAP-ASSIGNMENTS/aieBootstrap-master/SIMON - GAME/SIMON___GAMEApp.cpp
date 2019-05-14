#include "SIMON___GAMEApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Square.h"

SIMON___GAMEApp::SIMON___GAMEApp() {

}

SIMON___GAMEApp::~SIMON___GAMEApp() {

}

bool SIMON___GAMEApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_square_Red = new Square(600, 600, 200, 210);
	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void SIMON___GAMEApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void SIMON___GAMEApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
	else if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		ToDraw = true;
	}
}

void SIMON___GAMEApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_square_Red->Draw(m_2dRenderer);
	if (ToDraw == true)
	{
		m_square_Red = new Square(600, 200, 200, 210);
		m_square_Red->Draw(m_2dRenderer);
	}
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}