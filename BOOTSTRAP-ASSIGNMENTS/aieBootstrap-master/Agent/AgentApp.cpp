#include "AgentApp.h"
#include "Texture.h"
#include "Font.h"


AgentApp::AgentApp() {

}

AgentApp::~AgentApp() {

}

bool AgentApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_player = new Agent();
	//m_player->SetPosition(Vector2(100.0f, 100.0f)); // set starting position
	m_player->SetPosition(Vector2(100,100)); // set starting position

	m_keyboardBehaviour = new KeyboardBehaviour();
	//m_player->AddBehaviour(m_keyboardBehaviour); //adds behaviour of keyboard

	m_enemy = new Agent();
	m_enemy->SetPosition(Vector2(500.0f, 500.0f));// sets stating position for enemy

	m_followBehaviour = new SeekBehaviour();
	m_followBehaviour->SetTarget(m_player); //sets target to follow player
	//m_enemy->AddBehaviour(m_followBehaviour);//allows the behaviour to be processed by enemy

	return true;
}

void AgentApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void AgentApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	m_player->Update(deltaTime); //since player has keyboard behaviour there is no need for
								 //an input function in update
	
	m_enemy->Update(deltaTime);//calls update on enemy changing it's vector

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void AgentApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	
	m_player->Draw(m_2dRenderer);
	m_enemy->Draw(m_2dRenderer);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}