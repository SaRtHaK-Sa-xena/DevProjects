#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Square.h"
//#include "SimonGameClass.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Dynamic Array.h"


class SIMON___GAMEApp : public aie::Application {
public:

	SIMON___GAMEApp();
	virtual ~SIMON___GAMEApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

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

	aie::Texture* m_redBackGround;
	//=============Textures==============


	//SimonGameClass* SimonTree;
	DynamicArray* SimonTree = new DynamicArray();

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
	bool TodrawInputPhase = false;
	bool gamePaused = false;
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
	

	//Incrementer
	int increment = 0;
	bool reset = true;
};