#pragma once
#include "AgentClass.h"
#include "NodeClass.h"

class PathfindBehaviour : public Behaviour
{
public:

	PathfindBehaviour() {};
	virtual ~PathfindBehaviour() {};

	Vector2 Update(Agent* agent, float deltaTime);

	void SetTarget(std::vector<Node*>Path)
	{
		m_target = Path;
	}

private:
	std::vector < Node*> m_target;
};