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


PhysicsScene::PhysicsScene():m_timeStep(0.01f), m_gravity(glm::vec2(0,0))
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
	//	iterate through vector of actors
	for (int i = 0; i < m_actors.size(); i++)
	{
		//	if the actor matches the current index vector
		//	in the vector of actors
		if (actor == m_actors[i])
		{
			//start swapping to move the one to remove at the end
			// temp equals last index in array
			PhysicsObject* temp_actor = m_actors[m_actors.size()-1];

			//make last index actor equal to the designated actor to remove
			m_actors[m_actors.size()-1] = actor;
			
			//then make the last position stored equal to the current index 
			m_actors[i] = temp_actor;

			//then remove the last index
			m_actors.pop_back();
			
			//then delete
			delete actor;
			break;
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
	//doesn't move..
	//static object's don't collide
	return false;
}

bool PhysicsScene::plane2Sphere(PhysicsObject*obj1, PhysicsObject*obj2)
{
	PlaneClass* plane = dynamic_cast<PlaneClass*>(obj1);
	SphereClass* sphere = dynamic_cast<SphereClass*>(obj2);
	
	if (plane != NULL && sphere != NULL)
	{
		return sphere2Plane(sphere, plane);
	}
}

bool PhysicsScene::plane2Box(PhysicsObject* obj1, PhysicsObject* obj2)
{
	PlaneClass* plane = dynamic_cast<PlaneClass*>(obj1);
	AABBClass* box = dynamic_cast<AABBClass*>(obj2);

	if (plane != NULL && box != NULL)
	{
		return box2Plane(box, plane);
	}
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
			if (sphere->isThisStriker())
			{
				sphere->resetFoulPieces(true);
				//sphere->setStreak(true);
			}

			glm::vec2 contact = sphere->getPosition() + (collisionNormal * -sphere->getRadius());
			
			sphere->setPosition(collisionNormal * intersection);
			
			plane->resolveCollision(sphere, contact);
			
			return true;

			//Keep Sphere above Plane
			//sphere->movePosition(intersection * collisionNormal);

			//Apply Force Upwards
			//glm::vec2 appliedForce = collisionNormal * glm::length(sphere->getVelocity()) * forceDirection;
			//sphere->applyForce(appliedForce * 0.7f);
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
		
		glm::vec2 delta = sphere2->getPosition() - sphere1->getPosition();
		float distance = glm::length(delta);
		float intersection = sphere1->getRadius() + sphere2->getRadius() - distance;

		if (intersection > 0)
		{
			glm::vec2 contactForce = 0.5f*(distance - (sphere1->getRadius() + sphere2->getRadius())) * delta / distance;

			// checks if the striker is hitting anything that isn't foul

			//	checks if sphere can be placed to be aimed 
			//	when not on any coins
			
			//	if it is the striker and the player is in start turn
			if (sphere1->isThisStriker() && sphere1->isitStartTurn())
			{
				//	can't be placed or aimed
				sphere1->setPlaceable(false);
				
				// set colour to red
			}
			if (sphere2->isThisStriker() && sphere2->isitStartTurn())
			{
				//can't be placed or aimed
				sphere2->setPlaceable(false);

				// set colour to red
			}


			//Doesn't let Striker collide with the coins on the play area
			// Lets Striker Collide with coins after the Striker has been hit
			if (sphere1->ifCollidable() == false || sphere2->ifCollidable() == false)
			{
				//don't set collision resolution
				// Or the force added afterwards
				return false;
			}
			
			//	checks if collided with a foul piece
			//	if collided with foul piece rewind it to previous status
			if (sphere1->isFoul() && sphere2->isThisStriker() || sphere2->isFoul() && sphere1->isThisStriker())
			{
				//reset their positions and velocity
				sphere1->rewindTime();
				sphere1->setVelocity(glm::vec2(0,0));
				sphere2->rewindTime();
				sphere2->setVelocity(glm::vec2(0,0));
				
				//	Turn Streak On 
				//	To Maintain Player x's turn
				if (sphere1->isThisStriker())
				{
					sphere1->setStreak(true);
					/*if (sphere1->returnPlayerTurn())
					{
						sphere1->setPlayerTurn(true);
					}
					else
					{
						sphere1->setPlayerTurn(false);
					}*/
				}
				if (sphere2->isThisStriker())
				{
					sphere2->setStreak(true);
					/*if (sphere2->returnPlayerTurn())
					{
						sphere2->setPlayerTurn(true);
					}
					else
					{
						sphere2->setPlayerTurn(false);
					}*/
				}
				return true;
			}
			else
			{
				if (sphere1->isThisStriker() && !sphere2->isFoul())
				{
					// Let Striker Hold Condition To Reset Foul
					sphere1->resetFoulPieces(true);
					sphere1->setStreak(false);
					//sphere1->setPlayerTurn(false);
				}


				if (sphere2->isThisStriker() && !sphere1->isFoul())
				{
					// Let Striker Hold Condition To Reset Foul
					sphere2->resetFoulPieces(true);
					sphere2->setStreak(false);
					//sphere2->setPlayerTurn(true);
				}
			}


			sphere1->setPosition(contactForce);
			sphere2->setPosition(-contactForce);

			//respond to the collision
			sphere1->resolveCollision(sphere2, 0.5f * (sphere1->getPosition() + sphere2->getPosition()));
			return true;
		}
		
		//when not colliding set placeable on play area to true
		else
		{
			if (sphere1->isThisStriker() && sphere1->isitStartTurn())
			{
				//	can't be placed or aimed
				sphere1->setPlaceable(true);
			}
			if (sphere2->isThisStriker() && sphere2->isitStartTurn())
			{
				//can't be placed or aimed
				sphere2->setPlaceable(true);
			}
		}
		
		
		//collison detection
		//glm::vec2 difference = sphere1->getPosition() - sphere2->getPosition();

		//float gradient = sqrt(difference.x * difference.x + difference.y * difference.y);

		////// if overlapping
		//if (gradient < (sphere1->getRadius() + sphere2->getRadius()))
		//{
		//	// set the velocity of the two spheres to zero
		//	//sphere1->setVelocity(glm::vec2(0, 0));
		//	//sphere2->setVelocity(glm::vec2(0, 0));


		//	// works somewhat
		//	//glm::vec2 normalizeSphere1 = glm::normalize(sphere1->getVelocity());
		//	//glm::vec2 normalizeSphere2 = glm::normalize(sphere2->getVelocity());
		//	//sphere1->movePosition(normalizeSphere1 * (gradient/2));
		//	//sphere2->movePosition(normalizeSphere2* (gradient / 2));
		//	//sphere1->applyForceToActor(sphere2, sphere1->getVelocity() * 0.1f);
		//	
		//	glm::vec2 contact = sphere1->getPosition() + sphere2->getPosition();

		//	sphere1->setPosition(sphere1->getPosition() + contact);
		//	sphere2->setPosition(sphere2->getPosition() - contact);

		//	sphere1->resolveCollision(sphere2, 0.5f * contact);
		//}
	}
	return false;
}

