#include "RigidBodyClass.h"


RigidBodyClass::RigidBodyClass(ShapeType shapeID, glm::vec2 position, glm::vec2 velocity, float rotation, float mass) : PhysicsObject(shapeID), m_position(position), m_velocity(velocity), m_rotation(rotation), m_mass(mass)
{
}

RigidBodyClass::~RigidBodyClass()
{
}

void RigidBodyClass::fixedUpdate(glm::vec2 gravity, float timeStep)
{
	applyForce(gravity * m_mass * timeStep);
	m_position += m_velocity * timeStep;
}

void RigidBodyClass::debug()
{
}

void RigidBodyClass::applyForce(glm::vec2 force)
{
	m_velocity += force / m_mass;
}

void RigidBodyClass::applyForceToActor(RigidBodyClass* actor2, glm::vec2 force)
{
	//force effect obj A
	actor2->applyForce(force);
	
	//force effect itself obj B
	applyForce(-force);
}

void RigidBodyClass::resolveCollision(RigidBodyClass* actor2)
{
	glm::vec2 normal = glm::normalize(actor2->getPosition() - m_position);
	glm::vec2 relativeVelocity = actor2->getVelocity() - m_velocity;

	//assumed as one
	float elasticity = 1;

	//Formula for calculating impulse magnitude
	float j = glm::dot(-(1 + elasticity) * (relativeVelocity), normal)
		/ glm::dot(normal, normal * ((1 / m_mass) + (1 / actor2->getMass())));

	glm::vec2 force = normal * j;

	applyForceToActor(actor2, -force);

}
