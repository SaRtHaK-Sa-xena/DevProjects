#pragma once
#include "AgentClass.h"

class PathfindBehaviour : public Behaviour
{
public:

	PathfindBehaviour() {};
	virtual ~PathfindBehaviour() {};

	virtual Vector2 Update(Agent* agent, float deltaTime);

	void SetTarget(Vector2 position)
	{
		m_target = position;
	}

private:
	Vector2 m_target;
};