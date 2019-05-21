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
	SimonTree = new Array();
	InputTree = new Array();
	/*Bar* m_bar;*/
	string red = "red";
	string blue = "blue";
	string green = "green";
	string yellow = "yellow";
	Red = new Bar(600, 150, 200, 210, red); //bottom Square
	Blue= new Bar(600, 600, 200, 210, blue); //top square
	Green = new Bar(350, 350, 200, 210, green); //left square 
	Yellow = new Bar(850, 350, 200, 210, yellow); //right square
	
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

	delete m_font;
	delete m_2dRenderer;
	delete Red;
	delete Blue;
	delete Green;
	delete Yellow;
	delete SimonTree;
}

void Simon___AssignmentApp::update(float deltaTime) {
	
	// ==================input example===============
	aie::Input* input = aie::Input::getInstance();
	// ===============exit the application===========

	//Default Start
	//==============Intitializing==================================
	 string red = "RED";
	 string blue = "BLUE";
	 string green = "GREEN";
	 string yellow = "YELLOW";
	 string colours[4] = { red,blue,green,yellow }; //from red,blue,green yellow
	string randomColour = colours[rand() % 4]; //random and output = red,blue,green or yellow
	static int difficulty = 0;
	static int moves;
	static int Total_moves = 2;
	bool startGame = false;
	//==============Intitializing==================================

	
	//Default Colour
	//==============INITIALIZE COLOURS RESTING TEXTURE==============
	Red->SetValue(100);
	Blue->SetValue(100);
	Green->SetValue(100);
	Yellow->SetValue(100);
	//==============INITIALIZE COLOURS RESTING TEXTURE==============

	//=======================START SEQUENCE=========================
	if (m_gameOver == false)
	{
		//It will distribute Sequence
		while(startGame == true)
		{
			timer = Total_timer;
			timer = timer - deltaTime;

			while (timer > 0)
			{
				//===========Seems to be working==============
				DisplayColours_sequence(randomColour);//sequence Function
				//=============Blinks Good!===============
			}
			startGame = false;
		}
		//end distribution

		float gameTimer = Game_total_timer;
		gameTimer = gameTimer - deltaTime;
		while (gameTimer > 0)
		{
			Total_moves = moves;
			while (moves != 0)
			{
				//=========================INPUT PHASE==========================
				if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
					quit();
				else if (input->isKeyDown(aie::INPUT_KEY_W))
				{
					Blue->SetValue(-1);
					moves--;
					InputTree->insert(blue);
				}
				else if (input->isKeyDown(aie::INPUT_KEY_S))
				{
					Red->SetValue(-1);
					moves--;
					InputTree->insert(red);

				}
				else if (input->isKeyDown(aie::INPUT_KEY_A))
				{
					Green->SetValue(-1);
					moves--;
					InputTree->insert(green);

				}
				else if (input->isKeyDown(aie::INPUT_KEY_D))
				{
					Yellow->SetValue(-1);
					moves--;
					InputTree->insert(yellow);

				}
				//=========================INPUT PHASE==========================
				//
				//Each input places, inserts in a different Tree of that specified colour
				//after each move moves--;
			}
			break;
		
		}
		if (CheckWon() == true)
		{
			Total_timer++;
			Total_moves++;
			//Call Start Game Again, increment moves, and time
		}
		else
		{
			m_gameOver == true;
		}
			

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
	}
	else
	{
		cout << "You Lost" << endl;
	}

	//=======================START SEQUENCE=========================




}

void Simon___AssignmentApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!

	//==========DEFAULT COLOURS===============
	Red->Draw(m_2dRenderer, 1,0,0);
	Blue->Draw(m_2dRenderer,0,0,1);
	Green->Draw(m_2dRenderer,0,1,0);
	Yellow->Draw(m_2dRenderer,0.80,1,0);
	//==========DEFAULT COLOURS===============

	//if (Todraw == true)
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

bool Simon___AssignmentApp::CheckWon(Array *firstList, Array *secondList)
{
	Bar *current = nullptr;
	Bar *parent = nullptr;

	current = R
	//if Won
	return true;

	//else Lost
	//return false;
}
