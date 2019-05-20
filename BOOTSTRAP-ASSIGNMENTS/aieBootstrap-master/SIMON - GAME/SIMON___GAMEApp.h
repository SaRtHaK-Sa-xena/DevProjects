#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Square.h"

class SIMON___GAMEApp : public aie::Application {
public:

	SIMON___GAMEApp();
	virtual ~SIMON___GAMEApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	virtual void GamePhase();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	Square*				Red;
	Square*				Blue;
	Square*				Green;
	Square*				Yellow;
	bool pressed = false;
	Square colours[4] = { *Red, *Blue, *Green, *Yellow};
};