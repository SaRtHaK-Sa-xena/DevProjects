#include "AgentClass.h"

void Agent::Update(float deltaTime)
{
	float force = 0;
	
}

void Agent::Draw(aie::Renderer2D * renderer)
{
	renderer->drawBox(m_Position.x, m_Position.y, 10, 10);
}
