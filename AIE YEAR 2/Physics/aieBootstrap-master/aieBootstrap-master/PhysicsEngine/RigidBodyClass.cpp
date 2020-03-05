#include "RigidBodyClass.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

const float MIN_LINEAR_THRESHOLD = 0.8f;
const float MIN_ROTATION_THRESHOLD = 0.001f;

RigidBodyClass::RigidBodyClass(ShapeType shapeID, glm::vec2 position, glm::vec2 velocity, float rotation, float mass, float elasticity, float angularVelocity, float moment) : PhysicsObject(shapeID), m_position(position), m_velocity(velocity), m_rotation(rotation), m_mass(mass), m_elasticity(elasticity), m_angularVelocity(angularVelocity), m_moment(moment)
{
}

RigidBodyClass::~RigidBodyClass()
{
}

void RigidBodyClass::fixedUpdate(glm::vec2 gravity, float timeStep)
{
	if (m_isKinematic == true)
	{
		m_velocity = glm::vec2(0, 0);
		return;
	}
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
	//===Previous Implementation
	//comments: Works, but not as good as the new implementation, when recieving multiple collisions

	//std::cout << "===========================VELOCITY CHECK START=============================" << std::endl;
	//std::cout << "Before Angular Velocity: " << m_angularVelocity << std::endl;
	//m_velocity += force / m_mass;
	//m_angularVelocity = (force.y * pos.x - force.x * pos.y) / (m_moment);
	//m_angularVelocity = (force.x * pos.y - force.y * pos.x) / (m_moment);

	//std::cout << "force.x: " << force.x << std::endl;
	//std::cout << "force.y: " << force.y << std::endl;

	//if (m_angularVelocity > 50) { m_angularVelocity = 50; }
	//Correct One That Worked The Best	
	//m_angularVelocity += glm::length(m_velocity) / glm::length((pos) / (m_moment) * (-force));
	//
	////point of contact
	////float pos = glm::distance(/*radius, pos*/)
	////float angle = acos(glm::length(force / pos));
	////	new implementation
	///glm::vec2 angle = glm::acos(rad_distance / force);
	//m_angularVelocity += glm::length(force) * rad_distance * sin(glm::length(angle));
	//m_angularVelocity = m_angularVelocity / m_moment;
	////m_angularVelocity += glm::length(force) * glm::length(pos) * sin(angle);
	//float temp = glm::length(pos);
	////glm::length(pos - force)
	////m_angularVelocity += glm::length(m_velocity) / -temp;
	////m_angularVelocity = m_angularVelocity * 5584124.f;

	//std::cout << "Force: " << "X: " << force.x << " Y: " << force.y << std::endl;
	//std::cout << "After Angular Velocity: " << m_angularVelocity << std::endl;
	//std::cout << "===========================VELOCITY CHECK END=============================" << std::endl;

	//===================NEW IMPLEMENTATION=================================================================
	#pragma region New Implementation
	
	//Implementation of calculating Torque, and angular velocity from Michaela
	//[ F = m * a ] can be rewritten to [ a = F / m ] 
	//F = force
	//m = mass
	//a = acceleration
	m_velocity += force / m_mass;
	
	//Torque is calculated as	[ t = ||r|| * ||f|| * sin0 ]
	//t = torque
	//||r|| = the magnitude of the radius from the axis of rotation to the point of application of the force. In otherwords, the distance from the center of the object to the contact point
	//||f|| = the magnitude of the force vector
	//0 = the angle between the object's current angular heading and 'r'
	
	glm::vec2 heading = glm::normalize(m_position + force); //Current heading
	
	//The formula to find the angle between two vectors is [ cos0 = dot(a, b) / ||a|| * ||b|| ]
	float dotResult = glm::dot(heading, pos);
	float magnitudeResult = sqrtf(heading.x * heading.x + heading.y * heading.y) * sqrtf(pos.x * pos.x + pos.y * pos.y);
	float angle = (dotResult == 0 && magnitudeResult == 0) ? 0 : acosf(dotResult / magnitudeResult);
	
	//Multiply lever arm by force
	glm::vec2 lever = pos * sinf(angle);
	glm::vec2 t = lever * force;
	float torque = sqrtf(t.x * t.x + t.y * t.y);
	
	//Angular acceleration is calculations as	[ a = t / i ]
	//a = angular acceleration
	//t = torque
	//i = moment of inertia
	m_angularVelocity += torque / m_moment;

	//m_angularVelocity = m_angularVelocity * glm::length(glm::normalize(-force));

	m_angularVelocity = -m_angularVelocity;

	#pragma endregion New Implementation
}


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
	float v1 = glm::dot(m_velocity, normal) - r1;// * m_angularVelocity;

	// velocity of contact point on actor2
	float v2 = glm::dot(actor2->m_velocity, normal) + r2;// *actor2->m_angularVelocity;

	if (v1 > v2) //	if moving closer
	{
		// calculate the effective mass at contact point for each object
		// ie. how much the contact point will move due to the force applied

		float mass1 = 1.0f / (1.0f / m_mass + (r1 * r2) / m_moment);
		float mass2 = 1.0f / (1.0f / actor2->m_mass + (r2 * r2) / actor2->m_moment);

		float elasticity = (m_elasticity + actor2->getElasticity()) / 2.0f;

		/*std::cout << "=========PRIOR TO FORCE CALCULATION===========" << std::endl;
		std::cout << "Elasticity:" << 1.0f + elasticity << std::endl;
		std::cout << "Mass For Actor 1: " << mass1 << std::endl;
		std::cout << "Mass For Actor 2: " << mass2 << std::endl;
		std::cout << "Velocity of Contact POint on Actor 1: " << v1 << std::endl;
		std::cout << "Velocity of Contact POint on Actor 2: " << v2 << std::endl;
		std::cout << "Normal X_POS: " << normal.x << std::endl;
		std::cout << "Normal Y_POS: " << normal.y << std::endl;
		std::cout << "=============================================" << std::endl;*/


		glm::vec2 force = (1.0f + elasticity)*mass1*mass2 / 
			(mass1 + mass2)*(v1-v2)*normal;


		float spin_const = 2;
		glm::vec2 halfPos(m_position.x / spin_const, m_position.y / spin_const);
		glm::vec2 halfPos2(actor2->getPosition().x / spin_const, actor2->getPosition().y / spin_const);


		/*std::cout << "=========AFTER THE FORCE CALCULATION===========" << std::endl;
		std::cout << "Elasticity:" << 1.0f + elasticity << std::endl;
		std::cout << "Mass For Actor 1: " << mass1 << std::endl;
		std::cout << "Mass For Actor 2: " << mass2 << std::endl;
		std::cout << "Velocity of Contact POint on Actor 1: " << v1 << std::endl;
		std::cout << "Velocity of Contact POint on Actor 2: " << v2 << std::endl;
		std::cout << "Normal X_POS: " << normal.x << std::endl;
		std::cout << "Normal Y_POS: " << normal.y << std::endl;
		std::cout << "=============================================" << std::endl;*/

		//	apply equal and opposite force
		//	according to Newton's Third Law

		/*std::cout << "applied Force for Actor: " << getShapeID() << std::endl;
		std::cout << "FORCE X: " << -force.x << std::endl;
		std::cout << "FORCE Y: " << -force.y << std::endl;

		std::cout << "applied Force for Actor 2: " << actor2->getShapeID() << std::endl;
		std::cout << "FORCE X: " << force.x << std::endl;
		std::cout << "FORCE Y: " << force.y << std::endl;*/

		//What used to be
		//applyForce(-force, halfPos - contact);
		//actor2->applyForce(force, contact - halfPos2);
		
		//Updated
		applyForce(-force, contact-m_position);
		actor2->applyForce(force, contact - actor2->getPosition());

		//TESTING
		//applyForce(-force, contact - halfPos);
		//actor2->applyForce(force, halfPos2 - contact);
	}
}
