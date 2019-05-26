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

	string randomColour;

	


	//Square colours[4] = { *Red, *Blue, *Green, *Yellow};
};