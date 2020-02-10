#pragma once
#include "PhysicsObject.h"
#include "RigidBodyClass.h"

class PlaneClass : public PhysicsObject
{
public:
	PlaneClass() : PhysicsObject(ShapeType::PLANE) { m_distanceToOrigin = 0; m_normal = glm::vec2(0, 1); };
	PlaneClass(glm::vec2 normal, float distance) : PhysicsObject(PLANE), m_normal(normal), m_distanceToOrigin(distance) {};
	~PlaneClass();

	virtual void fixedUpdate(glm::vec2 gravity, float timeStep);
	virtual void debug() {};
	virtual void makeGizmo();
	virtual void resetPosition();
	
	void resolveCollision(RigidBodyClass* actor2, glm::vec2 contact);
	

	glm::vec2 getNormal() { return m_normal; }
	float getDistance() { return m_distanceToOrigin; }

protected:
	glm::vec2 m_normal;
	float m_distanceToOrigin;
};