bool PhysicsScene::sphere2Box(PhysicsObject* obj1, PhysicsObject* obj2)
{
	SphereClass* sphere = dynamic_cast<SphereClass*>(obj1);
	AABBClass* box = dynamic_cast<AABBClass*>(obj2);

	//if valid
	if (sphere != NULL && box != NULL)
	{
		return box2Sphere(box, sphere);
	}
}

bool PhysicsScene::box2Plane(PhysicsObject* obj1, PhysicsObject* obj2)
{
	AABBClass* box = dynamic_cast<AABBClass*>(obj1);
	PlaneClass* plane = dynamic_cast<PlaneClass*>(obj2);

	if (box != NULL && plane != NULL)
	{
		int numContacts = 0;
		glm::vec2 contact(0, 0);
		float contactV = 0;
		float radius = 0.5f * std::fminf(box->getWidth(), box->getHeight());
		float penetration = 0;

		// which side is the centre of mass on?
		glm::vec2 planeOrigin = plane->getNormal() * plane->getDistance();
		float comFromPlane = glm::dot(box->getPosition() - planeOrigin, plane->getNormal());

		// check all four corners to see if we've hit the plane
		for (float x = -box->getWidth()/2; x < box->getWidth(); x += box->getWidth())
		{
			for (float y = -box->getHeight()/2; y < box->getHeight(); y += box->getHeight())
			{
				// get the position of the corner in world space
				glm::vec2 p = box->getPosition() + x * box->getLocalX() + y * box->getLocalY();

				float distFromPlane = glm::dot(p - planeOrigin, plane->getNormal());

				// this is the total velocity of the point
				float velocityIntoPlane = glm::dot(box->getVelocity() + box->getAngularVelocity() * (-y * box->getLocalX() + x * box->getLocalY()), plane->getNormal());

				// if this corner is on the opposite side from the Center Of Mass,
				// and moving further in, resolve the collision
				if ((distFromPlane > 0 && comFromPlane < 0 && velocityIntoPlane >= 0) || (distFromPlane < 0 && comFromPlane > 0 && velocityIntoPlane <= 0))
				{
					numContacts++;
					contact += p;
					contactV += velocityIntoPlane;
				}
				if (comFromPlane >= 0)
				{
					if (penetration > distFromPlane)
					{
						penetration = distFromPlane;
					}
					else
					{
						if (penetration < distFromPlane)
						{
							penetration = distFromPlane;
						}
					}
				}
			}
		}

		// after this we have a hit
		// typically only two corners hit...
		if (numContacts > 0)
		{
			// get the average collision velocity into the plane
			// (covers linear and rotational velocity of all corners involved)
			float collisionV = contactV / (float)numContacts;

			// get the acceleration required to stop (restitution = 0) or reverse 
			// (restitution = 1) the average velocity into the plane
			glm::vec2 acceleration = -plane->getNormal() * ((1.f + box->getElasticity()) * collisionV);

			// and the average position at which we'll apply the force 
			// (corner or edge centre)
			glm::vec2 localContact = (contact / (float)numContacts) - box->getPosition();

			// this is the perpendicular distance we apply the force at relative to
			// the Centre Of Mass, so Torque = F*r
			float r = glm::dot(localContact, glm::vec2(plane->getNormal().y, -plane->getNormal().x));

			// work out the "effective mass" - this is a combination of moment of 
			// inertia and mass, and tells us how much the contact point velocity
			// will change with the force we're applying
			float mass0 = 1.f / (1.f / box->getMass() + (r * r) / box->getMoment());

			// and apply the force
			box->applyForce(acceleration * mass0, localContact);

			box->setPosition(box->getPosition() - plane->getNormal() * penetration);
		}

		////create vector
		////glm::vec2 vectorToPlane = plane->getNormal() * box->getPosition();
		//glm::vec2 vectorToPlane = plane->getNormal() * box->getPosition() - plane->getDistance();
		//glm::vec2 boxPoint;

		////for x-AXIS
		//if (vectorToPlane.x < -box->getHeight())
		//{
		//	//set it to the left side
		//	boxPoint.x = -box->getWidth();
		//}
		//else if (vectorToPlane.x > box->getWidth())
		//{
		//	//set it to the right side
		//	boxPoint.x = box->getWidth();
		//}
		//else
		//{
		//	//set it to the vector.x
		//	boxPoint.x = vectorToPlane.x;
		//}

		////Setting the y-AXIS
		//if (vectorToPlane.y < -box->getHeight())
		//{
		//	//set it to the bottom
		//	boxPoint.y = -box->getHeight();
		//}
		//else if (vectorToPlane.y > box->getHeight())
		//{
		//	//set it to the top
		//	boxPoint.y = box->getHeight();
		//}
		//else
		//{
		//	//set it to the vector.y
		//	boxPoint.y = vectorToPlane.y;
		//}

		////seperate line, check if line advances past 
		//glm::vec2 collisionNormal = plane->getNormal();
		//float boxToPlane = glm::dot(boxPoint, plane->getNormal()) - plane->getDistance();
		//float forceDirection = 1.0f;

		////if we are behind plane then we flip the normal
		//if (boxToPlane < 0)
		//{
		//	collisionNormal *= -1;
		//	boxToPlane *= -1;
		//	forceDirection = -1.0f;

		//	//collision has occured
		//	//box->setVelocity(glm::vec2(0, 0));
		//}
		////intersection
		//float intersection = box->getHeight() - boxToPlane;
		//if (intersection < 0)
		//{
		//	box->setVelocity(glm::vec2(0, 0));
		//}
	}

	return false;
}

