#include "AABBClass.h"



AABBClass::AABBClass(glm::vec2 a_topLeft, glm::vec2 a_bottomRight) : RigidBodyClass(BOX, m_position, m_velocity, m_rotation, m_mass,1.0f,1.0f,1.0f)
{
}

AABBClass::AABBClass(glm::vec2 position, float a_width, float a_height) : RigidBodyClass(BOX, position, glm::vec2(0,0), 0, 1.f,1.0f,0,1.0f)
{
	m_width = a_width;
	m_height = a_height;
}

AABBClass::~AABBClass()
{
}

void AABBClass::makeGizmo()
{
	glm::vec4 m_colour(1, 0, 0, 1);
	/*glm::vec4 colour(1, 0, 0, 1);
	aie::Gizmos::add2DAABB(m_position, glm::vec2(m_width, m_height), colour);*/

	// draw using local axes
	glm::vec2 p1 = m_position - m_localX * m_width - m_localY * m_height;
	glm::vec2 p2 = m_position + m_localX * m_width - m_localY * m_height;
	glm::vec2 p3 = m_position - m_localX * m_width + m_localY * m_height;
	glm::vec2 p4 = m_position + m_localX * m_width + m_localY * m_height;
	aie::Gizmos::add2DTri(p1, p2, p4, m_colour);
	aie::Gizmos::add2DTri(p1, p2, p3, m_colour);
}

void AABBClass::fixedUpdate(glm::vec2 gravity, float timeStep)
{
	RigidBodyClass::fixedUpdate(gravity, timeStep);

	//store the local axes
	float cs = cosf(m_rotation);
	float sn = sinf(m_rotation);
	m_localX = glm::normalize(glm::vec2(cs, sn));
	m_localY = glm::normalize(glm::vec2(-sn, cs));
}

bool AABBClass::checkCollision(PhysicsObject* pOther)
{
	return false;
}

