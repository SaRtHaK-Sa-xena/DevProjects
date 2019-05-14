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

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	Square*				m_square_Red;
	bool ToDraw = false;
};