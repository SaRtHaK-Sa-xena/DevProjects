#include "AgentClass.h"

Agent::Agent()
{
	m_Position.m_x = 0;
	m_Position.m_y = 0;

	m_Velocity.m_x = 0;
	m_Velocity.m_y = 0;
	
}

Agent::~Agent()
{
}

void Agent::Update(float deltaTime)
{
	Vector2 force;
	Agent* newAgent = new Agent();

	for (auto behaviours : m_behaviourList)
	{
		force = force + behaviours->Update(newAgent, deltaTime);
	}
}

void Agent::Draw(aie::Renderer2D * renderer)
{
}

void Agent::AddBehaviour(Behaviour * behaviour)
{
}

void Agent::setPosition(Vector2 position)
{
}

Vector2 Agent::getPosition()
{
	return Vector2();
}

void Agent::setVelocity(vector2 velocity)
{
}

void Agent::getVelocity()
{
}
