#include "Simon___AssignmentApp.h"
#include "Bar.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Array.h"


aie::Font *g_systemFont = nullptr;

Simon___AssignmentApp::Simon___AssignmentApp() {

}

Simon___AssignmentApp::~Simon___AssignmentApp() {

}

bool Simon___AssignmentApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	SimonTree = new Array();
	//InputTree = new Array();
	/*Bar* m_bar;*/


	m_BrightRedTexture = new aie::Texture("./textures/Bright_Red.png");
	m_DarkRedTexture = new aie::Texture("./textures/Dark_Red.png");

	m_BrightYellowTexture = new aie::Texture("./textures/Bright_Yellow.png");
	m_DarkYellowTexture = new aie::Texture("./textures/Dark_Yellow.png");

	m_BrightBlueTexture = new aie::Texture("./textures/Bright_Blue.png");
	m_DarkBlueTexture = new aie::Texture("./textures/Dark_Blue.png");

	m_BrightGreenTexture = new aie::Texture("./textures/Bright_Green.png");
	m_DarkGreenTexture = new aie::Texture("./textures/Dark_Green.png");


	string red = "red";
	string blue = "blue";
	string green = "green";
	string yellow = "yellow";



	Red = new Bar(600, 150, 200, 210, red); //bottom Square
	Blue = new Bar(600, 600, 200, 210, blue); //top square
	Green = new Bar(350, 350, 200, 210, green); //left square
	Yellow = new Bar(850, 350, 200, 210, yellow); //right square
	
	//========
	m_2dRenderer->drawSprite(m_DarkRedTexture, Red->m_posX, Red->m_posY, Red->m_width, Red->m_height);
	m_2dRenderer->drawSprite(m_DarkBlueTexture, Blue->m_posX, Blue->m_posY, Blue->m_width, Blue->m_height);
	m_2dRenderer->drawSprite(m_DarkGreenTexture, Green->m_posX, Green->m_posY, Green->m_width, Green->m_height);
	m_2dRenderer->drawSprite(m_DarkRedTexture, Yellow->m_posX, Yellow->m_posY, Yellow->m_width, Yellow->m_height);
	//================


	/*Red->SetValue(100);
	Blue->SetValue(100);
	Green->SetValue(100);
	Yellow->SetValue(100);*/

	//Current equals m_pRoot
	//current = SimonTree->ReturnRoot();
	Data = new Bar(0,0,0,0,"");
	inputPhase = false;
	inputDone = false;
	SequenceFinished = false;
	//Default Start
	
	//Default Colour

	//m_bar2 = new Bar(600, 200, 200, 210);
	//m_bar2->SetValue(-1);
	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	g_systemFont = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void Simon___AssignmentApp::shutdown() {

	delete g_systemFont;
	delete m_2dRenderer;

	delete m_BrightRedTexture;
	delete m_BrightBlueTexture;
	delete m_BrightGreenTexture;
	delete m_BrightYellowTexture;

	delete m_DarkRedTexture;
	delete m_DarkBlueTexture;
	delete m_DarkGreenTexture;
	delete m_DarkYellowTexture;


	delete Red;
	delete Blue;
	delete Green;
	delete Yellow;
	delete SimonTree;
}


//void StartRound(int difficulty, int timer, int deltaTime, bool insert)
//{
//	for (difficulty; difficulty != 0; difficulty--)
//	{
//		timer = timer - deltaTime;
//		if (timer > 0)
//		{
//			if (insert == true)
//			{
//				randomColour = colours[rand() % 4]; //random and output = red,blue,green or yellow
//			}
//		}
//	}
//}





