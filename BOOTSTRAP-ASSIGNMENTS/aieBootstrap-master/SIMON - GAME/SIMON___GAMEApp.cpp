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

	SimonTree = new SimonGameClass();
	InputTree = new SimonGameClass();

	string red = "red";
	string blue = "blue";
	string green = "green";
	string yellow = "yellow";

	EndTime = false;

	Red = new Square(600, 150, 200, 210, red); //bottom Square
	Blue = new Square(600, 600, 200, 210, blue);//top square
	Green = new Square(350, 350, 200, 210, green); //left square 
	Yellow = new Square(850, 350, 200, 210, yellow); //right square
	
	
	
	timer = Total_timer; //timer will equal Total Time = 5;
	gameTimer = Game_total_timer;

	//SimonTree->insert(randomColour); //insert colour

	//Red->SetColourValue(0.80, m_2dRenderer);
	//pressed = false;
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
	delete SimonTree;
}
//Square colours[4];

//void SIMON___GAMEApp::GamePhase()
//{
//	int Difficulty = 0;
//	if (Difficulty == 0)
//	{
//		colours[0].SetValue(20);
//		//void Press()
//		//{
//			//will press multiple
//		//}
//	}
//}


void SIMON___GAMEApp::update(float deltaTime) {

	// ======================input example===============
	aie::Input* input = aie::Input::getInstance();
	// exit the application===================


	


	//Default Start
	//==============Intitializing==================================
	
	//static int difficulty = 0;
	//static int moves;
	//static int Total_moves = 2;
	//bool startGame = true;
	//==============Intitializing==================================

	timer = timer - deltaTime; // timer will decrement


	//Default Colour
	//==============INITIALIZE COLOURS RESTING TEXTURE==============
		//Red->SetValue(100);
		//Green->SetValue(100);
		//Yellow->SetValue(100);
		//Blue->SetValue(100);
	//==============INITIALIZE COLOURS RESTING TEXTURE==============


	//if (EndTime == false)
	//{
	//	SimonTree->insert(randomColour);
	//	EndTime = true;
	//}

	if (input->isKeyDown(aie::INPUT_KEY_W)) //key 'pressed' hold calls
	{
		//==============Get Random Colour===============================
		string red = "RED";
		string blue = "BLUE";
		string green = "GREEN";
		string yellow = "YELLOW";
		string colourArray[4] = { red, blue, green, yellow };//into array
		string randomColour = colourArray[rand() % 4];// random from array
		//==============Get Random Colour==============================

		SimonTree->insert(randomColour);
		if (randomColour == "RED")
		{
			Red->SetValue(-1);
		}
		else if (randomColour == "BLUE")
		{
			Blue->SetValue(-1);
		}
		else if (randomColour == "GREEN")
		{
			Green->SetValue(-1);
		}
		else if (randomColour == "YELLOW")
		{
			Yellow->SetValue(-1);
		}
	}

	if (timer < 0)
	{
		Red->SetValue(100);
		Blue->SetValue(100);
		Green->SetValue(100);
		Yellow->SetValue(100);
		//timer = 5;
	}

	
		//=======================START SEQUENCE=========================
	//if (m_gameOver == false)
	//{
		//It will distribute Sequence
		//while (startGame == true)
		//{
			//timer = timer - deltaTime;
			//if (timer > 4.95) //&& timer < 5.00) // while timer greater than 0 == [true]->
			//{
				//===========Seems to be working==============
				//DisplayColours_sequence(randomColour);//sequence Function (inputs into SimonTree) , then pause, then continue
		
			//start -> setColour -> timer will equal 4 -> calls draw function -> repeats

			//if(col = red -> setvalue-1 -> 
			//if (timer < 5 && timer > 4)
			//{
			//	//===================Conditions====================
			//	if (randomColour == "RED")
			//	{
			//		Red->SetValue(-1);
			//		//update(deltaTime);

			//	}
			//	else if (randomColour == "BLUE")
			//	{
			//		Blue->SetValue(-1);
			//		//update(deltaTime);

			//		/*secondTimer = secondTimer - deltaTime;
			//		bool complete = false;
			//		while (complete == false)
			//		{
			//			if (secondTimer < 0)
			//			{
			//				complete = true;
			//				update(deltaTime);
			//			}
			//			else
			//			{
			//				complete = false;
			//				update(deltaTime);
			//			}
			//		}*/
			//	}
			//	else if (randomColour == "GREEN")
			//	{
			//		Green->SetValue(-1);
			//		//update(deltaTime);

			//		/*secondTimer = secondTimer - deltaTime;
			//		bool complete = false;
			//		while (complete == false)
			//		{
			//			if (secondTimer < 0)
			//			{
			//				complete = true;
			//				update(deltaTime);
			//			}
			//			else
			//			{
			//				complete = false;
			//				update(deltaTime);
			//			}
			//		}*/
			//	}
			//	else if (randomColour == "YELLOW")
			//	{
			//		Yellow->SetValue(-1);
			//		//update(deltaTime);
			//		/*	secondTimer = secondTimer - deltaTime;
			//			bool complete = false;
			//			while (complete == false)
			//			{
			//				if (secondTimer < 0)
			//				{
			//					complete = true;
			//					update(deltaTime);
			//				}
			//				else
			//				{
			//					complete = false;
			//					update(deltaTime);
			//				}
			//			}*/
			//	}
			//	//===================Conditions====================
			//}
			//
			//else if(timer < 2)
			//{
			//	Red->SetValue(100);
			//	Blue->SetValue(100);
			//	Green->SetValue(100);
			//	Yellow->SetValue(100);
			//	//Insert_Display(randomColour);
			//	//timer = 10;
			//	//draw();

			//}
			//else
			//{
			//	cout << "End of IF" << endl;
			//}
			
					//Wait For 1 second then call Draw
					/*if (randomColour == "RED")
					{

					}*/



				//=======================FIRST ATTEMPT==================================									  
				//EndTime = true;
				//if (EndTime == true)
				//{
					//timer = 0;
				//}
				//Red->SetValue(-1);
				//draw();
													  //Drawing
				//=============Blinks Good!===============
				//=======================FIRST ATTEMPT==================================									  


			//}
			//else
			//{
				//startGame = false;
			//}
		//}
		//draw();
		//end distribution


		//gameTimer = gameTimer - clockSpeed;
		//while (gameTimer > 0)
		//{


		//=========================================Stopping For Now=========================== (is Input Function)

		////=====================Stacking For Debug===========================================
		//	//moves = Total_moves;
		//	//while (moves != 0)
		//	//{
		//		//=========================INPUT PHASE==========================
		//	/*if (timer < 2 && timer > 1)
		//	{
		//		if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		//			quit();
		//		else if (input->isKeyDown(aie::INPUT_KEY_W))
		//		{
		//			Blue->SetValue(-1);
		//			moves--;
		//			InputTree->insert(blue);
		//		}
		//		else if (input->isKeyDown(aie::INPUT_KEY_S))
		//		{
		//			Red->SetValue(-1);
		//			moves--;
		//			InputTree->insert(red);

		//		}
		//		else if (input->isKeyDown(aie::INPUT_KEY_A))
		//		{
		//			Green->SetValue(-1);
		//			moves--;
		//			InputTree->insert(green);

		//		}
		//		else if (input->isKeyDown(aie::INPUT_KEY_D))
		//		{
		//			Yellow->SetValue(-1);
		//			moves--;
		//			InputTree->insert(yellow);

		//		}
		//	}*/
		//		//=========================INPUT PHASE==========================
		//		//
		//		//Each input places, inserts in a different Tree of that specified colour
		//		//after each move moves--;
		//	//}
		//
		//	//break;
		////=====================Stacking For Debug===========================================

		//=========================================Stopping For Now===========================






		//}
		//if (CheckWon() == true)
		//{
		//	Total_timer++;
		//	Total_moves++;
		//	//Call Start Game Again, increment moves, and time
		//}
		//else
		//{
		//	m_gameOver == true;
		//}


			//set start game to equal false;

			//start game_decision timer
			//GameTotalTimer = 5;
			//gameTimre = GameTotalTimer;
			//gameTimer = gameTimer - deltaTime;
			//while(gameTimer > 0)
			//Call Movement Function
			//if(gameTimer < 0)
			//CheckIfWon() <-- If false
			//return to mainMenu <---For now cout << you Lost < endl;
			//if CheckIfWon == true
			//Total_timer++;







		//Total_Timer = 5; == to number colours to display 1-4
		//timer = Total_Timer; 
		//while counting down from 5 -> display Colours;
		//Total_Timer++;

		//Input Phase Function




		//complete CheckWon Function
		//if (CheckWon() == true) //CheckWon compares Values with SimonTree->insert() and tree->insert() and returns true if entire list matches and false if not
		//{
			//Total_moves++;//since player advanced, moves will increment
			//Start Void Function -- Calls Start Again, to Keep Incrementing
		//}
	//}
	//else
	//{
		//cout << "You Lost" << endl;
	//}

	//=======================START SEQUENCE=========================



	//if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	//	quit();
	//else if (input->isKeyDown(aie::INPUT_KEY_S))
	//{
	//	Red->SetValue(-1);
	//	//Red->SetColourValue(0.80, m_2dRenderer);
	//}
	//else if (input->isKeyDown(aie::INPUT_KEY_W))
	//{
	//	//delete Red;
	//	//Red = new Square(600, 150, 200, 210);//bottom Square
	//	Blue->SetValue(-1);
	//}
	//else if (input->isKeyDown(aie::INPUT_KEY_A))
	//{
	//	Yellow->SetValue(-1);
	//}
	//else if (input->isKeyDown(aie::INPUT_KEY_D))
	//{
	//	Green->SetValue(-1);
	//}

}

void SIMON___GAMEApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!


	//Red->Draw(m_2dRenderer);
	//Red->SetColourValue(1, 0, 0, m_2dRenderer);
	//Blue->Draw(m_2dRenderer);
	//Blue->SetColourValue(0, 0, 1, m_2dRenderer);
	//Green->Draw(m_2dRenderer);
	//Green->SetColourValue(0, 1, 0, m_2dRenderer);
	//Yellow->Draw(m_2dRenderer);
	//Yellow->SetColourValue(0.80, 1, 0, m_2dRenderer);

	//==========DEFAULT COLOURS===============
	Red->Draw(m_2dRenderer, 1, 0, 0);
	Blue->Draw(m_2dRenderer, 0, 0, 1);
	Green->Draw(m_2dRenderer, 0, 1, 0);
	Yellow->Draw(m_2dRenderer, 0.80, 1, 0);
	//==========DEFAULT COLOURS===============


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