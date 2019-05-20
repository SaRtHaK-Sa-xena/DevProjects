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

	virtual void MoveDoneForRed(float deltaTime);
	virtual void GamePhase(float deltaTime);

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	Array	        *m_binaryTree;
	Node		    *m_selectedNode = nullptr;
	Bar *RED;
	Bar *BLUE;
	Bar *GREEN;
	Bar *YELLOW;

	Bar *Colour;

	Bar *colours[4] = { RED, BLUE, GREEN, YELLOW };
	float timer = 5;

	bool TimeEnd = false;
	bool Todraw = false;
};