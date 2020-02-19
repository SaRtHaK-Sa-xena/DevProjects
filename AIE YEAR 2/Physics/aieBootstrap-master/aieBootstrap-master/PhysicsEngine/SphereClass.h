#pragma once
#include "RigidBodyClass.h"

class SphereClass : public RigidBodyClass
{
public:
	SphereClass(glm::vec2 position, glm::vec2 velocity, 
		float mass, float radius, float elasticity, float angularVelocity, float moment, glm::vec4 colour);

	SphereClass(glm::vec2 position, float speed, float angle,
		float mass, float radius, glm::vec4 colour);
	
	~SphereClass();

	virtual void makeGizmo();
	virtual bool checkCollision(PhysicsObject* pOther);


	float getRadius() { return m_radius; }
	glm::vec4 getColour() { return m_colour; }

	//	To Track Score Functions
	float getTimeStored() { return m_timeUntilScore; }
	void incrementTimeStored() { m_timeUntilScore = m_timeUntilScore + 1; }
	void resetTimeStored() { m_timeUntilScore = 0; }
	
	//	To Track Player Turn
	bool returnPlayerTurn() { return m_player; }

protected:
	float m_radius;
	glm::vec4 m_colour;

	// Stores Time Here When Above Hole
	float m_timeUntilScore;

	//	if true player equal to 'PLAYER 1'
	//	if false player equal to 'PLAYER 2'
	bool m_player = true;
};

