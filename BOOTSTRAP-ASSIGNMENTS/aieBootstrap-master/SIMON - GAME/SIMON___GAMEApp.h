#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Square.h"
#include "SimonGameClass.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"


class SIMON___GAMEApp : public aie::Application {
public:

	SIMON___GAMEApp();
	virtual ~SIMON___GAMEApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();


	//virtual void CheckWon(SimonGameClass* firstList, SimonGameClass* secondList);

	void DisplayColours_sequence()
	{
		//==============Get Random Colour===============================
		string red = "RED";
		string blue = "BLUE";
		string green = "GREEN";
		string yellow = "YELLOW";
		string colourArray[4] = { red, blue, green, yellow };//into array
		randomColour = colourArray[rand() % 4];// random from array
		//==============Get Random Colour==============================
		//Sequence Start Void Function
		SimonTree->insert(randomColour);//Insert Node, which Holds a random String betweeen Red,Blue,Green and Yellow
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

		}						//Sequence Start Void Function
		else
		{
			cout << "Not Set" << endl;
		}
	}

	virtual void Insert_Display(string randomColour)
	{
		SimonTree->insert(randomColour);
	}

protected:


	aie::Renderer2D* m_2dRenderer;
	aie::Font* m_font;

	//=============Textures==============
	aie::Texture* m_BrightRedTexture;
	aie::Texture* m_DarkRedTexture;

	aie::Texture* m_BrightBlueTexture;
	aie::Texture* m_DarkBlueTexture;

	aie::Texture* m_BrightYellowTexture;
	aie::Texture* m_DarkYellowTexture;

	aie::Texture* m_BrightGreenTexture;
	aie::Texture* m_DarkGreenTexture;
	//=============Textures==============


	SimonGameClass* SimonTree;

	//Node		    *m_selectedNode = nullptr;

	//====Colours=======
	Square* Red;
	Square* Blue;
	Square* Green;
	Square* Yellow;
	//====Colours=======


	//=====NODES (IN USE)=======
	Square* current = nullptr;
	Square* Data = nullptr;
	//=====NODES (IN USE)=======


	//=======TIMER===============
	float Total_timer = 5;
	float timer = Total_timer;
	float Game_total_timer = 10;
	//=======TIMER===============


	//=====ToDrawQuery===========
	bool TodrawDarkRed = true;
	bool TodrawDarkBlue = true;
	bool TodrawDarkGreen = true;
	bool TodrawDarkYellow = true;
	bool TodrawGamePhase = true;
	bool TodrawInputPhase;
	//=====ToDrawQuery===========


	//=====STRING OF COLOURS=========================
	string red = "RED";
	string blue = "BLUE";
	string green = "GREEN";
	string yellow = "YELLOW";
	string colours[4] = { red,blue,green,yellow }; //from red,blue,green yellow
	string randomColour;
	//=====STRING OF COLOURS=========================


	//=====Difficulty/Rounds======
	int Total_difficulty = 3;
	int Total_RESETdifficulty = 3;
	int TempTotaldifficulty = Total_difficulty;
	int difficulty = Total_difficulty;
	//=====Difficulty/Rounds======


	//=====InputPhaseChecks=======
	bool checkedTrue = true;
	bool inputDone;
	bool inputPhase;
	bool insert = true;
	bool SequenceFinished;
	bool valueInsertPhase = true;
	bool SetCurrentToRoot = true;
	bool AlreadyDisplayed = false;
	//=====InputPhaseChecks=======
	
};