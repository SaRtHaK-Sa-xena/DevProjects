#include "AABBClass.h"



AABBClass::AABBClass(glm::vec2 a_topLeft, glm::vec2 a_bottomRight) : RigidBodyClass(BOX, m_position, m_velocity, m_rotation, m_mass)
{
}

AABBClass::AABBClass(glm::vec2 position, float a_width, float a_height) : RigidBodyClass(BOX, position, glm::vec2(0,0), 1.f, 1.f)
{
	m_width = a_width;
	m_height = a_height;
}

AABBClass::~AABBClass()
{
}

void AABBClass::makeGizmo()
{
	glm::vec4 colour(1, 0, 0, 1);
	aie::Gizmos::add2DAABB(m_position, glm::vec2(m_width, m_height), colour);
}

bool AABBClass::checkCollision(PhysicsObject* pOther)
{
	return false;
}

