#include "PathfindingBehaviour.h"

const float speedOfSeeker = 150;


Vector2 PathfindBehaviour::Update(Agent * agent, float deltaTime)
{
	//if first position  not equal to anything
	if (m_target->position.m_x == 0, m_target->position.m_y == 0)
	{
		return Vector2();
	}

	else
	{
		//get position, and velocity
		Vector2 Direction(0, 0); //creates a default vector2

		//calculate the vector describing the direction to the target and normalize it
		Direction = m_target->position - agent->GetPosition(); //direction to target

		Direction.normalise(); //normalize

		//Multiply the direction by the speed we want the agent to move
		Direction = Direction * speedOfSeeker;


		//Subtract the agent's current velocity from the result to get the force we need to apply
		Direction = Direction - agent->GetVelocity();

		return Direction;
	}

	
}
