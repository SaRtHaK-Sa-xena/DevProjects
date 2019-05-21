#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Bar.h"
#include "Node.h"
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

	virtual bool CheckWon(Array *firstList, Array *secondList);


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

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	Array	        *SimonTree;
	Array	        *InputTree;

	//Node		    *m_selectedNode = nullptr;

	Bar *Red;
	Bar *Blue;
	Bar *Green;
	Bar *Yellow;

	Bar *selectedColour = nullptr;



	float Total_timer = 5;
	float timer;
	float Game_total_timer = 10;

	bool Todraw = false;
};