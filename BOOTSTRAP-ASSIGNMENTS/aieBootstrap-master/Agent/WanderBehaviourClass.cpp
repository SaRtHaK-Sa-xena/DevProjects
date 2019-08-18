#include "WanderBehaviourClass.h"
#include <Matrix3.h>
#include <Vector3.h>
#include <math.h>
#include <iostream>

Vector2 WanderBehaviour::Update(Agent * agent, float deltaTime)
{


	//Reworked everything increased by 5
	//targets position as random
	jitter = (rand() % 15) - 10;
	float jitterDifference = rand() % 15;
	jitterHalf = jitter / 2;

	Vector2 displacement;

	displacement.m_x = jitter;
	jitter = rand() % 15 - 10;
	displacement.m_y = jitter;
	while (displacement.magnitude() == 0)
	{
		jitter = rand() % 15 - 10;
		displacement.m_x = jitter;
		jitter = rand() % 15 - 10;
		displacement.m_y = jitter;
		std::cout << "still 0" << std::endl;
	}
	targetToFollow = targetToFollow + displacement;

	//since targetToFollow has got back its direction and position
	//it is normalised so it only holds a direction not a position
	targetToFollow.normalise();
	targetToFollow = targetToFollow * radius;
	//agent->GetVelocity().normalise(); //finds the agents current direction
	targetToFollow = targetToFollow + agent->GetVelocity() * distance; //and moves its crosshair to that direction


	//Force To Finally push it in the direction of target
	Vector2 wanderForceApplied;
	wanderForceApplied = agent->GetVelocity() - targetToFollow;
	wanderForceApplied.normalise();
	wanderForceApplied = wanderForceApplied - agent->GetVelocity(); //minus the agent's current normalised velocity --> so direction
	wanderForceApplied = wanderForceApplied * speed * 0.3;
	return wanderForceApplied;
}