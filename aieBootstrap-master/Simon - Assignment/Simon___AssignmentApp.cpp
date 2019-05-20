#include "Simon___AssignmentApp.h"
#include "Bar.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Simon Tree.h"

aie::Font *g_systemFont = nullptr;

Simon___AssignmentApp::Simon___AssignmentApp() {

}

Simon___AssignmentApp::~Simon___AssignmentApp() {

}

void Simon___AssignmentApp::GamePhase(float deltaTime)
{
	colours[0]->SetValue(-1);
	
	colours[1]->SetValue(-1);
	


	//=======ATTEMPT ONE==================
	//for (int i = 0; i < 4; i++)
	//{
		//colours[i]->SetValue(-1);
		//_sleep(500);
		//break;
		/*timer = timer - deltaTime;*/

	/*	if (i >= 3)
		{
			timer = 10;
		}*/
	//}
	//======================================



	//========ATTEMPT==TWO===================
	//int i = 0;
	//while (i < 3)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		colours[j]->SetValue(-1);
	//		_sleep(500);
	//		break;
	//	}
	//	i++;
	//}
	//======================================

	//colours[0].SetColourValue(1, 0, 0, m_2dRenderer); //RED
	



	//===========ATTEMPT THREE===============
	//colours[1].SetValue(-1);
	//colours[1].SetColourValue(1, 0, 0, m_2dRenderer);
	//_sleep(500);

	//colours[2].SetValue(-1);
	//colours[2].SetColourValue(1, 0, 0, m_2dRenderer);
	//_sleep(500);

	//======================================
	//Blink Red----Blue----Green

}

bool Simon___AssignmentApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_binaryTree = new Array();

	//string word = "WORD";

	//m_binaryTree->insert(word);

	//m_bar = new Bar(600, 150, 200, 210); //bottom Square
	colours[0] = new Bar(600, 150, 200, 210); //bottom square --RED
	colours[1] = new Bar(600, 600, 200, 210); //Top square	--BLUE
	colours[2] = new Bar(350, 350, 200, 210); //Left square	--GREEN
	colours[3] = new Bar(850, 350, 200, 210); //Right square	--YELLOWwasd

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	g_systemFont = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void Simon___AssignmentApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete colours;
	delete RED;
	delete BLUE;
	delete GREEN;
	delete YELLOW;
}

void Simon___AssignmentApp::MoveDoneForRed(float deltaTime)
{
	if (timer >= 0)
	{
		timer = timer - deltaTime; //decrement TIME
		colours[0]->SetValue(-1); //RED WILL BECOME WHITE

		if (timer < 0) //COUNTS DOWN TO 0 (FROM 0)
		{
			colours[0]->SetValue(100); //WHITE WILL THEN BECOME RED
		}
		//The entire process makes it look like it flickered
	}
}

void Simon___AssignmentApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();
	// exit the application


	

	//==========Initializing values to their original colours=====================
	colours[0]->SetValue(100); //	RED
	colours[1]->SetValue(100); //	BLUE
	colours[2]->SetValue(100); //	GREEN
	colours[3]->SetValue(100); //	YELLOW
	//===========================================================================


	//========================GAMEPHASE=========================================
		//timer = timer - deltaTime; //subtracting by a constant value
		//
		//if (timer > 4) //so it's running
		//{
		//	colours[0]->SetValue(-1);
		//	//timer = 0.5;
		//}
		//else if (timer > 3)// && timer > 0)
		//{
		//	colours[1]->SetValue(-1);
		//}
		//else if (timer < 0)
		//{
		//	colours[0]->SetValue(100);
		//	colours[1]->SetValue(100);
		//}
	//========================GAMEPHASE=========================================

	//===============================Start Game========================



	//===============================Start Game========================








	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
	else if(input->isKeyDown(aie::INPUT_KEY_S))
	{
		colours[0]->SetValue(-1);
	}
	else if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		colours[1]->SetValue(-1);
	}
	else if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		colours[2]->SetValue(-1);
	}
	else if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		colours[3]->SetValue(-1);
	}
	//else if (input->isKeyDown(aie::INPUT_KEY_E))
	//{
	//	Todraw = true;
	//	if (Todraw)
	//	{
	//		GamePhase(deltaTime);
	//		//Wait
	//		Todraw = false;
	//	}
	//	
	//}
	
}

void Simon___AssignmentApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	colours[0]->Draw(m_2dRenderer);
	colours[0]->SetColourValue(1, 0, 0, m_2dRenderer); //RED
	colours[1]->Draw(m_2dRenderer);
	colours[1]->SetColourValue(0, 0, 1, m_2dRenderer); //BLUE
	colours[2]->Draw(m_2dRenderer);
	colours[2]->SetColourValue(0, 1, 0, m_2dRenderer); //GREEN
	colours[3]->Draw(m_2dRenderer);
	colours[3]->SetColourValue(0.80, 1, 0, m_2dRenderer); //YELLOW
	//m_binaryTree->draw(m_2dRenderer, m_selectedNode);


	// output some text, uses the last used colour
	m_2dRenderer->drawText(g_systemFont, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}