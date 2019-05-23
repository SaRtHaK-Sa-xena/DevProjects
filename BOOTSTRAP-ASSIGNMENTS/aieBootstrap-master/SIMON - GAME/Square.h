
#pragma once
#include "Renderer2D.h"
#include <string>

using namespace std;

class Square
{
public:
	Square(float posX, float posY, float width, float height, string colour);
	~Square();

	void Draw(aie::Renderer2D* renderer);
	void SetValue(float value);

	void setRight(Square* current);
	Square *getRight();

	void setData(string value);
	string getData();
	//void SetArray();

	void SetColourValue(float value, float value2, float value3, aie::Renderer2D* renderer);

	//The bar's position, width, and height
	float m_posX;
	float m_posY;
	float m_width;
	float m_height;
	//The bar's current and maximum value
	float m_currentValue;
	float m_maxValue;

private:
	Square* m_right = nullptr;
	string m_value;

};
