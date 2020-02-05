#include "PhysicsClass.h"
#include "RigidBodyClass.h"
#include "SphereClass.h"
#include "PlaneClass.h"
#include "AABBClass.h"
#include <list>
#include <iostream>

//function pointer array for doing collisions
typedef bool(*fn)(PhysicsObject*, PhysicsObject*);


static fn collisionFunctionArray[] =
{
	PhysicsScene::plane2Plane, PhysicsScene::plane2Sphere, PhysicsScene::plane2Box,
	PhysicsScene::sphere2Plane, PhysicsScene::sphere2Sphere, PhysicsScene::sphere2Box,
	PhysicsScene::box2Plane, PhysicsScene::box2Sphere, PhysicsScene::box2Box,
};


PhysicsScene::PhysicsScene():m_timeStep(0.01f), m_gravity(glm::vec2(0,-10))
{
}

PhysicsScene::~PhysicsScene()
{
	for (auto pActor : m_actors)
	{
		delete pActor;
	}
}

//adds that pointer to the end of the list
void PhysicsScene::addActor(PhysicsObject* actor)
{
	m_actors.push_back(actor);
}

//remove the actor
void PhysicsScene::removeActor(PhysicsObject* actor)
{
	for (int i = 0; i < m_actors.size(); i++)
	{
		if (actor == m_actors[i])
		{
			delete m_actors[i];
		}
	}
}

void PhysicsScene::update(float dt)
{
	static std::list<PhysicsObject*> dirty;

	// update physics at a fixed time step
	static float accumulatedTime = 0.0f;
	accumulatedTime += dt;
	while (accumulatedTime >= m_timeStep)
	{
		for (auto pActor : m_actors)
		{
			pActor->fixedUpdate(m_gravity, m_timeStep);
		}
		accumulatedTime -= m_timeStep;


		//check for collisions
		checkForCollision();
		/*for (auto pActor : m_actors)
		{
			for (auto pOther : m_actors)
			{
				if (pActor == pOther)
				{
					continue;
				}
				if (std::find(dirty.begin(), dirty.end(), pActor) != dirty.end() && std::find(dirty.begin(), dirty.end(), pOther) != dirty.end())
					continue;


				RigidBodyClass* pRigid = dynamic_cast<RigidBodyClass*>(pActor);
				if (pRigid->checkCollision(pOther) == true)
				{
					pRigid->applyForceToActor(
						dynamic_cast<RigidBodyClass*>(pOther),
						pRigid->getVelocity()* pRigid->getMass());
					dirty.push_back(pRigid);
					dirty.push_back(pOther);
				}
			}
		}
		dirty.clear();*/
	}
}

void PhysicsScene::updateGizmos()
{
	for (auto pActor : m_actors) {
		pActor->makeGizmo();
	}
}

void PhysicsScene::debugScene()
{
	int count = 0;
	for (auto pActor : m_actors)
	{
		std::cout << count << " : ";
		pActor->debug();
		count++;
	}
}



void PhysicsScene::checkForCollision()
{
	int actorCount = m_actors.size();

	//need to check for collisions against all objects except this one.
	for (int outer = 0; outer < actorCount - 1; outer++)
	{
		for (int inner = outer + 1; inner < actorCount; inner++)
		{
			PhysicsObject* object1 = m_actors[outer];
			PhysicsObject* object2 = m_actors[inner];
			int shapeId1 = object1->getShapeID();
			int shapeId2 = object2->getShapeID();

			//using function pointers
			int functionIdx = (shapeId1 * SHAPE_COUNT) + shapeId2;
			fn collisionFunctionPtr = collisionFunctionArray[functionIdx];
			if (collisionFunctionPtr != nullptr)
			{
				// did a collision occur?
				collisionFunctionPtr(object1, object2);
			}
		}
	}
}

bool PhysicsScene::plane2Plane(PhysicsObject*, PhysicsObject*)
{
	return false;
}

bool PhysicsScene::plane2Sphere(PhysicsObject*, PhysicsObject*)
{
	return false;
}

bool PhysicsScene::plane2Box(PhysicsObject*, PhysicsObject*)
{
	return false;
}

bool PhysicsScene::sphere2Plane(PhysicsObject* obj1, PhysicsObject* obj2)
{
	SphereClass *sphere = dynamic_cast<SphereClass*>(obj1);
	PlaneClass *plane = dynamic_cast<PlaneClass*>(obj2);

	//if we are successful then test for collision
	if (sphere != nullptr && plane != nullptr)
	{
		glm::vec2 collisionNormal = plane->getNormal();
		float sphereToPlane = glm::dot(sphere->getPosition(), plane->getNormal()) - plane->getDistance();
		float forceDirection = 1.0f;

		//if we are behind plane then we flip the normal
		if (sphereToPlane < 0) 
		{
			collisionNormal *= -1;
			sphereToPlane *= -1;
			forceDirection = -1.0f;
		}

		//intersection
		float intersection = sphere->getRadius() - sphereToPlane;
		if (intersection > 0)
		{
			//set sphere velocity to zero
			//sphere->setVelocity(glm::vec2(0, 0));

			//add that distance to the velocity of sphere to move it
			//sphere->getPosition() += sphere->getPosition() * collisionNormal * intersection;
			
			//Keep Sphere above Plane
			sphere->movePosition(intersection * collisionNormal);

			//Apply Force Upwards
			glm::vec2 appliedForce = collisionNormal * glm::length(sphere->getVelocity()) * forceDirection;
			sphere->applyForce(appliedForce * 0.7f);

			return true;
		}
	}
	return false;
}

