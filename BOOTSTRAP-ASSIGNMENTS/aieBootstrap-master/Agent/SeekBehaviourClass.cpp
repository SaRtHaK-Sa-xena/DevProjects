#include "SeekBehaviourClass.h"

Vector2 SeekBehaviour::Update(Agent * agent, float deltaTime)
{
	//if target is null return a zero vector
	if (m_target == nullptr)
	{
		return Vector2(0, 0);
	}
	
	else
	{
		//get position, and velocity
		agent->GetPosition();
		agent->GetVelocity();

		Vector2 m(0, 0); //maybe 

		//calculate the vector describing the direction to the target and normalize it
		//direction
		m.magnitude();
		//normalized
		m.normalise();


		//Multiply the direction by the speed we want the agent to move
		//Vector2 result = m.m_y *= 20;


		Vector2 example(m.m_x, m.m_y * 20);

		Vector2 result = agent->GetPosition.m_y * 20;//just added

		//Subtract the agent's current velocity from the result to get the force we need to apply
		Vector2 force;
		return force = agent->GetVelocity() - result; //example used to be in this

		//return vector2();
	}
}
