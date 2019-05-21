#include "Bar.h"



Bar::Bar(float posX, float posY, float width, float height, string colour)
{
	m_posX = posX;
	m_posY = posY;
	m_width = width;
	m_height = height;
	m_currentValue = 100;
	m_maxValue = 100;
	m_value = colour;
}

Bar::~Bar()
{
}




void Bar::Draw(aie::Renderer2D* renderer, float value_R, float value_G, float value_B)
{
	float ratio = m_currentValue / m_maxValue;
	float full = m_width * ratio;
	float offsetX = m_posX - (m_width - full) * 0.5f;

	//Draw background (Square Behind)
	renderer->setRenderColour(1, 1, 1, 1); //Red, Green and Blue Mix To Make White
	renderer->drawBox(m_posX, m_posY, m_width, m_height);

	//Setting Colours (Square In Front)
	renderer->setRenderColour(value_R, value_G, value_B, 1);
	renderer->drawBox(offsetX, m_posY, full, m_height);
	renderer->setRenderColour(1, 2, 1, 1);
}

//Set Colour Opacity
void Bar::SetValue(float value)
{
	m_currentValue = value;
}
//Set Colour Opacity


void Bar::setRight(Bar * current)
{
	m_right = current; //make the value of m_right = to that class node
}


Bar * Bar::getRight()
{
	return m_right; //return value of m_right ||previously set through m_right =ing to current
}



//Set String Colour
void Bar::setData(string value)
{
	m_value = value;
}
//Set String Colour



//Check String Colour
string Bar::getData()
{
	return m_value;
}
//Check String Colour




//			Default Data
	//renderer->setRenderColour(0, 1, 0, 1);
	//renderer->drawBox(offsetX, m_posY, full, m_height);
	//renderer->setRenderColour(1, 1, 1, 1);
