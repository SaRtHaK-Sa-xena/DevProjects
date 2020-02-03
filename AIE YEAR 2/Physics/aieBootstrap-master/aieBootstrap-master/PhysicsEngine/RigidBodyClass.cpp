#include "RigidBodyClass.h"

void RigidBodyClass::fixedUpdate(glm::vec2 gravity, float timeStep)
{
	applyForce(gravity * m_mass * timeStep);
	m_position += m_velocity * timeStep;
}

void RigidBodyClass::applyForce(glm::vec2 force)
{
	m_velocity = force * m_mass;
}

void RigidBodyClass::applyForceToActor(RigidBodyClass* actor2, glm::vec2 force)
{
	//force effect obj A
	actor2->applyForce(force);
	
	//force effect itself obj B
	applyForce(-force);
}
