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

	void startPhase();
	void selectPhase();
	void gamePhase();

	PhysicsScene* m_physicsScene;

	SphereClass* rocket_Ship;
	SphereClass* sphere;
	AABBClass* box1;
	AABBClass* box;
	SphereClass* striker;

	SphereClass* mousePointer = new SphereClass(glm::vec2(0, 0), 0, 0, 1, 2, glm::vec4(1, 0, 1, 1));
protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};