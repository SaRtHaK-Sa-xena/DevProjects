#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "PhysicsClass.h"
#include "SphereClass.h"

class PhysicsEngineApp : public aie::Application {
public:

	PhysicsEngineApp();
	virtual ~PhysicsEngineApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();


	PhysicsScene* m_physicsScene;
	SphereClass* Ball1;
	SphereClass* Ball2;
protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};