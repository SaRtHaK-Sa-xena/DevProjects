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
	
	//Create renderer
	m_2dRenderer = new aie::Renderer2D();
	
	//Create Tree to use
	SimonTree = new DynamicArray();

	//====================================Load in Textures=========================
	m_BrightRedTexture = new aie::Texture("./textures/Bright_Red.png");
	m_DarkRedTexture = new aie::Texture("./textures/Dark_Red.png");

	m_BrightYellowTexture = new aie::Texture("./textures/Bright_Yellow.png");
	m_DarkYellowTexture = new aie::Texture("./textures/Dark_Yellow.png");

	m_BrightBlueTexture = new aie::Texture("./textures/Bright_Blue.png");
	m_DarkBlueTexture = new aie::Texture("./textures/Dark_Blue.png");

	m_BrightGreenTexture = new aie::Texture("./textures/Bright_Green.png");
	m_DarkGreenTexture = new aie::Texture("./textures/Dark_Green.png");
	//====================================Load in Textures=========================

	//create a string of colours
	string red = "red";
	string blue = "blue";
	string green = "green";
	string yellow = "yellow";


	//add colours in with instantiated default nodes
	Red = new Square(600, 150, 200, 210, red); //bottom Square
	Blue = new Square(600, 600, 200, 210, blue); //top square
	Green = new Square(350, 350, 200, 210, green); //left square
	Yellow = new Square(850, 350, 200, 210, yellow); //right square

	//==================================================
	//Use instantiated nodes specific data to load in attribute details to user
	m_2dRenderer->drawSprite(m_DarkRedTexture, Red->m_posX, Red->m_posY, Red->m_width, Red->m_height);
	m_2dRenderer->drawSprite(m_DarkBlueTexture, Blue->m_posX, Blue->m_posY, Blue->m_width, Blue->m_height);
	m_2dRenderer->drawSprite(m_DarkGreenTexture, Green->m_posX, Green->m_posY, Green->m_width, Green->m_height);
	m_2dRenderer->drawSprite(m_DarkRedTexture, Yellow->m_posX, Yellow->m_posY, Yellow->m_width, Yellow->m_height);
	//==================================================

	//create a temporary value to be edited and compared with
	Data = new Square(0, 0, 0, 0, "");
	
	//second phase input will equal to false
	inputPhase = false;
	
	//since no input will be done in beginning
	//don't start checking
	
	inputDone = false;
	
	//Sequence will not be finished
	//So don't start second phase
	SequenceFinished = false;
	
	//start increment at 0
	increment = 0;

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	g_systemFont = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void SIMON___GAMEApp::shutdown() {

	//Delete all used components

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
	delete Data;
	//Delete all used components
}




