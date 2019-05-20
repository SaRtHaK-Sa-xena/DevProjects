#include "Square.h"



Square::Square(float posX, float posY, float width, float height)
{
	m_posX = posX;
	m_posY = posY;
	m_width = width;
	m_height = height;
	m_currentValue = 100;
	m_maxValue = 100;
}
Square::~Square()
{
}
/*renderer->setRenderColour(0.80, 1, 0, 1);*/ // <--- YELLOW


void Square::SetArray()
{

}

void Square::Draw(aie::Renderer2D* renderer)
{
	float ratio = m_currentValue / m_maxValue;
	float full = m_width * ratio;
	float offsetX = m_posX - (m_width - full) * 0.5f;

	//Draw background
	renderer->setRenderColour(1, 1, 1, 1);
	renderer->drawBox(m_posX, m_posY, m_width, m_height);


	renderer->setRenderColour(0, 0, 0, 0);
	renderer->drawBox(offsetX, m_posY, full, m_height);
	renderer->setRenderColour(0, 0, 0, 1);
}
void Square::SetValue(float value)
{
	m_currentValue = value;
}
void Square::SetColourValue(float value, float value2, float value3, aie::Renderer2D *renderer)
{
	float ratio = m_currentValue / m_maxValue;
	float full = m_width * ratio;
	float offsetX = m_posX - (m_width - full) * 0.5f;

	renderer->setRenderColour(value, value2, value3, 1);
	renderer->drawBox(offsetX, m_posY, full, m_height);
	renderer->setRenderColour(1, 1, 1, 1);
}
//renderer->setRenderColour(0, 1, 0, 1);
//renderer->drawBox(offsetX, m_posY, full, m_height);
//renderer->setRenderColour(1, 1, 1, 1);