bool PhysicsScene::sphere2Sphere(PhysicsObject* obj1, PhysicsObject* obj2)
{
	//try to cast objects to sphere and sphere
	SphereClass* sphere1 = dynamic_cast<SphereClass*>(obj1);
	SphereClass* sphere2 = dynamic_cast<SphereClass*>(obj2);

	//if we are successful then test for collision
	if (sphere1 != nullptr && sphere2 != nullptr)
	{
		//coliison detection
		// set the velocity of the two spheres to zero
		//if overlappingd

		glm::vec2 difference = sphere1->getPosition() - sphere2->getPosition();

		float gradient = sqrt(difference.x * difference.x + difference.y * difference.y) * 2;

		if (gradient < (sphere1->getRadius() + sphere2->getRadius()))
		{
			//works somewhat
			glm::vec2 normalizeSphere1 = glm::normalize(sphere1->getVelocity());
			glm::vec2 normalizeSphere2 = glm::normalize(sphere2->getVelocity());
			sphere1->movePosition(normalizeSphere1 * gradient);
			sphere2->movePosition(normalizeSphere2 * gradient);
			sphere1->applyForceToActor(sphere2, sphere1->getVelocity() * 0.1f);
		}
	}
	return false;
}

bool PhysicsScene::sphere2Box(PhysicsObject*, PhysicsObject*)
{
	return false;
}

bool PhysicsScene::box2Plane(PhysicsObject*, PhysicsObject*)
{
	return false;
}

bool PhysicsScene::box2Sphere(PhysicsObject*obj1, PhysicsObject*obj2)
{
	AABBClass* box1 = dynamic_cast<AABBClass*>(obj1);
	SphereClass* sphere1 = dynamic_cast<SphereClass*>(obj2);

	//if valid
	if (sphere1, box1)
	{
		//glm::vec2 difference = sphere1->getPosition() - box1->getPosition();

		////============================================================
		//float minX;
		//if ((box1->getWidth() + box1->getPosition().x) < sphere1->getRadius())
		//{
		//	minX = box1->getWidth() + box1->getPosition().x;
		//}
		//else
		//{
		//	minX = sphere1->getRadius();
		//}
		//float maxX;
		//if (minX > box1->getWidth())
		//{
		//	maxX = minX;
		//}
		//else
		//{
		//	maxX = box1->getWidth();
		//}
		////==========================================================
		//float minY;
		//if ((box1->getHeight() + box1->getPosition().y) > sphere1->getPosition().y)
		//{
		//	minY = box1->getHeight() + box1->getPosition().y;
		//}
		//else
		//{
		//	minY = sphere1->getPosition().y;
		//}
		//float maxY;
		//if (maxY > box1->getHeight())
		//{
		//	maxY = minY;
		//}
		//else
		//{
		//	maxY = box1->getHeight();
		//}

		//float distance = sqrt((maxX - sphere1->getRadius()) * (maxX - sphere1->getRadius()) +
		//	(maxY - sphere1->getPosition().y) * (maxY - sphere1->getPosition().y));

		//if (distance < sphere1->getRadius())
		//{
		//	sphere1->setVelocity(glm::vec2(0, 0));
		//	box1->setVelocity(glm::vec2(0, 0));
		//}


		//=====NEW ATTEMPT=======
		//glm::vec2 distance = sphere1->getPosition() - box1->getPosition();
		/*if (box1->getPosition().x < sphere1->getPosition().x + sphere1->getRadius() &&
			(sphere1->getPosition().x - sphere1->getRadius()) > box1->getPosition().x&&
			box1->getPosition().y < (sphere1->getPosition().y - sphere1->getRadius()) &&
			(sphere1->getPosition().y + sphere1->getRadius()) > box1->getPosition().y)
		{
			sphere1->setVelocity(glm::vec2(0, 0));
			box1->setVelocity(glm::vec2(0, 0));
		}*/


		//Function To Dissassable Box
		//..Top Line
		glm::vec2 collisionNormal = glm::normalize(glm::vec2(0, 10));
		float sphereToPlane = glm::dot(sphere1->getPosition(), glm::normalize(glm::vec2(0, 10))) - box1->getWidth();
		float forceDirection = 1.0f;

		//if we are behind plane then we flip the normal
		if (sphereToPlane < 0)
		{
			collisionNormal *= -1;
			sphereToPlane *= -1;
			forceDirection = -1.0f;
		}

		//intersection
		float intersection = sphere1->getRadius() - sphereToPlane;
		if (intersection > 0)
		{
			sphere1->setVelocity(glm::vec2(0,0));
		}




		/*float sphereToPlaneOfBox = glm::dot(sphere1->getPosition(), box1->getVelocity()) - box1->getPosition().x;

		if (sphereToPlaneOfBox < 0)
		{
			sphereToPlaneOfBox *= -1;
		}


		float intersection = sphere1->getRadius() - sphereToPlaneOfBox;
		
		if (intersection > 0)
		{
			
		}*/
	}
	return false;
}

bool PhysicsScene::box2Box(PhysicsObject* obj1, PhysicsObject* obj2)
{
	//cast to AABB Class
	AABBClass* box1 = dynamic_cast<AABBClass*>(obj1);
	AABBClass* box2 = dynamic_cast<AABBClass*>(obj2);

	//if cast successful
	if (box1, box2)
	{
		if (box1->getPosition().x < box2->getPosition().x + box2->getWidth() &&
			(box1->getPosition().x + box1->getWidth()) > box2->getPosition().x &&
			box1->getPosition().y < (box2->getPosition().y + box2->getHeight()) &&
			(box1->getPosition().y + box1->getHeight()) > box2->getPosition().y)
		{
			box1->setVelocity(glm::vec2(0, 0));
		}
	}

	return false;
}
