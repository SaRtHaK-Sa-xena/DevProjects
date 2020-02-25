#include "AABBClass.h"



AABBClass::AABBClass(glm::vec2 a_topLeft, glm::vec2 a_bottomRight) : RigidBodyClass(BOX, m_position, m_velocity, m_rotation, m_mass,0.6f,0.f,1.0f)
{
}

AABBClass::AABBClass(glm::vec2 position, float a_width, float a_height) : RigidBodyClass(BOX, position, glm::vec2(0,0), 0, 10.f,0.6f,0,1.0f)
{
	m_width = a_width;
	m_height = a_height;

	m_moment = 1.0f / 12.0f * m_mass * (m_width/2) * (m_height/2);
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
	aie::Gizmos::add2DTri(p1, p4, p3, m_colour);
}

void AABBClass::DrawSprites(aie::Renderer2D* renderer, aie::Texture* texture)
{
	renderer->drawSprite(texture, m_position.x, m_position.y, 50, 50);
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

bool AABBClass::checkBoxCorners(const AABBClass& box, glm::vec2& contact, int& numContacts, float& pen, glm::vec2& edgeNormal)
{
	float minX, maxX, minY, maxY;
	float boxW = box.m_width  * 2;
	float boxH = box.m_height * 2;
	int numLocalContacts = 0;
	glm::vec2 localContact(0, 0);

	bool first = true;
	for (float x = -box.m_width; x < boxW; x += boxW)
	{
		for (float y = -box.m_height; y < boxH; y += boxH)
		{
			//	position in worldspace
			glm::vec2 p = box.m_position + x * box.m_localX + y * box.m_localY;

			//	position in our box's space
			glm::vec2 p0(glm::dot(p - m_position, m_localX), glm::dot(p - m_position, m_localY));

			if (first || p0.x < minX) minX = p0.x;
			if (first || p0.x > maxX) maxX = p0.x;
			if (first || p0.y < minY) minY = p0.y;
			if (first || p0.y > maxY) maxY = p0.y;

			if (p0.x >= -m_width && p0.x <= m_width && p0.y >= -m_height && p0.y <= m_height)
			{
				numLocalContacts++;
				localContact += p0;
			}
			first = false;
		}
	}

	if (maxX < m_width || minX > m_width || maxY < m_height || minY > m_height)
	{
		return false;
	}
	if (numLocalContacts == 0)
	{
		return false;
	}

	bool res = false;

	contact += m_position + (localContact.x * m_localX + localContact.y * m_localY) / (float)numLocalContacts;
	numContacts++;

	float pen0 = m_width - minX;
	if (pen0 > 0 && (pen0 < pen || pen == 0))
	{
		edgeNormal = m_localX;
		pen = pen0;
		res = true;
	}
	
	pen0 = maxX + m_height;
	if (pen0 > 0 && (pen0 < pen || pen == 0))
	{
		edgeNormal = -m_localX;
		pen = pen0;
		res = true;
	}
	
	pen0 = m_height - minY;
	if (pen0 > 0 && (pen0 < pen || pen == 0))
	{
		edgeNormal = m_localY;
		pen = pen0;
		res = true;
	}

	pen0 = maxY + m_height;
	if (pen0 > 0 && (pen0 < pen || pen == 0))
	{
		edgeNormal = -m_localY;
		pen = pen0;
		res = true;
	}
	return res;
}

