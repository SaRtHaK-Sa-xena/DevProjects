#include "WanderBehaviourClass.h"
#include <Matrix3.h>
#include <Vector3.h>
#include <math.h>

Vector2 WanderBehaviour::Update(Agent * agent, float deltaTime)
{
	if (m_target == nullptr)
	{

	}
	else
	{
		//Matrix3 Circle(1, 13, 5, -1, 2, 2, 0, 3, -1, 1, 1, 1);

		////Find Direction
		//Vector3 circleCenter;
		//circleCenter.m_x = agent->GetVelocity().m_x;
		//circleCenter.m_y = agent->GetVelocity().m_y;

		////normalize it
		//circleCenter.normalise();
		//circleCenter = circleCenter * 3; //3 is const

		//Vector3 displacement = Vector3(0, 0, -1);
		//displacement = displacement * 3;


		//=======================================================
		//====================CURRENTLY IN USE==============================
		//create a target variable ahead of agent
		//Vector2 direction; //this is what the agent is looking at 

		//Vector2 circle;

		//m_target->SetPosition(rand() % 10);

		////target's velocity will equal direction's velocity + it's own
		//m_target->SetPosition(direction + m_target->GetPosition());

		//direction = m_target->GetPosition() - agent->GetPosition();

		//direction.normalise();

		//direction = direction * speed * deltaTime;

		//direction = direction - agent->GetVelocity();

		//return direction;

		//========================CURRENTLY IN USE=================================
		//Direction to target
		//direction = m_target->GetPosition() - agent->GetPosition();
		//direction.normalise();
		//direction = direction * speed * deltaTime;
		//direction = direction - agent->GetVelocity(); //this'll finally move it to the direction of agent
		//return direction [the movement]
	}
	//return Vector2();



	//
	//position of target
	//Vector2 positionAheadOfTarget(m_target->GetPosition().m_x * radius, m_target->GetPosition().m_y * radius);

	//positionAheadOfTarget = agent->GetPosition() - m_target->GetPosition(); //direction

	//positionAheadOfTarget.normalise(); //normalise

	//positionAheadOfTarget = positionAheadOfTarget * (speed * deltaTime);

	//positionAheadOfTarget = positionAheadOfTarget - agent->GetVelocity();

	//return positionAheadOfTarget;


	//=====================================================================================

	//circle needs to point to the same velocity vector as the agent
	Vector2 force(0, 0);

	//points at
	force = m_target->GetPosition() - agent->GetPosition();

	//only has direction no force
	force.normalise();

	force = force * distance; //scale by

	Vector2 displacement(0,-1);
	displacement = displacement * radius; //scale by CIRCLE_RADIUS

	displacement.m_x = cos(jitter) * distance;
	displacement.m_y = sin(jitter) * distance;
	//V = pointA - pointB

	jitter += rand() % 10 - 5 * .5;

	Vector2 WanderForce(0, 0);
	WanderForce = force + displacement;
	return WanderForce;


}

