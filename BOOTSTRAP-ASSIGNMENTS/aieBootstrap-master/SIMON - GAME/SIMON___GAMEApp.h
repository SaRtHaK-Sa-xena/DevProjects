#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Square.h"
#include "SimonGameClass.h"


class SIMON___GAMEApp : public aie::Application {
public:

	SIMON___GAMEApp();
	virtual ~SIMON___GAMEApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	//virtual void CheckWon(SimonGameClass* firstList, SimonGameClass* secondList);

	virtual void DisplayColours_sequence(string randomColour, float deltaTime)
	{
		//Sequence Start Void Function
		SimonTree->insert(randomColour);//Insert Node, which Holds a random String betweeen Red,Blue,Green and Yellow
		if (randomColour == "RED")
		{
			Red->SetValue(-1);
			secondTimer = secondTimer - deltaTime;
			bool complete = false;
			while (complete == false) 
			{
				if (secondTimer < 0)
				{
					complete = true;
				}
			}
			
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

	virtual void Insert_Display(string randomColour)
	{
		SimonTree->insert(randomColour);
	}

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;


	SimonGameClass* SimonTree;
	SimonGameClass* InputTree;

	Square*				Red;
	Square*				Blue;
	Square*				Green;
	Square*				Yellow;


	float Total_timer = 5;
	float timer;
	float secondTimer = 5;
	float gameTimer;
	float Game_total_timer = 10;
	int clockSpeed = 1;
	bool EndTime;



	


	//Square colours[4] = { *Red, *Blue, *Green, *Yellow};
};