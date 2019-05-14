#pragma once
#include "Renderer2D.h"

class Square
{
public:

	Square(float posX, float posY, float width, float height);
	~Square();

	void Draw(aie::Renderer2D* renderer);
	void SetValue(float value);

	//The square's position, width, and height
	float m_posX;
	float m_posY;
	float m_width;
	float m_height;
	//Thesquare's current and maximum value
	float m_currentValue;
	float m_maxValue;
};