void SIMON___GAMEApp::update(float deltaTime) {

	// ==================input example===============
	aie::Input* input = aie::Input::getInstance();

	//==============Intitializing==================================
	//nothing is displayed so will equal false
	AlreadyDisplayed = false;
	//don't start input phase at beginning of each phase
	inputPhase = false;
	//==============Intitializing==================================

	//counter that counts down by delta Time
	timer -= deltaTime * 2;

	//if the difficulty is greater than 0
	//To add colours or display it
	if (difficulty > 0)
	{
		//only triggered the second time
		if (SequenceFinished)
		{
			//Draw Game Phase text
			TodrawGamePhase = true;
			
			//In beginning
			if (timer > 4 && timer < 5)
			{
				//Display last used colour to be dark
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

			//if timer greater or equal to 1
			else if (timer >= 1)
			{

				//=================Display Sequence Again===========================
				//since when sequenceFinished is true, insert phase will also equal true
				if (valueInsertPhase == true)
				{
					//create random Colour
					randomColour = colours[rand() % 4];

					//Set current to beginning
					current = SimonTree->ReturnRoot();
					
					// add colour to Tree
					SimonTree->add(randomColour);
					
					for (int i = 0; i < SimonTree->returnElementsUsed(); i++) {
						cout << "Value Stored: " << SimonTree->getAt(i)->getData() << endl;
					}

					//set to false so it doesn't immediate call this function again
					valueInsertPhase = false;
					
					//dispaly colour added for debug purposes
					cout << "Value Inserted: "<< randomColour << endl;
				}
				//=============Display By Current======================


				//Since current at beginning
				//displays first colour as bright 
				//at the beginning
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
				cout << "current: " << current->getData() << endl;
				//=============Display By Current======================

			}


			//Before it reaches 0,
			//Create each colour to be dark
			else if (timer > 0 && timer < 1)
			{
				TodrawDarkBlue = true;
				TodrawDarkRed = true;
				TodrawDarkGreen = true;
				TodrawDarkYellow = true;
			}

			//If timer finally less than 0
			else if (timer < 0)
			{
				//set timer back to 6
				timer = 5;

				//decrement temp difficulty
				TempTotaldifficulty--;

				//Check if the incremented value less than usedElements
				if (increment < SimonTree->returnElementsUsed())
				{
					/*if (reset)
					{
						increment = increment + 1;
						reset = false;
					}*/
						
					//make current the value at increment
					current = SimonTree->getAt(increment);

					//increment value to go down the array list
					increment = increment + 1;
					
				}

				
				else if (TempTotaldifficulty <= 0)
				{
					//decrement difficulty since variable difficulty equals to temp difficulty
					difficulty--;
					//set the current node to root node in Tree
					current = SimonTree->ReturnRoot();
					cout << "-----------CORRECT!!--------" << endl;
					cout << "GREAT!" << endl;
					cout << "-------------CORRECT!!-----------" << endl;
					increment = 0;
				}
				//else if (current->getRight() != nullptr)
				//{
					//current = current->getRight();
				//}
			}
			//=================Display Sequence Again===========================
		}

		//only triggered the first time
		//Inputs three values to be displayed 
		else
		{
			//Beginning Of Game

			//Write Text Game Phase
			TodrawGamePhase = true;

			//if the timer greater or equal to 1
			if (timer >= 1)
			{
				//So it will display colours
				//Set to true each time by difficulty
				//which is set to 3
				if (insert == true)
				{
					//finds random colour
					randomColour = colours[rand() % 4];
					
					//makes current Node equal to root of Tree
					current = SimonTree->ReturnRoot();
					
					//add a node with that random generated colour to Tree's end
					SimonTree->add(randomColour);
					
					//make sure this doesn't get hit immediately after
					insert = false;
				}

				//While timer running check if it is Red,Blue,Green,Yellow
				//The one selected won't be dark
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

			//while the timer is greater or less than 1
			//make each of them dark, as an interval betweeen switching
			else if (timer > 0 && timer < 1)
			{
				TodrawDarkRed = true;
				TodrawDarkBlue = true;
				TodrawDarkGreen = true;
				TodrawDarkYellow = true;
			}

			//if timer finally reaches 0 or is less than 0
			//decrement difficulty to start the phase again
			//but with a different colour
			else if (timer <= 0)
			{
				//After displayed

				//decrement difficulty
				difficulty--;

				//Make add 'another value' check to true
				insert = true;

				//set timer back to 5
				timer = 5;
			}
		}
	}
	else
	{
		//if the difficulty has reached 0
		//meaning 3 colours have been added and displayed
		//make everything dark again and make input phase equal to true
		TodrawDarkRed = true;
		TodrawDarkBlue = true;
		TodrawDarkGreen = true;
		TodrawDarkYellow = true;
		inputPhase = true;
	}

	//Now that all colours have been displayed
	//The input phase begins
	if(inputPhase)
	{
		/*if (reset)
		{
			increment = 0;
			reset = false;
		}*/

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
		//set it to false, so it doesn't immediately call it again
		inputDone = false;

		//if (increment < SimonTree->returnElementsUsed()-1)
		//{
			for (int i = 0; i < SimonTree->returnElementsUsed(); i++) {
				cout << "Value Stored: " << SimonTree->getAt(i)->getData() << endl;
			}

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
					//if the elements have all been checked 
					
					//increment diffculty, making it 4
					difficulty++;

					//increment Total difficulty which always equals to 3
					Total_difficulty++;

					//make the temperoryDifficulty equal to total
					TempTotaldifficulty = Total_difficulty;
					
					//timer will be resetted
					timer = 5;
					
					//Now the second Phase of the Game will start
					//By checking true
					SequenceFinished = true;
					
					//set the second phases' insert colour to true
					valueInsertPhase = true;
					
					//bring increment back to zero
					//increment back at zero to draw colours from beginning
					increment = 1;
					reset = true;
				}
			}

			//If data not match
			else if (SimonTree->getAt(increment)->getData() != Data->getData())
			{
				cout << "Incorrect" << endl;

				//---Set Values Back In-------
				//reset values
				Total_difficulty = 3;
				//reset values
				difficulty = 3;
				//reset values
				timer = 5;
				//reset values, don't start next phase
				SequenceFinished = false;
				//reset values, start first phase, which inserts three values
				insert = true;
				//---Set Values Back In-------

				//set value to 0 again
				increment = 0;

				//call Shutdown deleting objects
				shutdown();

				//instantiate needed variables again
				startup();

				//Display Restarting for Debug sakes
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
		//Rules for player to abide by
		m_2dRenderer->drawText(g_systemFont, "GAME PHASE", 500, 300);
	}
	else
	{
		//Rules for player to abide by
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


