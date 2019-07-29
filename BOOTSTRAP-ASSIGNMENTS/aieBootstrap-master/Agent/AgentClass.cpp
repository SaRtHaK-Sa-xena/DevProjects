#include "AgentClass.h"

void Agent::Update(float deltaTime)
{

	//force equal to zero
	Vector2 force(0, 0);

	//===========completed================
	//for each Behaviour in Behaviour list
	//call the Behaviour's update Function and add the returned value to force
	for (auto behaviours : m_BehaviourList)
	{
		//returns the force depending on the key pressed
		force = force + behaviours->Update(this, deltaTime);
	}

	//add Force multiplied by deltaTime to Velocity
	m_Velocity = force * deltaTime;
	//add Velocity multiplied by deltaTime to Position
	m_Position = m_Position + m_Velocity;
}

void Agent::Draw(aie::Renderer2D * renderer, aie::Texture * texture)
{
	renderer->drawSprite(texture, m_Position.m_x, m_Position.m_y, 50, 50);
}

void Agent::AddBehaviour(Behaviour * behaviour)
{
	m_BehaviourList.push_back(behaviour);
}

