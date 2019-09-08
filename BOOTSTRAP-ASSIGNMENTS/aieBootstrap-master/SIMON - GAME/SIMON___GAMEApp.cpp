#include "SIMON___GAMEApp.h"
#include "Square.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
//#include "SimonGameClass.h"

aie::Font* g_systemFont = nullptr;

SIMON___GAMEApp::SIMON___GAMEApp() {

}

SIMON___GAMEApp::~SIMON___GAMEApp() {

}

bool SIMON___GAMEApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	SimonTree = new DynamicArray();

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



	Red = new Square(600, 150, 200, 210, red); //bottom Square
	Blue = new Square(600, 600, 200, 210, blue); //top square
	Green = new Square(350, 350, 200, 210, green); //left square
	Yellow = new Square(850, 350, 200, 210, yellow); //right square

	//==================================================
	m_2dRenderer->drawSprite(m_DarkRedTexture, Red->m_posX, Red->m_posY, Red->m_width, Red->m_height);
	m_2dRenderer->drawSprite(m_DarkBlueTexture, Blue->m_posX, Blue->m_posY, Blue->m_width, Blue->m_height);
	m_2dRenderer->drawSprite(m_DarkGreenTexture, Green->m_posX, Green->m_posY, Green->m_width, Green->m_height);
	m_2dRenderer->drawSprite(m_DarkRedTexture, Yellow->m_posX, Yellow->m_posY, Yellow->m_width, Yellow->m_height);
	//==================================================

	Data = new Square(0, 0, 0, 0, "");
	inputPhase = false;
	inputDone = false;
	SequenceFinished = false;
	increment = 0;
	//Default Start

	//Default Colour

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	g_systemFont = new aie::Font("../bin/font/consolas.ttf", 32);



	return true;
}

void SIMON___GAMEApp::shutdown() {

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
	//delete []SimonTree;
	delete Data;
}




