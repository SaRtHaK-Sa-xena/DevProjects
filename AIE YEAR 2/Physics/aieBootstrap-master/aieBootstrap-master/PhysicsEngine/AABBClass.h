#pragma once
#include "RigidBodyClass.h"

class AABBClass : public RigidBodyClass
{
public:
	
	//second constuctor for position placement through vectors
	AABBClass(glm::vec2 a_topLeft, glm::vec2 a_bottomRight);

	//third constructor
	AABBClass(glm::vec2 position, float a_width, float a_height);


	~AABBClass();

	//some functions
	virtual void debug() {};
	virtual void makeGizmo();
	virtual void fixedUpdate(glm::vec2 gravity, float timeStep);
	virtual bool checkCollision(PhysicsObject* pOther);

	float getWidth() { return m_width; };
	float getHeight() { return m_height; }

	glm::vec2 getLocalX() { return m_localX; }
	glm::vec2 getLocalY() { return m_localY; }

	float getAngularVelocity() { return m_angularVelocity; }
	float getMoment() { return m_moment; }

protected:
	
	//points on the Box
	//float m_TopLeft_x;
	//float m_TopLeft_y;

	//float m_BottomRight_x;
	//float m_BottomRight_y;

	////direct position
	//glm::vec2 m_topLeft;
	//glm::vec2 m_bottomRight;

	float m_width;
	float m_height;

	glm::vec2 m_localX;
	glm::vec2 m_localY;
};

