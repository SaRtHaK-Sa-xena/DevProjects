#include "AABBClass.h"



AABBClass::~AABBClass()
{
}

void AABBClass::makeGizmo()
{
	glm::vec4 colour(1, 0, 0, 1);
	aie::Gizmos::add2DAABB(glm::vec2(m_position.x, m_position.y), glm::vec2(m_width, m_height), colour);
}

