#pragma once

#include "State.h"
#include "GameObject.h"
#include <vector>

class GameObject;

class ChaseState : public State
{
public:
	ChaseState();
	~ChaseState();

	void onUpdate(GameObject* object, float dt);

	void setTarget(GameObject* target) { m_target = target;  }

private:
	GameObject* m_target;
};