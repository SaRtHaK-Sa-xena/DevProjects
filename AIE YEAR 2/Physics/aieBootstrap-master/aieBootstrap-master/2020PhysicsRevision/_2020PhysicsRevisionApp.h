#pragma once

#include "Application.h"
#include "Renderer2D.h"

class _2020PhysicsRevisionApp : public aie::Application {
public:

	_2020PhysicsRevisionApp();
	virtual ~_2020PhysicsRevisionApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	float x = -35;
	float y = -35;

	bool action = false;
};