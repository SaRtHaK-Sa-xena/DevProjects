#pragma once
#include "GameObject.h"

class GameObject;

class Condition
{
public:
	virtual ~Condition() {};
	virtual bool test(GameObject* go) const = 0;
};

class WithinRangeCondition : public Condition
{
public:
	WithinRangeCondition(GameObject* target, float distance) : m_target(target), m_distance(distance) {}
	WithinRangeCondition(){}

	bool test(GameObject* go) const
	{
		Vector2D target = m_target->getPosition();
		Vector2D pos = go->getPosition();
		Vector2D dist = { target.x - pos.x, target.y - pos.y };
		float length = sqrt(dist.x * dist.x + dist.y * dist.y);

		if (length < m_distance)
		{
			return true;
		}
		return false;
	}

protected:
	GameObject* m_target;
	float m_distance;
};

class NotCondition : public Condition
{
public:
	NotCondition(Condition* condition) : m_condition(condition) {}
	virtual ~NotCondition(){}

	virtual bool test(GameObject* go) const
	{
		return !m_condition->test(go);
	}

protected:
	Condition* m_condition;
};