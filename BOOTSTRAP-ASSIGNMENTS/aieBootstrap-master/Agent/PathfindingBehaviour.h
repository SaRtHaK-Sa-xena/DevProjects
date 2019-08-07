#pragma once
#include "AgentClass.h"
#include "NodeClass.h"

class PathfindBehaviour : public Behaviour
{
public:

	PathfindBehaviour() {};
	virtual ~PathfindBehaviour() {};

	virtual Vector2 Update(Agent* agent, float deltaTime);

	void SetTarget(Node* targetToSeek)
	{
		m_target = targetToSeek;
	}

private:
	Node* m_target;
};