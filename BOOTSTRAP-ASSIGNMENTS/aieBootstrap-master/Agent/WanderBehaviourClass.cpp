#include "WanderBehaviourClass.h"
#include <Matrix3.h>
#include <Vector3.h>
#include <math.h>
#include <iostream>

Vector2 WanderBehaviour::Update(Agent * agent, float deltaTime)
{
	//if (m_target == nullptr)
	//{

	//}
	//else
	//{

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

	//return Vector2();



	//
	//position of target
	//Vector2 positionAheadOfTarget(m_target->GetPosition().m_x * radius, m_target->GetPosition().m_y * radius);

	//positionAheadOfTarget = agent->GetPosition() - m_target->GetPosition(); //direction

	//positionAheadOfTarget.normalise(); //normalise

	//positionAheadOfTarget = positionAheadOfTarget * (speed * deltaTime);

	//positionAheadOfTarget = positionAheadOfTarget - agent->GetVelocity();

	//return positionAheadOfTarget;


	//================FIRST ATTEMPT============SORT OF DONE==========================================

	//circle needs to point to the same velocity vector as the agent
	//Vector2 force(0,0);
	//Vector2 displacement(0,-1);
	//float magDisplacement = displacement.magnitude();


	//displacement = displacement * radius; //scale by CIRCLE_RADIUS

	//displacement.m_x = cos(jitter) * (magDisplacement * deltaTime);
	//displacement.m_y = sin(jitter) * (magDisplacement * deltaTime);

	//jitter = jitter + rand() % 10 + (rand() % -10); //* .5;
	//std::cout << jitter;

	////points at
	//force = (displacement - agent->GetVelocity());

	////only has direction no force
	//force.normalise();

	//force = force * (distance / deltaTime);

 ////scale by


	//Vector2 WanderForce(0, 0);
	//WanderForce = force + displacement * deltaTime;
	//return WanderForce;

	//==================NEW ATTEMPT============================
		Vector2 circleCenter(0,0);
		while (circleCenter.magnitude() == 0) //while mag 0
		{
			circleCenter.m_x = 2;//rand() % 10 + rand() % -5;
			circleCenter.m_y = 2;//rand() % 10 + rand() % -5;
		}
		//just changed===================================
		//if (agent->GetVelocity().magnitude() == 0) //if velocity equal to zero
		//{
		//	circleCenter = agent->GetPosition(); //use position
		//}
		//else
		//{
		//	circleCenter = agent->GetVelocity(); //matches the agent's ms_2 looking
		//}
		//circleCenter.normalise(); //direction
		//circleCenter = circleCenter * distance; //defining circle center 5 spaces in
		//just changed===================================
		Vector2 dispalcement(0,0);
		while (dispalcement.magnitude() == 0) //while mag 0
		{
			dispalcement.m_x = rand() % 10 + rand() % -5;
			dispalcement.m_y = rand() % 10 + rand() % -5;
		}
		Vector2 temporary = agent->GetVelocity();
		dispalcement = dispalcement * radius;// 
		dispalcement = dispalcement + circleCenter;
		dispalcement.normalise();
		temporary.normalise();
		dispalcement = dispalcement + temporary * distance;




		//displacement force

		//float magOfdispalcement = dispalcement.magnitude();

		//just changed
		//dispalcement.normalise(); //only direction
		//dispalcement = dispalcement * radius;// now represents a point on the radi of circle

		////just added
		//agent->GetVelocity().normalise();
		//dispalcement = dispalcement + agent->GetVelocity() * distance;
		//just changed



		Vector2 WANDERFORCE(dispalcement);
		WANDERFORCE.normalise();
		WANDERFORCE = WANDERFORCE * deltaTime * speed;
		//WANDERFORCE = WANDERFORCE * speed;
		WANDERFORCE = WANDERFORCE - agent->GetVelocity();
		//WANDERFORCE = dispalcement + circleCenter;
		//WANDERFORCE = dispalcement + circleCenter;

		return WANDERFORCE;
	//}
	

	
}		//dispalcement.m_x = cos(jitter) * magOfdispalcement;
		//dispalcement.m_y = sin(jitter) * magOfdispalcement;

		//Vector2 pointsAt(0, 0);
		//pointsAt = dispalcement - agent->GetVelocity();

		//degree = (1 + rand() % 360) * PI / 180;
		//dispalcement.m_x = cos(degree) * magOfdispalcement;
		//dispalcement.m_y = sin(degree) * magOfdispalcement;
