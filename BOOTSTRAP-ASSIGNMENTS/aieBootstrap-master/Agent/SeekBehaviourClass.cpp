#include "SeekBehaviourClass.h"

const float speedOfSeeker = 150;

Vector2 SeekBehaviour::Update(Agent * agent, float deltaTime)
{
	//if target is null return a zero vector
	if (m_target == nullptr)
	{
		return Vector2();
	}
	
	else
	{
		//get position, and velocity
		Vector2 Direction(0, 0); //creates a default vector2

		//calculate the vector describing the direction to the target and normalize it
		Direction = m_target->GetPosition() - agent->GetPosition(); //direction to target

		Direction.normalise(); //normalize

		//Multiply the direction by the speed we want the agent to move
		Direction = Direction * speedOfSeeker;


		//Subtract the agent's current velocity from the result to get the force we need to apply
		Direction = Direction - agent->GetVelocity();

		return Direction;
	}
}
