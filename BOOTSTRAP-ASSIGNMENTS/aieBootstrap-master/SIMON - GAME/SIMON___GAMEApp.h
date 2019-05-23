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

	virtual void CheckWon(SimonGameClass* firstList, SimonGameClass* second List);

	virtual void DisplayColours_sequence(string randomColour);

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
	float Game_total_timer = 10;
	//Square colours[4] = { *Red, *Blue, *Green, *Yellow};
};