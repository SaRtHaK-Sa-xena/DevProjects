#include "Simon___AssignmentApp.h"
#include "Bar.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"


aie::Font *g_systemFont = nullptr;

Simon___AssignmentApp::Simon___AssignmentApp() {

}

Simon___AssignmentApp::~Simon___AssignmentApp() {

}

bool Simon___AssignmentApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_binaryTree = new Array();
	/*Bar* m_bar;*/
	m_bar = new Bar(600, 600, 200, 210);
	
	m_bar2 = new Bar(600, 200, 200, 210);
	m_bar2->SetValue(75);
	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	g_systemFont = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void Simon___AssignmentApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete m_bar, m_bar2;
}

void Simon___AssignmentApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	bool draw = false;
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
	else if(input->isKeyDown(aie::INPUT_KEY_W))
	{
		Todraw = true;
		
	}
}

void Simon___AssignmentApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_bar->Draw(m_2dRenderer);
	m_bar2->Draw(m_2dRenderer);

	
	//m_binaryTree->draw(m_2dRenderer, m_selectedNode);


	// output some text, uses the last used colour
	//m_2dRenderer->drawText(g_systemFont, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}