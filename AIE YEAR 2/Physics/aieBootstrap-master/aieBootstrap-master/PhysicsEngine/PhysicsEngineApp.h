#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "PhysicsClass.h"
#include "SphereClass.h"
#include "AABBClass.h"

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

	SphereClass* rocket_Ship;
	AABBClass* box1;
	AABBClass* box2;
protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};