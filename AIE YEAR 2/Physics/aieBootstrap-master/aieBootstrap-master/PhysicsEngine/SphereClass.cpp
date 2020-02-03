#include "SphereClass.h"

SphereClass::SphereClass(glm::vec2 position, glm::vec2 velocity, float mass, float radius, glm::vec4 colour) : RigidBodyClass(SPHERE, position, velocity, 0, mass)
{
	m_radius = radius;
	m_colour = colour;
}

bool SphereClass::checkCollision(PhysicsObject* pOther)
{

	SphereClass* Dcast = dynamic_cast<SphereClass*>(pOther);
	if (Dcast)
	{
		//start collision check
		
		//store vec2 of the differenc in distance
		glm::vec2 difference = Dcast->getPosition() - m_position;

		//(x,y) divide to find the gradient in float value
		double gradient = sqrt(difference.x * difference.x + difference.y * difference.y) / 2;

		//find it in 
		if (gradient < (Dcast->getRadius() + m_radius))
		{
			return true;
		}
	}
	else
	{
		//return false
		return false;
	}
}
