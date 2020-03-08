#include "PlaneClass.h"

PlaneClass::~PlaneClass()
{
}

void PlaneClass::fixedUpdate(glm::vec2 gravity, float timeStep)
{
}

void PlaneClass::makeGizmo()
{
}

void PlaneClass::resetPosition()
{
}

void PlaneClass::resolveCollision(RigidBodyClass* actor2, glm::vec2 contact)
{
	// The plane isn't moving, so the relative velocity is just actor2's velocity
	glm::vec2 relativeVelocity = actor2->getVelocity();
	float elasticity = actor2->getElasticity();

	float j = glm::dot(-(1 + elasticity) * (relativeVelocity), m_normal) / glm::dot(m_normal, m_normal * ((1 / actor2->getMass())));

	//	force applied 
	glm::vec2 forceApplied = m_normal*j;

	float spinForce = 2;
	glm::vec2 halfPos(actor2->getPosition().x / spinForce, actor2->getPosition().y / spinForce);
	actor2->applyForce(forceApplied, contact - actor2->getPosition());
}
