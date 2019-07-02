#include "stdafx.h"
#include "Vector2.h"
#include <iostream>

//basic constructor
Vector2::Vector2()
{
	m_x = 1;
	m_y = 1;

}

//setting constructor
Vector2::Vector2(float X, float Y)
{
	m_x = X;
	m_y = Y;

	data[0] = X;
	data[1] = Y;
}


//allows Vector2 to convert to float
Vector2::operator float*() { return data; }
Vector2::operator const float*()
{
	return data;
}
//allows Vector2 to convert to float



//==================OPERATOR(+)======================
Vector2 Vector2::operator+(const Vector2 & other)
{
	return { m_x + other.m_x, m_y + other.m_y };
}
//==================OPERATOR(+)======================


//==================OPERATOR(-)======================
Vector2 Vector2::operator-(const Vector2 & other)
{
	/*m_x -= other.m_x;
	m_y -= other.m_y;
	return *this;*/
	return{ m_x - other.m_x, m_y - other.m_y };
}
//==================OPERATOR(-)======================

//==================OPERATOR(/=)======================
Vector2 Vector2::operator/= (float scalar)
{
	m_x /= scalar;
	m_y /= scalar;
	return *this;
}
//==================OPERATOR(/=)======================

//==================OPERATOR(*)======================
Vector2 Vector2::operator*(float scalar)const
{
	return{ m_x * scalar, m_y * scalar };
}
//==================OPERATOR(*)======================


//==================OPERATOR(*)======================
Vector2 operator*(float scalar, const Vector2 & vec)
{
	return vec * scalar; //for multiplying vector2 with scalar value
}
//==================OPERATOR(*)======================


//==================OPERATOR(=)======================
Vector2 Vector2::operator=(Vector2 & other)
{
	m_x = other.m_x;
	m_y = other.m_y;
	return *this; //returns the new vector2
}
//==================OPERATOR(=)======================


//===========Returns m_X============================
float Vector2::GetX()
{
	return m_x;
}
//===========Returns m_X============================

//===========Returns m_Y============================
float Vector2::GetY()
{
	return m_y;
}
//===========Returns m_Y============================

//============Sets============================
void Vector2::SetX(float x_value)
{
	m_x = x_value;
}
void Vector2::SetY(float y_value)
{
	m_y = y_value;
}
//============Sets============================


//==============DOT multiplication==============
float Vector2::dot(const Vector2 & other) const
{
	//vector2 times vector2 = new vector2
	return m_x * other.m_x + m_y * other.m_y;
}
//==============DOT multiplication==============


//finds square root of the vector2 for magnitude
float Vector2::magnitude() const
{
	return sqrt(m_x*m_x + m_y * m_y);
}
//finds square root of the vector2 for magnitude


//decrease the vector2 by the scale increased through magnitude
void Vector2::normalise()
{
	float mag = sqrt(m_x*m_x + m_y * m_y); //a^2 + b^2 = 2 + 2 = 4 so then this get's squared [PT]
	m_x /= mag;
	m_y /= mag;
}
//decrease the vector2 by the scale increased through magnitude
