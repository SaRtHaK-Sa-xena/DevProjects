#include "SphereClass.h"

SphereClass::SphereClass(glm::vec2 position, glm::vec2 velocity, float mass, float radius, glm::vec4 colour) : RigidBodyClass(SPHERE, position, velocity, 0, mass)
{
	m_radius = radius;
	m_colour = colour;
}

SphereClass::SphereClass(glm::vec2 position, float angle, float speed, float mass, float radius, glm::vec4 colour) : RigidBodyClass(SPHERE, position, speed, angle, 0, mass)
{
	m_velocity.x = speed * cos(angle);
	m_velocity.y = speed * sin(angle);

	m_radius = radius;
	m_colour = colour;
}

SphereClass::~SphereClass()
{
}

void SphereClass::makeGizmo()
{
	aie::Gizmos::add2DCircle(m_position, m_radius, 17, m_colour);
}

bool SphereClass::checkCollision(PhysicsObject* pOther)
{
	SphereClass* Dcast = dynamic_cast<SphereClass*>(pOther);
	if (Dcast)
	{
		//start collision check
		
		//store vec2 of the difference in distance
		glm::vec2 difference = Dcast->getPosition() - m_position;

		//find magnitude
		float mag = sqrt(difference.x * difference.x + difference.y * difference.y);

		//find it in 
		if (mag < (Dcast->getRadius() + m_radius))
		{
			//turned off for rocket Exercise
			return false;
		}
		else
		{
			return false;
		}
	}
	else
	{
		//return false
		return false;
	}
}