bool PhysicsScene::box2Sphere(PhysicsObject*obj1, PhysicsObject*obj2)
{
	AABBClass* box = dynamic_cast<AABBClass*>(obj1);
	SphereClass* sphere = dynamic_cast<SphereClass*>(obj2);

	//if valid
	if (sphere != NULL && box != NULL)
	{
		#pragma region Tutorial Example

		glm::vec2 circlePos = sphere->getPosition() - box->getPosition();
		float w2 = box->getWidth(), h2 = box->getHeight();

		int numContacts = 0;
		glm::vec2 contact(0, 0); // contact is in our box coordinates

		//check the four corners to see if ay of them are inside the circle
		for (float x = -w2; x <= w2; x += box->getWidth())
		{
			for (float y = -h2; y < h2; y += box->getHeight())
			{
				glm::vec2 p = x * box->getLocalX() + y * box->getLocalY();
				glm::vec2 dp = p - circlePos;
				if (dp.x * dp.x + dp.y * dp.y < sphere->getRadius() * sphere->getRadius())
				{
					numContacts++;
					contact += glm::vec2(x, y);
				}
			}
		}

		glm::vec2* direction = nullptr;
		//	get the local position of the circle center
		glm::vec2 localPos(glm::dot(box->getLocalX(), circlePos), glm::dot(box->getLocalY(), circlePos));

		if (localPos.y < h2 && localPos.y > -h2)
		{
			if (localPos.x > 0 && localPos.x < w2 + sphere->getRadius())
			{
				numContacts++;
				contact += glm::vec2(w2, localPos.y);
				direction = new glm::vec2(box->getLocalX());
			}
			if (localPos.x < 0 && localPos.x > -(w2 + sphere->getRadius()))
			{
				numContacts++;
				contact += glm::vec2(-w2, localPos.y);
				direction = new glm::vec2(-box->getLocalX());
			}
		}
		if (localPos.x < w2 && localPos.x > -w2)
		{
			if (localPos.y > 0 && localPos.y < h2 + sphere->getRadius())
			{
				numContacts++;
				contact += glm::vec2(localPos.x, h2);
				direction = new glm::vec2(box->getLocalY());
			}
			if(localPos.y < 0 && localPos.y > -(h2 + sphere->getRadius()))
			{
				numContacts++;
				contact += glm::vec2(localPos.x, -h2);
				direction = new glm::vec2(-box->getLocalY());
			}
		}

		if (numContacts > 0)
		{
			//	average, and convert back into world coordinates
			contact = box->getPosition() + (1.f / numContacts) * (box->getLocalX() * contact.x + box->getLocalY() * contact.y);

			//	given the contact point we can find a penetration amount and normal
			float pen = sphere->getRadius() - glm::length(contact - sphere->getPosition());
			glm::vec2 norm = glm::normalize(sphere->getPosition() - contact);

			glm::vec2 penVec = glm::normalize(contact - sphere->getPosition() * pen);
			
			//when does sphere need to bounce back?
			//When hit kinematic box
			//so if box->isKinematic(apply contact force, and resolve collision)
			if (box->isKinematic())
			{
				if (sphere->isThisStriker())
				{
					sphere->resetFoulPieces(true);
					sphere->setStreak(false);
				}

				//sphere->setPosition(-penVec);
				//PhysicsScene *classCall = new PhysicsScene();
				ApplyContactForces(box, sphere, norm, pen);
				box->resolveCollision(sphere, contact, direction);

			}
			
			//When does sphere need to travel through
			//When over hole
			//so if box->isNotKinematic, don't apply contact force, and don't resolve collision
			else
			{
				sphere->incrementTimeStored();
			}
		}
		delete direction;
		
		#pragma endregion Tutorial Example


		#pragma region AABB Implementation

		////create vector from box to sphere
		//glm::vec2 vectorToSphere(sphere->getPosition() - box->getPosition());
		//
		////closest point on the box
		//glm::vec2 boxPoint;

		////Setting the x-AXIS
		//if (vectorToSphere.x < -box->getHeight())
		//{
		//	//set it to the left side
		//	boxPoint.x = -box->getWidth();
		//}
		//else if (vectorToSphere.x > box->getWidth())
		//{
		//	//set it to the right side
		//	boxPoint.x = box->getWidth();
		//}
		//else
		//{
		//	//set it to the vector.x
		//	boxPoint.x = vectorToSphere.x;
		//}

		////Setting the y-AXIS
		//if (vectorToSphere.y < -box->getHeight())
		//{
		//	//set it to the bottom
		//	boxPoint.y = -box->getHeight();
		//}
		//else if (vectorToSphere.y > box->getHeight())
		//{
		//	//set it to the top
		//	boxPoint.y = box->getHeight();
		//}
		//else
		//{
		//	//set it to the vector.y
		//	boxPoint.y = vectorToSphere.y;
		//}

		////Now we should have the closest point on the box
		////check if distance from that point to the sphere center less than the radius
		//glm::vec2 distance = vectorToSphere - boxPoint;
		//
		////check if collision
		//if (distance.x * distance.x + distance.y * distance.y < sphere->getRadius() * sphere->getRadius())
		//{
		//	//set velocity of sphere to zero
		//	//sphere->setVelocity(glm::vec2(0,0));
		//	//when does sphere need to bounce back?
		//	//When hit kinematic box
		//	//so if box->isKinematic(apply contact force, and resolve collision)
		//	if (box->isKinematic())
		//	{
		//		if (sphere->isThisStriker())
		//		{
		//			sphere->resetFoulPieces(true);
		//			sphere->setStreak(false);
		//		}
		//		box->resolveCollision(sphere, distance);
		//	}
		//	
		//	//When does sphere need to travel through
		//	//When over hole
		//	//so if box->isNotKinematic, don't apply contact force, and don't resolve collision
		//	else
		//	{
		//		sphere->incrementTimeStored();
		//	}
		//}

		#pragma endregion AABB Implementation

	}
	return false;
}

