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

	void setupContinuousDemo(glm::vec2 startPos, float inclination, float speed, float gravity);

	PhysicsScene* m_physicsScene;
	float fuel = 100;
	float time = 100;

	SphereClass* rocket_Ship;
protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};