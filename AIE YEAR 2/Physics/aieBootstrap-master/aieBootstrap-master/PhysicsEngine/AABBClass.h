#pragma once
#include "RigidBodyClass.h"

class AABBClass : public RigidBodyClass
{
public:
	
	//second constuctor for position placement through vectors
	AABBClass(glm::vec2 a_topLeft, glm::vec2 a_bottomRight) : m_topLeft(a_topLeft), m_bottomRight(a_bottomRight) {};

	//third constructor
	AABBClass(float a_x, float a_y, float a_width, float a_height) : m_x(a_x), m_y(a_y), m_width(a_width), m_height(a_height) {};

	~AABBClass();

	//some functions
	virtual void debug() {};
	virtual void makeGizmo();
	virtual bool checkCollision(PhysicsObject* pOther) { return false; };

	float getTopLeft_x() { return m_TopLeft_x; }
	float getTopLeft_y() { return m_TopLeft_y; }

	float getBottomRight_x() { return m_BottomRight_x; }
	float getBottomRight_y() { return m_BottomRight_y; }

	void setPosition(glm::vec2 a_position) { m_position = a_position; }

protected:
	
	//points on the Box
	float m_TopLeft_x;
	float m_TopLeft_y;

	float m_BottomRight_x;
	float m_BottomRight_y;

	//direct position
	glm::vec2 m_topLeft;
	glm::vec2 m_bottomRight;

	float m_x;
	float m_y;
	float m_width;
	float m_height;
	
	glm::vec2 m_position;
};

