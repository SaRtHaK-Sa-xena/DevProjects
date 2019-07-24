#pragma once

#include "WanderBehaviourClass.h"
#include "AgentClass.h"


class WanderBehaviour : public Behaviour
{
public:

	WanderBehaviour() 
	{
		float halfOfRadius = radius * 0.5;
		targetToFollow.m_x = radius - halfOfRadius;
		targetToFollow.m_y = radius - halfOfRadius;
		//since x and y have been set the force applied will push it straight away
		//to remove that normalise the vector2
		targetToFollow.normalise();

		//pushes the targetToFollow away by radius
		targetToFollow = targetToFollow * radius;
	};
	virtual ~WanderBehaviour() {};

	virtual Vector2 Update(Agent* agent, float deltaTime);

private:
	Agent *m_target;
	float speed = 50, distance = 20;
	float radius = rand() % 10 - 5;
	int degree = 0;
	float jitter;
	float jitterHalf;

	Vector2 targetToFollow;
};