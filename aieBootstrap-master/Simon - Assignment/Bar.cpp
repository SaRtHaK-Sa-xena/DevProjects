#include "Bar.h"



Bar::Bar(float posX, float posY, float width, float height)
{
	m_posX = posX;
	m_posY = posY;
	m_width = width;
	m_height = height;
	m_currentValue = 100;
	m_maxValue = 100;
}
Bar::~Bar()
{
}


void Bar::Draw(aie::Renderer2D* renderer)
{
	float ratio = m_currentValue / m_maxValue;
	float full = m_width * ratio;
	float offsetX = m_posX - (m_width - full) * 0.5f;

	//Draw background
	renderer->setRenderColour(1, 0, 0, 1);
	renderer->drawBox(m_posX, m_posY, m_width, m_height);


	renderer->setRenderColour(0, 1, 0, 1);
	renderer->drawBox(offsetX, m_posY, full, m_height);
	renderer->setRenderColour(1, 2, 1, 1);
}
void Bar::SetValue(float value)
{
	m_currentValue = value;
}
	//renderer->setRenderColour(0, 1, 0, 1);
	//renderer->drawBox(offsetX, m_posY, full, m_height);
	//renderer->setRenderColour(1, 1, 1, 1);
