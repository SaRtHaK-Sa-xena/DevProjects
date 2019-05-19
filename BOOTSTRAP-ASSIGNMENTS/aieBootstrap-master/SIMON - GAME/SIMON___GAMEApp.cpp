#include "SIMON___GAMEApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Square.h"
#include <iostream>


SIMON___GAMEApp::SIMON___GAMEApp() {

}

SIMON___GAMEApp::~SIMON___GAMEApp() {

}

bool SIMON___GAMEApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();


	Red = new Square(600, 150, 200, 210); //bottom Square
	Blue = new Square(600, 600, 200, 210);//top square
	Yellow = new Square(350, 350, 200, 210); //left square 
	Green = new Square(850, 350, 200, 210); //right square
	//Red->SetColourValue(0.80, m_2dRenderer);
	pressed = false;
	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void SIMON___GAMEApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete Red;
	delete Blue;
	delete Green;
	delete Yellow;
}
//Square colours[4];

void SIMON___GAMEApp::GamePhase()
{
	int Difficulty = 0;
	if (Difficulty == 0)
	{
		colours[0].SetValue(20);
		//void Press()
		//{
			//will press multiple
		//}
	}
}


void SIMON___GAMEApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();
	// exit the application
	Red->SetValue(100);
	Green->SetValue(100);
	Yellow->SetValue(100);
	Blue->SetValue(100);
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
	else if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		Red->SetValue(-1);
		//Red->SetColourValue(0.80, m_2dRenderer);
	}
	else if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		//delete Red;
		//Red = new Square(600, 150, 200, 210);//bottom Square
		Blue->SetValue(-1);
	}
	else if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		Yellow->SetValue(-1);
	}
	else if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		Green->SetValue(-1);
	}

}

void SIMON___GAMEApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	Red->Draw(m_2dRenderer);
	Red->SetColourValue(1, 0, 0, m_2dRenderer);
	Blue->Draw(m_2dRenderer);
	Blue->SetColourValue(0, 0, 1, m_2dRenderer);
	Green->Draw(m_2dRenderer);
	Green->SetColourValue(0, 1, 0, m_2dRenderer);
	Yellow->Draw(m_2dRenderer);
	Yellow->SetColourValue(0.80, 1, 0, m_2dRenderer);


	//if (pressed == true)
	//{
		//Red->SetValue(-1);
		//delete Red;
		//Red->SetValue(75);
		//Red->Draw(m_2dRenderer);
	//}
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}