#include "Square.h"



Square::Square(float posX, float posY, float width, float height, string colour)
{
	m_posX = posX;
	m_posY = posY;
	m_width = width;
	m_height = height;
	m_currentValue = 100;
	m_maxValue = 100;
	m_value = colour;
}


Square::~Square()
{
}
/*renderer->setRenderColour(0.80, 1, 0, 1);*/ // <--- YELLOW


//void Square::SetArray()
//{
//	
//}

void Square::Draw(aie::Renderer2D* renderer, float value_R, float value_G, float value_B)
{
	float ratio = m_currentValue / m_maxValue;
	float full = m_width * ratio;
	float offsetX = m_posX - (m_width - full) * 0.5f;

	//Draw background (Square Behind)
	renderer->setRenderColour(1, 1, 1, 1); //Red, Green and Blue Mix to Make White
	renderer->drawBox(m_posX, m_posY, m_width, m_height);

	//Setting Colours (Square In Front)
	renderer->setRenderColour(value_R, value_G, value_B, 1);
	renderer->drawBox(offsetX, m_posY, full, m_height);
	renderer->setRenderColour(1, 2, 1, 1);
}

//Set Colour Opacity
void Square::SetValue(float value)
{
	m_currentValue = value;
}
//Set Colour Opacity


void Square::setRight(Square* current)
{
	m_right = current; //make the value of m_right = to that class node
}

Square *Square::getRight()
{
	return m_right; //return value of m_right ||previously set through m_right =ing to current
}

//Set String Colour
void Square::setData(string value)
{
	m_value = value;
}
//Set String Colour


//Check String Colour
string Square::getData()
{
	return m_value;
}
//Check String Colour


void Square::SetColourValue(float value, float value2, float value3, aie::Renderer2D *renderer)
{
	float ratio = m_currentValue / m_maxValue;
	float full = m_width * ratio;
	float offsetX = m_posX - (m_width - full) * 0.5f;

	renderer->setRenderColour(value, value2, value3, 1);
	renderer->drawBox(offsetX, m_posY, full, m_height);
	renderer->setRenderColour(1, 1, 1, 1);
}



//				 Default Data
//renderer->setRenderColour(0, 1, 0, 1);
//renderer->drawBox(offsetX, m_posY, full, m_height);
//renderer->setRenderColour(1, 1, 1, 1);