void SIMON___GAMEApp::update(float deltaTime) {

	// ==================input example===============
	aie::Input* input = aie::Input::getInstance();
	// ===============exit the application===========

	//Default Start
	//==============Intitializing==================================

	AlreadyDisplayed = false;
	inputPhase = false;
	//==============Intitializing==================================

	timer -= deltaTime * 2;
	if (difficulty > 0)
	{
		if (SequenceFinished)
		{
			TodrawGamePhase = true;
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
					//create random Colour
					randomColour = colours[rand() % 4];

					//Set current to beginning
					current = SimonTree->ReturnRoot();
					
					// add colour to Tree
					SimonTree->add(randomColour);
					valueInsertPhase = false;
					
					cout << "Value Inserted: "<< randomColour << endl;
					reset = true;
				}

				//=============Display By Current======================
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
				//=============Display By Current======================

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
					cout << "-----------CORRECT!!--------" << endl;
					cout << "GREAT!" << endl;
					cout << "-------------CORRECT!!-----------" << endl;
				}
				//else if(SimonTree)

				else if (increment < SimonTree->returnElementsUsed())
				{
					current = SimonTree->getAt(increment);
					increment = increment + 1;
				}

				//else if (current->getRight() != nullptr)
				//{
					//current = current->getRight();
				//}
			}
			//=================Display Sequence Again===========================
		}
		else
		{
			//Beginning Of Game
			TodrawGamePhase = true;
			if (timer >= 1)
			{
				//insert values will equal false
				//So it will display colours
				if (insert == true)
				{
					randomColour = colours[rand() % 4];
					current = SimonTree->ReturnRoot();
					SimonTree->add(randomColour);
					insert = false;
					reset = true;
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
	}

	//Now that all colours have been displayed
	//The input phase begins
	{
		if (reset)
		{
			increment = 0;
			reset = false;
		}

		//Draw Input and not Game Phase Text
		TodrawGamePhase = false;
		TodrawInputPhase = true;

		if (input->wasKeyPressed(aie::INPUT_KEY_W))
		{
			TodrawDarkBlue = false;
			
			//Set data to check against value
			Data->setData("BLUE");
			inputDone = true;
		}
		else if (input->wasKeyPressed(aie::INPUT_KEY_A))
		{
			TodrawDarkGreen = false;
			
			//Set data to check against value
			Data->setData("GREEN");
			inputDone = true;
		}
		else if (input->wasKeyPressed(aie::INPUT_KEY_S))
		{
			TodrawDarkRed = false;
			
			//Set data to check against value
			Data->setData("RED");
			inputDone = true;
		}
		else if (input->wasKeyPressed(aie::INPUT_KEY_D))
		{
			TodrawDarkYellow = false;
			
			//Set data to check against value
			Data->setData("YELLOW");
			inputDone = true;
		}
	}

	//One of the buttons pressed
	//Now it will check if it was correct
	if (inputDone)
	{
		inputDone = false;

		//if (increment < SimonTree->returnElementsUsed()-1)
		//{
			if (SimonTree->getAt(increment)->getData() == Data->getData())
			{
				//If more elements being used in Array
				if (increment < SimonTree->returnElementsUsed()-1)
				{
					//move up index
					increment = increment + 1;
				}
				else
				{
					difficulty++;
					Total_difficulty++;
					TempTotaldifficulty = Total_difficulty;
					timer = 5;
					SequenceFinished = true;
					valueInsertPhase = true;
					//bring increment back to zero
					increment = 0;
				}
			}
			else if (SimonTree->getAt(increment)->getData() != Data->getData())
			{
				cout << "Incorrect" << endl;

				//---Set Values Back In-------
				Total_difficulty = 3;
				difficulty = 3;
				timer = 5;
				SequenceFinished = false;
				insert = true;
				//---Set Values Back In-------

				//set values to reseted value
				increment = 0;

				shutdown();
				startup();

				cout << "----------RESTARTING------" << endl;
				cout << endl;
				cout << "----------RESTARTING------" << endl;
			}
		//}
		//if first value equal to value of Data then
		//if (current->getData() == Data->getData())
		//{
		//	//if current right not equal to nothing


		//	if (current->getRight() != nullptr)
		//	{
		//		current = current->getRight();
		//	}
		//	else
		//	{
		//		//increment difficulty
		//		difficulty++;
		//		Total_difficulty++;
		//		TempTotaldifficulty = Total_difficulty;
		//		timer = 5;
		//		SequenceFinished = true;
		//		valueInsertPhase = true;
		//	}
		//}

		////If current's data not equal to Data 
		//else if (current->getData() != Data->getData())
		//{
		//	cout << "Incorrect" << endl;
		//	
		//	//---Set Values Back In-------
		//	Total_difficulty = 3;
		//	difficulty = 3;
		//	timer = 5;
		//	SequenceFinished = false;
		//	insert = true;
		//	//---Set Values Back In-------


		//	shutdown();
		//	startup();

		//	cout << "----------RESTARTING------" << endl;
		//	cout << endl;
		//	cout << "----------RESTARTING------" << endl;
		//}

	}

	
}

void SIMON___GAMEApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!

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
	}

	if (TodrawGamePhase)
	{
		m_2dRenderer->drawText(g_systemFont, "GAME PHASE", 500, 300);
	}
	else
	{
		//m_2dRenderer->drawSprite(m_InputPhaseTexture, InputPhase->m_posX, InputPhase->m_posY, InputPhase->m_width, InputPhase->m_height);
		m_2dRenderer->drawText(g_systemFont, "INPUT PHASE", 500, 400);
	}

	//============KEYS FOR HELP==========================
	m_2dRenderer->drawText(g_systemFont, "W", 590, 590);
	m_2dRenderer->drawText(g_systemFont, "A", 350, 350);
	m_2dRenderer->drawText(g_systemFont, "S", 590, 100);
	m_2dRenderer->drawText(g_systemFont, "D", 850, 350);
	//============KEYS FOR HELP==========================

	// done drawing sprites
	m_2dRenderer->end();
}


