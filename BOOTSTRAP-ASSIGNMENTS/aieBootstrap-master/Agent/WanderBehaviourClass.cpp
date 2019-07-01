#include "WanderBehaviourClass.h"
#include <Vector3.h>

Vector2 WanderBehaviour::Update(Agent * agent, float deltaTime)
{
	if (m_target)
	{

	}
	else
	{
		//Find Direction
		Vector3 circleCenter;
		circleCenter.m_x = agent->GetVelocity().m_x;
		circleCenter.m_y = agent->GetVelocity().m_y;

		//normalize it
		circleCenter.normalise();
		circleCenter = circleCenter * 3; //3 is const

		Vector3 displacement = Vector3(0, 0, -1);
		displacement = displacement * 3;

		
	}
	return Vector2();
}
