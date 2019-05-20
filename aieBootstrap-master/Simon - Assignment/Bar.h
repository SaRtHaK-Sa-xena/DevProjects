#pragma once
#include "Renderer2D.h"

class Bar
{
public:
	Bar(float posX, float posY, float width, float height);
	~Bar();

	void Draw(aie::Renderer2D * renderer);
	void SetValue(float value);
	void SetColourValue(float R, float G, float B, aie::Renderer2D *renderer);


	void SetRight(Bar *current)
	{
		m_right = current;
	}

	void setData(string value)
	{
		m_name = value;
	}

	Bar *getRight()
	{
		return m_right;
	}

	string getData()
	{
		return m_name;
	}

//The bar's position, width, and height
float m_posX;
float m_posY;
float m_width;
float m_height;
//The bar's current and maximum value
float m_currentValue;
float m_maxValue;

private:
	string m_name;
	Bar *m_right = nullptr;

};


