#pragma once
#include "AgentClass.h"

class SeekBehaviour : public Behaviour
{
public:
	
	SeekBehaviour() {};
	virtual ~SeekBehaviour() {};

	virtual Vector2 Update(Agent* agent, float deltaTime);
	void SetTarget(Agent *agent)
	{
		m_target = agent;
	}

private:
	Agent *m_target;
};