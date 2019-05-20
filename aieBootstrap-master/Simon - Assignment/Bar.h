#pragma once
#include "Renderer2D.h"

class Bar
{
public:
	Bar(float posX, float posY, float width, float height);
	~Bar();

	void Draw(aie::Renderer2D * renderer);
	void SetValue(float value);

//The bar's position, width, and height
float m_posX;
float m_posY;
float m_width;
float m_height;
//The bar's current and maximum value
float m_currentValue;
float m_maxValue;


};


