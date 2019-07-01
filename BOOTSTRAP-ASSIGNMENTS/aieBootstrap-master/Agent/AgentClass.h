#pragma once
#include <Renderer2D.h>
#include "BehaviourClass.h"
#include <vector>


class Agent
{
public:
	Agent() { m_Velocity.m_x = 0; m_Velocity.m_y = 0; };
	virtual ~Agent() { };

	// Update the agent and its behaviours
	virtual void Update(float deltaTime);

	// Draw the agent
	virtual void Draw(aie::Renderer2D* renderer);

	// Add a behaviour to the agent
	void AddBehaviour(Behaviour* behaviour);

	// Movement functions
	void SetPosition(Vector2 position) { m_Position = position; } //m_Position.m_y = position.m_y; } //would consist of (x,y)
	Vector2 GetPosition() { return m_Position; }
	
	void SetVelocity(Vector2 velocity) { m_Velocity = velocity; }//would consist of (x,2)
	Vector2 GetVelocity() { return m_Velocity; }

protected:
	std::vector<Behaviour*> m_BehaviourList;
	Vector2 m_Position;
	Vector2 m_Velocity;
};