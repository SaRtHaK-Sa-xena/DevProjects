#include "RigidBodyClass.h"
#define _USE_MATH_DEFINES
#include <math.h>

const float MIN_LINEAR_THRESHOLD = 0.1f;
const float MIN_ROTATION_THRESHOLD = 0.01f;


RigidBodyClass::RigidBodyClass(ShapeType shapeID, glm::vec2 position, glm::vec2 velocity, float rotation, float mass, float elasticity, float angularVelocity, float moment) : PhysicsObject(shapeID), m_position(position), m_velocity(velocity), m_rotation(rotation), m_mass(mass), m_elasticity(elasticity), m_angularVelocity(angularVelocity), m_moment(moment)
{
}

RigidBodyClass::~RigidBodyClass()
{
}

void RigidBodyClass::fixedUpdate(glm::vec2 gravity, float timeStep)
{
	m_velocity += gravity * timeStep;
	m_position += m_velocity * timeStep;
	
	m_velocity -= m_velocity * m_linearDrag * timeStep;
	m_rotation += m_angularVelocity * timeStep;
	m_angularVelocity -= m_angularVelocity * m_angularDrag * timeStep;
	
	if (glm::length(m_velocity) < MIN_LINEAR_THRESHOLD)
	{
		m_velocity = glm::vec2(0, 0);
	}
	if (abs(m_angularVelocity) < MIN_ROTATION_THRESHOLD)
	{
		m_angularVelocity = 0;
	}
}

void RigidBodyClass::debug()
{
}

void RigidBodyClass::applyForce(glm::vec2 force, glm::vec2 pos)
{
	m_velocity += force / m_mass;
	m_angularVelocity += (force.y * pos.x - force.x * pos.y) / (m_moment);
	//m_angularVelocity += glm::length(m_velocity) / glm::length((pos / 2.f) / (m_moment) * (force));
	//m_angularVelocity = m_angularVelocity * 5584124.f;
}

//void RigidBodyClass::applyForceToActor(RigidBodyClass* actor2, glm::vec2 force)
//{
//	//force effect obj A
//	actor2->applyForce(force);
//	
//	//force effect itself obj B
//	applyForce(-force);
//}

void RigidBodyClass::resolveCollision(RigidBodyClass* actor2, glm::vec2 contact, glm::vec2*collisionNormal)
{
	// find the vector between their centres, or use the provided direction
	// of force, and make sure it's normalized
	glm::vec2 normal = glm::normalize(collisionNormal ? *collisionNormal : actor2->m_position - m_position);
	
	// get the vector perpendicular to the collision normal
	glm::vec2 perp(normal.y, -normal.x);

	// determine the total velocity of the contact points for the two objects,
	// for both linear and rotational

	// 'r' is the radius from axis to application of force
	float r1 = glm::dot(contact - m_position, -perp); 
	float r2 = glm::dot(contact - actor2->m_position, perp);
	
	// velocity of the contact point on this object
	float v1 = glm::dot(m_velocity, normal) - r1 * m_angularVelocity;

	// velocity of contact point on actor2
	float v2 = glm::dot(actor2->m_velocity, normal) + r2 * actor2->m_angularVelocity;

	if (v1 > v2) //	if moving closer
	{
		// calculate the effective mass at contact point for each object
		// ie. how much the contact point will move due to the force applied

		float mass1 = 1.0f / (1.0f / m_mass + (r1 * r2) / m_moment);
		float mass2 = 1.0f / (1.0f / actor2->m_mass + (r2 * r2) / actor2->m_moment);

		float elasticity = (m_elasticity + actor2->getElasticity()) / 2.0f;

		glm::vec2 force = (1.0f + elasticity)*mass1*mass2 / 
			(mass1 + mass2)*(v1-v2)*normal;

		//	apply equal and opposite force
		//	according to Newton's Third Law
		applyForce(-force, contact - m_position);
		actor2->applyForce(force, contact - actor2->m_position);
	}
}
