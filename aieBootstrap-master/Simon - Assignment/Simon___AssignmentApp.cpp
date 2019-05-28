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
			if (timer >= 1)
			{
				if (valueInsertPhase == true)
				{
					randomColour = colours[rand() % 4];
					current = SimonTree->ReturnRoot();
					SimonTree->insert(randomColour);
					valueInsertPhase = false;
					cout << "Value Inserted" << endl;
				}

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
				if (TempTotaldifficulty < 0)
				{
					difficulty--;
					current = SimonTree->ReturnRoot();
				}
				else if (current->getRight() != nullptr)
				{
					current = current->getRight();
				}
			}
		}
		//if (SequenceFinished)
		//{
		//	//if(timer > 0)
		//	//{
		//	//	current = simonTree->ReturnRoot();
		//	//	if(timer > 1)
		//	//{
		//	//	if(current->getData() == "RED")
		//	//{
		//	//}
		//	if (timer <= 5)
		//	{
		//		if (SetCurrentToRoot)
		//		{
		//			current = SimonTree->ReturnRoot();//set current to beginning
		//			SetCurrentToRoot = false;
		//		}


		//		if (current->getData() == "RED")
		//		{
		//			TodrawDarkRed = false;
		//		}
		//		else if (current->getData() == "BLUE")
		//		{
		//			TodrawDarkBlue = false;
		//		}
		//		else if (current->getData() == "GREEN")
		//		{
		//			TodrawDarkGreen = false;
		//		}
		//		else if (current->getData() == "YELLOW")
		//		{
		//			TodrawDarkYellow = false;
		//		}
		//		if (current->getRight() != nullptr)
		//		{
		//			current = current->getRight();
		//		}
		//	}

		//	else if (timer > 1 && timer < 3)
		//	{
		//		if (valueInsertPhase)
		//		{
		//			randomColour = colours[rand() % 4];
		//			SimonTree->insert(randomColour);
		//			valueInsertPhase = false;
		//		}

		//		if (randomColour == "RED")
		//		{
		//			TodrawDarkRed = false;

		//		}
		//		else if (randomColour == "BLUE")
		//		{
		//			TodrawDarkBlue = false;
		//		}
		//		else if (randomColour == "GREEN")
		//		{
		//			TodrawDarkGreen = false;
		//		}
		//		else if (randomColour == "YELLOW")
		//		{
		//			TodrawDarkYellow = false;
		//		}
		//	}
		//	else if (timer > 0 && timer < 1)
		//	{
		//		TodrawDarkRed = true;
		//		TodrawDarkRed = true;
		//		TodrawDarkGreen = true;
		//		TodrawDarkYellow = true;
		//	}
		//	else if (timer <= 0)
		//	{
		//		difficulty--;
		//	}
		//}
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
				TodrawDarkRed = true;
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
				TempTotaldifficulty++;
				timer = 5;
				SequenceFinished = true;
				//increment difficulty
				//
			}
		}

		else if (current->getData() != Data->getData())
		{
			cout << "Incorrect" << endl;
			m_gameOver = true;
		}
		
		/*else if (current->getRight() != nullptr)
		{
			current = current->getRight();
		}*/
		
	}

	//while (inputDone == false)
		//while(valueInsertPhase)
		//{
		//	cout << "In While Loop" << endl;

		//	if (input->wasKeyPressed(aie::INPUT_KEY_W))
		//	{
		//		TodrawDarkBlue = false;
		//		Data->setData("BLUE");
		//		cout << "Set Colour To Blue" << endl;
		//		inputDone = true;

		//	}
		//	else if (input->wasKeyPressed(aie::INPUT_KEY_A))
		//	{
		//		TodrawDarkGreen = false;
		//		Data->setData("GREEN");
		//		cout << "Set Colour To Green" << endl;
		//		inputDone = true;

		//	}
		//	else if (input->wasKeyPressed(aie::INPUT_KEY_S))
		//	{
		//		TodrawDarkRed = false;
		//		Data->setData("RED");
		//		cout << "Set Colour To Red" << endl;
		//		inputDone = true;

		//	}
		//	else if (input->wasKeyPressed(aie::INPUT_KEY_D))
		//	{
		//		TodrawDarkYellow = false;
		//		Data->setData("YELLOW");
		//		cout << "Set Colour To Yellow" << endl;
		//		inputDone = true;

		//	}
		//	//draw(); //Draw everything
		//	if (inputDone) //put breakpoint here
		//	{
		//		if (current->getData() == Data->getData())
		//		{
		//			valueInsertPhase = true;
		//			cout << "Correct Data Entered, And Set inputPhase to True" << endl;
		//			if (current->getRight() == nullptr)
		//			{
		//				cout << "Right Of Current == nullptr" << endl;
		//				difficulty++;
		//			}
		//			else
		//			{
		//				current = current->getRight();
		//				cout << "Moved Current To The Right" << endl;

		//			}
		//		}
		//		else if (current->getData() != Data->getData())
		//		{
		//			cout << "Data Was Not Equal To Sequential data" << endl;
		//			valueInsertPhase = false;
		//			cout << "InputPhase Set To False" << endl;
		//		}
		//	}
		//	else
		//	{
		//		cout << "Nothing Inputted" << endl;
		//		valueInsertPhase = true;
		//		cout << "Setting InputPhase to FALSE" << endl;
		//	}
		//}
	//}

	//==================================CAPPING FOR NOW============================

	//if (inputPhase)//(inputPhase == true && checkedTrue == true)
	//{

	//	Game_total_timer -= deltaTime * 2;// Decrement
	//	cout << "Game___Timer: " << Game_total_timer << endl;
	//	if (Game_total_timer > 0)// True
	//	{
	//		//========================INPUT PHASE==================================================

	//		if (input->wasKeyPressed(aie::INPUT_KEY_W))// Input True
	//		{
	//			TodrawDarkBlue = false; //False (BRIGHT BLUE)
	//			Data->setData("BLUE"); // BLUE NOW IN DATA
	//			//inputPhase = false; // InputPhase = false
	//			inputDone = true;
	//			//Game_total_timer = -1; // gameTimer = -1;
	//		}
	//		else if (input->wasKeyPressed(aie::INPUT_KEY_A))
	//		{
	//			TodrawDarkGreen = false;
	//			Data->setData("GREEN");
	//			//inputPhase = false;
	//			inputDone = true;
	//			//Game_total_timer = -1;
	//		}
	//		else if (input->wasKeyPressed(aie::INPUT_KEY_S))
	//		{
	//			TodrawDarkRed = false;
	//			Data->setData("RED");
	//			//inputPhase = false;
	//			inputDone = true;
	//			//Game_total_timer = -1;
	//		}
	//		else if (input->wasKeyPressed(aie::INPUT_KEY_D))
	//		{
	//			TodrawDarkYellow = false;
	//			Data->setData("YELLOW");
	//			//inputPhase = false;
	//			inputDone = true;
	//			//Game_total_timer = -1;
	//		}
	//		else if (input->wasKeyPressed(aie::INPUT_KEY_ESCAPE))
	//		{
	//			quit();
	//		}

	//		//========================INPUT PHASE==================================================
	//		//Input(input);


	//		if (inputDone == true)
	//		{
	//			if (inputPhase)
	//			{
	//				if (current->getData() == Data->getData())
	//				{
	//					current = current->getRight();
	//					cout << "-------------CORRECT-----------" << endl;
	//					cout << "-------------CORRECT-----------" << endl;
	//					inputPhase = true;
	//				}
	//				else if(current->getData() != Data->getData())
	//				{
	//					inputPhase = false;
	//					cout << "You lost" << endl;
	//					m_gameOver = true;
	//				}
	//			}
	//		}
	//		//inputPhase = false;
	//	}
	//	else
	//	{
	//		//Check if Correct
	//		
	//	}
	//	//------Not Yet---------
	//	//SimonTree->CheckIfLost(Data, current, checkedTrue);
	//	//------Not Yet---------


	//	/*current = current->getRight();
	//	if (current->getData() == Data->getData())
	//	{
	//		checkedTrue = true;
	//	}
	//	else
	//	{
	//		checkedTrue = false;
	//	}*/
	//	//bool checkedTrue = false;
	//	//if(checkedTrue == false)
	//	//{
	//	// if(randomColour == "RED")

	//	
	//	//current = nullptr;
	//	//iterator = m_pRoot;
	//	//if (current->getdata == iterator)
	//	//{
	//	//	iterator = iteartor->getRight();
	//	//}
	//	////and then continue or not
	//	//current->setData(SimonTree[0]);
	//}

	//==================================CAPPING FOR NOW============================

	//========================WORKS================================

	//=================================BLINKING WORKS PERFECTLY====================================
	//if (timer > 0)
	//{
	//	if (insert == true)
	//	{
	//		randomColour = colours[rand() % 4]; //random and output = red,blue,green or yellow
	//		SimonTree->insert(randomColour);
	//		insert = false;
	//	}
	//	
	//	if (randomColour == "RED")
	//	{
	//		TodrawDarkRed = false;
	//		draw();
	//		//m_2dRenderer->drawSprite(m_BrightRedTexture, Red->m_posX, Red->m_posY, Red->m_width, Red->m_height);
	//	}
	//	else if (randomColour == "BLUE")
	//	{
	//		TodrawDarkBlue = false;
	//		draw();

	//	}
	//	else if (randomColour == "GREEN")
	//	{
	//		TodrawDarkGreen = false;
	//		draw();

	//		//Green->SetValue(-1);
	//	}
	//	else if (randomColour == "YELLOW")
	//	{
	//		TodrawDarkYellow = false;
	//		draw();

	//		//Yellow->SetValue(-1);
	//	}
	//}


	//if (timer > 0 && timer < 1)
	//{
	//	TodrawDarkBlue = true;
	//	TodrawDarkRed = true;
	//	TodrawDarkGreen = true;
	//	TodrawDarkYellow = true;
	//}

	//else if (timer <= 0)
	//{
	//	insert = true;
	//	timer = 5;
	//}
	//=================================BLINKING WORKS PERFECTLY====================================

	//==================================WORKS===================

	//do
	//{

	//	if (insert == true)
	//	{
	//		SimonTree->insert(randomColour);
	//		insert = false;
	//	}

	//	
	//	
	//	break;
	//} while (timer > 0);

	



	

	//if (timer > 0)
	//{
	//	if(insert == true)
	//	SimonTree->insert(randomColour);
	//	if (randomColour == "RED")
	//	{
	//		TodrawDarkRed = false;
	//		draw();
	//		//m_2dRenderer->drawSprite(m_BrightRedTexture, Red->m_posX, Red->m_posY, Red->m_width, Red->m_height);
	//	}
	//	else if (randomColour == "BLUE")
	//	{
	//		TodrawDarkBlue = false;
	//		draw();

	//	}
	//	else if (randomColour == "GREEN")
	//	{
	//		TodrawDarkGreen = false;
	//		draw();

	//		//Green->SetValue(-1);
	//	}
	//	else if (randomColour == "YELLOW")
	//	{
	//		TodrawDarkYellow = false;
	//		draw();

	//		//Yellow->SetValue(-1);
	//	}

	//	if (timer < 0)
	//	{
	//		//Red->setValue(100);
	//		TodrawDarkRed = true;
	//		TodrawDarkBlue = true;
	//		TodrawDarkGreen = true;
	//		TodrawDarkYellow = true;
	//	}

	//	
	//}
	//
	//if(timer < 0)
	
	

	//=======================START SEQUENCE=========================
	//if (m_gameOver == false)
	//{
	//	//It will distribute Sequence
	//	while(startGame == true)
	//	{
	//		timer = Total_timer;
	//		timer = timer - deltaTime;

	//		while (timer > 0)
	//		{
	//			//===========Seems to be working==============
	//			DisplayColours_sequence(randomColour);//sequence Function
	//			//=============Blinks Good!===============
	//		}
	//		startGame = false;
	//	}
	//	//end distribution

	//	float gameTimer = Game_total_timer;
	//	gameTimer = gameTimer - deltaTime;
	//	while (gameTimer > 0)
	//	{
	//		Total_moves = moves;
	//		while (moves != 0)
	//		{
	//			//=========================INPUT PHASE==========================
	//			if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	//				quit();
	//			else if (input->isKeyDown(aie::INPUT_KEY_W))
	//			{
	//				Blue->SetValue(-1);
	//				moves--;
	//				InputTree->insert(blue);
	//			}
	//			else if (input->isKeyDown(aie::INPUT_KEY_S))
	//			{
	//				Red->SetValue(-1);
	//				moves--;
	//				InputTree->insert(red);

	//			}
	//			else if (input->isKeyDown(aie::INPUT_KEY_A))
	//			{
	//				Green->SetValue(-1);
	//				moves--;
	//				InputTree->insert(green);




	//			}
	//			else if (input->isKeyDown(aie::INPUT_KEY_D))
	//			{
	//				Yellow->SetValue(-1);
	//				moves--;
	//				InputTree->insert(yellow);

	//			}
	//			//=========================INPUT PHASE==========================
	//			//
	//			//Each input places, inserts in a different Tree of that specified colour
	//			//after each move moves--;
	//		}
	//		break;
	//	
	//	}
	//	if (CheckWon() == true)
	//	{
	//		Total_timer++;
	//		Total_moves++;
	//		//Call Start Game Again, increment moves, and time
	//	}
	//	else
	//	{
	//		m_gameOver == true;
	//	}

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
	/*}
	else
	{
		cout << "You Lost" << endl;
	}*/

	//=======================START SEQUENCE=========================




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

