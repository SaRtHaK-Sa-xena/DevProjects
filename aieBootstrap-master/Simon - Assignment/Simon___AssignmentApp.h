#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Bar.h"
#include "Array.h"
#include <imgui.h>
#include "Texture.h"
#include "Font.h"
#include "Input.h"

class Simon___AssignmentApp : public aie::Application {
public:

	Simon___AssignmentApp();
	virtual ~Simon___AssignmentApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	//virtual bool CheckWon(Array *firstList, Array *secondList);


	virtual void InputPhase();

	virtual void DisplayColours_sequence(string randomColour)
	{
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
	}

	virtual void StartRound(float deltaTime)
	{
		for (difficulty; difficulty != 0; difficulty--)
		{
			//timer = timer - deltaTime;
			cout << "Timer: " << timer << endl;
			if (timer > 0)
			{
				randomColour = colours[rand() % 4];
				SimonTree->insert(randomColour);
				insert = false;
			}

			if (randomColour == "RED")
			{
				TodrawDarkRed = false;
				draw();
			}
			else if (randomColour == "BLUE")
			{
				TodrawDarkBlue = false;
				draw();
			}
			else if (randomColour == "GREEN")
			{
				TodrawDarkGreen = false;
			}
			else if (randomColour == "YELLOW")
			{
				TodrawDarkYellow = false;
			}

			if (timer > 0 && timer < 1)
			{
				TodrawDarkRed = true;
				TodrawDarkRed = true;
				TodrawDarkGreen = true;
				TodrawDarkYellow = true;
			}

			else if (timer <= 0)
			{
				insert = true;
				timer = 5;
			}
		}
	}


protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

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


	Array	        *SimonTree;
	Array	        *InputTree;

	//Node		    *m_selectedNode = nullptr;

	Bar *Red;
	Bar *Blue;
	Bar *Green;
	Bar *Yellow;

	Bar *selectedColour = nullptr;
	Bar *current = nullptr;

	bool insert = true;
	bool inputPhase = false;

	float Total_timer = 5;
	float timer = Total_timer;
	float Game_total_timer = 10;

	bool TodrawDarkRed = true;
	bool TodrawDarkBlue = true;
	bool TodrawDarkGreen = true;
	bool TodrawDarkYellow = true;


	string red = "RED";
	string blue = "BLUE";
	string green = "GREEN";
	string yellow = "YELLOW";
	string colours[4] = { red,blue,green,yellow }; //from red,blue,green yellow
	string randomColour;

	int Total_difficulty = 3;
	int difficulty = Total_difficulty;
	bool checkedTrue = true;

};