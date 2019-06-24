#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "SceneObjectClass.h"

class TankAssignmentApp : public aie::Application {
public:

	TankAssignmentApp();
	virtual ~TankAssignmentApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	SpriteObject m_tank, m_turret, m_bullet, temp;
	SpriteObject *new_bullet;

	SceneObject *List = new SceneObject();

	Matrix3 bullet;

	float Tracker;
	bool bulletFired;
	bool bulletFiredAnimate = false;

	float speed = 10;
	//std::vector<SpriteObject*>new_bullet;

};