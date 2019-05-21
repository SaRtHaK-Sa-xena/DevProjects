#pragma once
#include "Renderer2D.h"
#include <string>
using namespace std;

class Bar
{
public:
	Bar(float posX, float posY, float width, float height, string colour);
	~Bar();

	//Draws with Renderer, colour R, colour G, colour B
	void Draw(aie::Renderer2D * renderer, float value_R, float value_G, float value_B);
	//Default Colours

	//Changes Colour To White
	void SetValue(float value);
	//changes Colour to White(-1 = White || 100 = Original)


	//To Set Values
	void setRight(Bar*	current);


	//To Check Values
	Bar* getRight();

	void setData(string value);

	string getData();
	//{
	//}

//The bar's position, width, and height
float m_posX;
float m_posY;
float m_width;
float m_height;
//The bar's current and maximum value
float m_currentValue;
float m_maxValue;

private:
	//storage
	Bar *m_right = nullptr;
	string m_value;

};