bool PhysicsScene::box2Box(PhysicsObject* obj1, PhysicsObject* obj2)
{
	//cast to AABB Class
	AABBClass* box1 = dynamic_cast<AABBClass*>(obj1);
	AABBClass* box2 = dynamic_cast<AABBClass*>(obj2);

	//if cast successful
	if (box1 != NULL && box2 != NULL)
	{
		/*if (box1->getPosition().x < box2->getPosition().x + box2->getWidth() &&
			(box1->getPosition().x + box1->getWidth()) > box2->getPosition().x &&
			box1->getPosition().y < (box2->getPosition().y + box2->getHeight()) &&
			(box1->getPosition().y + box1->getHeight()) > box2->getPosition().y)
		{
			box1->setVelocity(glm::vec2(0, 0));
		}*/
		glm::vec2 boxPos = box2->getPosition() - box1->getPosition();

		glm::vec2 norm(0, 0);
		glm::vec2 contact(0, 0);
		float pen = 0;
		int numContacts = 0;

		box1->checkBoxCorners(*box2, contact, numContacts, pen, norm);

		if (box2->checkBoxCorners(*box1, contact, numContacts, pen, norm))
		{
			norm = -norm;
		}
		if (pen > 0)
		{
			box1->resolveCollision(box2, contact / float(numContacts), &norm);

			PhysicsScene *classCall = new PhysicsScene();
			classCall->ApplyContactForces(box1, box2, norm, pen);
		}
		return true;
	}

	return false;
}

void PhysicsScene::ApplyContactForces(RigidBodyClass* body1, RigidBodyClass* body2, glm::vec2 norm, float pen)
{
	float body1Factor = body1->isKinematic() ? 0 : (body2->isKinematic() ? 1.0f : 0.5f);

	body1->setPosition(-body1Factor * norm * pen);
	body2->setPosition((1 - body1Factor) * norm * pen);
}
