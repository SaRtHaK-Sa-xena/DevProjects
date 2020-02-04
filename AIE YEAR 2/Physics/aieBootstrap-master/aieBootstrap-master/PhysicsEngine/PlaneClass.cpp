#include "PlaneClass.h"

PlaneClass::~PlaneClass()
{
}

void PlaneClass::fixedUpdate(glm::vec2 gravity, float timeStep)
{
}

void PlaneClass::makeGizmo()
{
	float lineSegmentLength = 300;
	glm::vec2 centrePoint = m_normal * m_distanceToOrigin;
	
	//easy to rotate normal through 90 degrees around z
	glm::vec2 parallel(m_normal.y, -m_normal.x);
	glm::vec4 colour(1, 1, 1, 1);
	glm::vec2 start = centrePoint + (parallel * lineSegmentLength);
	glm::vec2 end = centrePoint - (parallel * lineSegmentLength);
	aie::Gizmos::add2DLine(start, end, colour);

}

void PlaneClass::resetPosition()
{
}
