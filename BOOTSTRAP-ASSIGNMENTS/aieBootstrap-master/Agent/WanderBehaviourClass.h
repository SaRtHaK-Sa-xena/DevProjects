#pragma once
#include "AgentClass.h"

class WanderBehaviour : public Behaviour
{
public:

	WanderBehaviour();
	virtual ~WanderBehaviour();

	virtual Vector2 Update(Agent* agent, float deltaTime);
	void setTarget(Agent *agent)
	{
		m_target = agent;
	}

private:
	Agent *m_target;
};