void Simon___AssignmentApp::update(float deltaTime) {

	// ==================input example===============
	aie::Input* input = aie::Input::getInstance();
	// ===============exit the application===========

	//Default Start
	//==============Intitializing==================================

	static int moves;
	static int Total_moves = 2;
	bool startGame = false;
	AlreadyDisplayed = false;
	inputPhase = false;
	//==============Intitializing==================================


	//Default Colour
	//==============INITIALIZE COLOURS RESTING TEXTURE==============
	//Red->SetValue(100);
	//Blue->SetValue(100);
	//Green->SetValue(100);
	//Yellow->SetValue(100);
	//==============INITIALIZE COLOURS RESTING TEXTURE==============

	//timer = timer - deltaTime;
	

	//if (input->wasKeyPressed(aie::INPUT_KEY_W))
//HERE
	//StartRound(deltaTime);
	//cout << "Timer: " << timer << endl;
	timer -= deltaTime * 2;
	if (difficulty > 0)
	{
		if (SequenceFinished)
		{
			cout << "Timer: " << timer << endl;
			if (timer > 4 && timer < 5)
			{
				if (randomColour == "RED")
				{
					TodrawDarkRed = true;
				}
				else if (randomColour == "BLUE")
				{
					TodrawDarkBlue = true;
				}
				else if (randomColour == "GREEN")
				{
					TodrawDarkGreen = true;
				}
				else if (randomColour == "YELLOW")
				{
					TodrawDarkYellow = true;
				}
			}
			else if (timer >= 1)
			{
				//=================Display Sequence Again===========================
				
				if (valueInsertPhase == true)
				{
					randomColour = colours[rand() % 4];
					current = SimonTree->ReturnRoot();
					SimonTree->insert(randomColour);
					valueInsertPhase = false;
					cout << "Value Inserted" << endl;
				
				}
				//==========Display By Current======================
				if (current->getData() == "RED")
				{
					TodrawDarkRed = false;
				}
				else if (current->getData() == "BLUE")
				{
					TodrawDarkBlue = false;
				}
				else if (current->getData() == "GREEN")
				{
					TodrawDarkGreen = false;
				}
				else if (current->getData() == "YELLOW")
				{
					TodrawDarkYellow = false;
				}
				//==========Display By Current======================

			}

			else if (timer > 0 && timer < 1)
			{
				TodrawDarkBlue = true;
				TodrawDarkRed = true;
				TodrawDarkGreen = true;
				TodrawDarkYellow = true;
			}
			else if (timer < 0)
			{
				timer = 5;
				TempTotaldifficulty--;
				if (TempTotaldifficulty == 0)
				{
					difficulty--;
					current = SimonTree->ReturnRoot();
					cout << "-------------CORRECT!!-----------" << endl;
					cout << "GREAT!" << endl;
					cout << "-------------CORRECT!!-----------" << endl;

				}
				else if (current->getRight() != nullptr)
				{
					current = current->getRight();
				}
				
			}

			//=================Display Sequence Again===========================

		}
		
		else
		{
			if (timer >= 1)
			{
				if (insert == true)
				{
					randomColour = colours[rand() % 4];
					current = SimonTree->ReturnRoot();
					SimonTree->insert(randomColour);
					insert = false;
				}
				if (randomColour == "RED")
				{
					TodrawDarkRed = false;
				}
				else if (randomColour == "BLUE")
				{
					TodrawDarkBlue = false;
				}
				else if (randomColour == "GREEN")
				{
					TodrawDarkGreen = false;
				}
				else if (randomColour == "YELLOW")
				{
					TodrawDarkYellow = false;
				}
			}
			else if (timer > 0 && timer < 1)
			{
				TodrawDarkRed = true;
				TodrawDarkBlue = true;
				TodrawDarkGreen = true;
				TodrawDarkYellow = true;
			}

			else if (timer <= 0)
			{
				difficulty--;
				insert = true;
				timer = 5;
			}
		}
	}
	else
	{
		TodrawDarkRed = true;
		TodrawDarkBlue = true;
		TodrawDarkGreen = true;
		TodrawDarkYellow = true;
		inputPhase = true;
		//sequnce_finished = true;
	}

	if (inputPhase == true)
	{
		if (input->wasKeyPressed(aie::INPUT_KEY_W))
		{
			TodrawDarkBlue = false;
			Data->setData("BLUE");
			inputDone = true;
		}
		else if (input->wasKeyPressed(aie::INPUT_KEY_A))
		{
			TodrawDarkGreen = false;
			Data->setData("GREEN");
			inputDone = true;
		}
		else if (input->wasKeyPressed(aie::INPUT_KEY_S))
		{
			TodrawDarkRed = false;
			Data->setData("RED");
			inputDone = true;
		}
		else if (input->wasKeyPressed(aie::INPUT_KEY_D))
		{
			TodrawDarkYellow = false;
			Data->setData("YELLOW");
			inputDone = true;
		}
	}


	if (inputDone)
	{
		inputDone = false;
		if (current->getData() == Data->getData())
		{
			if (current->getRight() != nullptr)
			{
				current = current->getRight();
			}
			else
			{
				difficulty++;
				Total_difficulty++;
				TempTotaldifficulty = Total_difficulty;
				timer = 5;
				SequenceFinished = true;
				valueInsertPhase = true;
				//increment difficulty
				//
			}
		}
		//Set Colours To Dark

		else if (current->getData() != Data->getData())
		{
			cout << "Incorrect" << endl;
			m_gameOver = true;
		}
		
		
		
	}

	//while (inputDone == false)
	



}

