#include "SeekBehaviourClass.h"

Vector2 SeekBehaviour::Update(Agent * agent, float deltaTime)
{
	//if target is null return a zero vector
	if (m_target == nullptr)
	{
		return Vector2();
	}
	
	else
	{
		////get position, and velocity
		//agent->GetPosition();
		//agent->GetVelocity();

		//Vector2 m; //maybe 

		////calculate the vector describing the direction to the target and normalize it
		////direction
		//m.magnitude();
		//
		////normalized
		//m.normalise();


		////Multiply the direction by the speed we want the agent to move
		////Vector2 result = m.m_y *= 20;


		////Vector2 example(m.m_x, m.m_y * 20);
		////Vector2 newPosition = agent->GetPosition() * 2;
		//Vector2 result = m_target->GetPosition() - agent->GetPosition();//just added
	
		//result.normalise();
		//
		////result.m_y * 2;
		////result * deltaTime;
		////Subtract the agent's current velocity from the result to get the force we need to apply
		//Vector2 force;
		////return result;
		//return force = agent->GetVelocity() - result;
		////force.normalise();
		////example used to be in this

		////return vector2();
		Vector2 Direction(0, 0);

		Vector2 Position = agent->GetPosition(); //agent's position

		Vector2 TargetPosition = m_target->GetPosition(); //target's position

		Direction = TargetPosition - Position; //direction to target

		Direction.normalise(); //normalize

		Direction = Direction * speed * deltaTime;

		//Direction = speed * deltaTime - Direction;

		Direction = agent->GetVelocity() - Direction;

		//Direction = Direction - agent->GetVelocity(); //give it speed

		//Vector2 force = agent->GetVelocity() - result;

		return Direction;
	}
}