void Simon___AssignmentApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!

	//==========DEFAULT COLOURS===============
	//Red->Draw(m_2dRenderer, 1,0,0);
	//Blue->Draw(m_2dRenderer,0,0,1);
	//Green->Draw(m_2dRenderer,0,1,0);
	//Yellow->Draw(m_2dRenderer,0.80,1,0);
	//==========DEFAULT COLOURS===============
	
	//=====================DEFAULT RED COLOURS RENDERERD IN========================================
	if (TodrawDarkRed)
	{
		m_2dRenderer->drawSprite(m_DarkRedTexture, Red->m_posX, Red->m_posY, Red->m_width, Red->m_height);
	}//=====================DEFAULT COLOURS RENDERERD IN========================================

	else {
		m_2dRenderer->drawSprite(m_BrightRedTexture, Red->m_posX, Red->m_posY, Red->m_width, Red->m_height);
	}

	//=====================DEFAULT BLUE COLOURS RENDERERD IN========================================
	if (TodrawDarkBlue) {
		m_2dRenderer->drawSprite(m_DarkBlueTexture, Blue->m_posX, Blue->m_posY, Blue->m_width, Blue->m_height);
	}//=====================DEFAULT COLOURS RENDERERD IN========================================

	else {
		m_2dRenderer->drawSprite(m_BrightBlueTexture, Blue->m_posX, Blue->m_posY, Blue->m_width, Blue->m_height);
	}
	//=====================DEFAULT GREEN COLOURS RENDERERD IN========================================
	if (TodrawDarkGreen) {
		m_2dRenderer->drawSprite(m_DarkGreenTexture, Green->m_posX, Green->m_posY, Green->m_width, Green->m_height);
	}//=====================DEFAULT COLOURS RENDERERD IN========================================

	else {
		m_2dRenderer->drawSprite(m_BrightGreenTexture, Green->m_posX, Green->m_posY, Green->m_width, Green->m_height);
	}
	//=====================DEFAULT YELLOW COLOURS RENDERERD IN========================================
	if (TodrawDarkYellow) {
		m_2dRenderer->drawSprite(m_DarkYellowTexture, Yellow->m_posX, Yellow->m_posY, Yellow->m_width, Yellow->m_height);
	}//=====================DEFAULT COLOURS RENDERERD IN========================================

	else {
		m_2dRenderer->drawSprite(m_BrightYellowTexture, Yellow->m_posX, Yellow->m_posY, Yellow->m_width, Yellow->m_height);
	}//if (Todraw == true)
	//{
	//	/*m_bar = new Bar(600, 200, 200, 210);
	//	m_bar->Draw(m_2dRenderer);*/
	//}
	

	
	//m_binaryTree->draw(m_2dRenderer, m_selectedNode);


	// output some text, uses the last used colour
	m_2dRenderer->drawText(g_systemFont, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}


//void Simon___AssignmentApp::InputPhase()
//{
//	if (input->wasKeyPressed(aie::INPUT_KEY_W))
//	{
//
//	}
//}


//----For Later-----


//bool Simon___AssignmentApp::CheckWon(Array *firstList, Array *secondList)
//{
//	Bar *current = nullptr;
//	Bar *parent = nullptr;
//
//	firstList->
//

//	current = firstList
//	//if Won
//	return true;

//	//current = firstList
//	//if Won
//	//return true;

//
//	//else Lost
//	//return false;
//}


//----For Later-----

