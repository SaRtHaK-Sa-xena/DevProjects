#include "stdafx.h"
#include "Vector4.h"
#include <iostream>

using namespace std;

//basic constructor
Vector4::Vector4()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
	m_w = 0;

	data[0] = m_x;
	data[1] = m_y;
	data[2] = m_z;
	data[3] = m_w;

}


//setting constructor
Vector4::Vector4(float X, float Y, float Z, float W)
{
	m_x = X;
	m_y = Y;
	m_z = Z;
	m_w = W;
}

//==================OPERATOR(*)======================
Vector4 operator * (float scalar, const Vector4 &vec4)
{
	//vector4 multiplied by scalar
	return	vec4 * scalar;

}
//==================OPERATOR(*)======================

//returns float of index through [] operator
float Vector4::operator[](int index) const
{
	return data[index];
}
//returns float of index through [] operator

//returns float reference through [] operator
float& Vector4::operator[](int index)
{
	return data[index];
}
//returns float reference through [] operator

//converts to float
Vector4::operator float* ()
{
	return data;
}
//converts to float



//converts to const float
Vector4::operator const float*()
{
	return data;
}
//converts to const float


//==================OPERATOR(+)======================
Vector4 Vector4::operator+(const Vector4 &other) const
{
	return { m_x + other.m_x, m_y + other.m_y , m_z + other.m_z , m_w + other.m_w };
}
//==================OPERATOR(+)======================


//==================OPERATOR(+=)======================
Vector4 Vector4::operator+=(const Vector4 & other)
{
	m_x += other.m_x;
	m_y += other.m_y;
	m_z += other.m_z;
	m_w += other.m_w;
	return *this;
}
//==================OPERATOR(+=)======================


//==================OPERATOR(-)======================
Vector4& Vector4::operator -(const Vector4 &other)
{
	m_x -= other.m_x;
	m_y -= other.m_y;
	m_z -= other.m_z;
	m_w -= other.m_w;
	return *this;
}
//==================OPERATOR(-)======================



//==================OPERATOR(-=)======================
Vector4 & Vector4::operator-=(const Vector4 * other)
{
	m_x -= other->m_x;
	m_y -= other->m_y;
	m_z -= other->m_z;
	m_w -= other->m_w;

	return *this;
}
//==================OPERATOR(-=)======================


//==================OPERATOR(*=)======================
Vector4 & Vector4::operator*=(float scalar)
{
	m_x *= scalar;
	m_y *= scalar;
	m_z *= scalar;
	m_w *= scalar;

	return *this;
}
//==================OPERATOR(*=)======================


//==================OPERATOR(*)======================
Vector4 Vector4::operator * (float scalar) const
{
	return { m_x * scalar, m_y * scalar, m_z *scalar, m_w * scalar };
}
//==================OPERATOR(*)======================


//==================OPERATOR(/)======================
Vector4& Vector4::operator /(float scalar)
{
	m_x /= scalar;
	m_y /= scalar;
	m_z /= scalar;
	m_w /= scalar;
	return *this;
}
//==================OPERATOR(/)======================


//==================OPERATOR(=)======================
Vector4& Vector4::operator = (const Vector4 &other)
{
	m_x = other.m_x;
	m_y = other.m_y;
	m_z = other.m_z;
	m_w = other.m_w;

	return *this;
}
//==================OPERATOR(=)======================


//finds square root of the vector4 for magnitude
float Vector4::magnitude() const
{
	return sqrt(m_x*m_x + m_y * m_y + m_z * m_z + m_w * m_w);
}
//finds square root of the vector4 for magnitude


//decrease the vector2 by the scale increased through magnitude
void Vector4::normalise()
{
	float mag = sqrt(m_x*m_x + m_y * m_y + m_z * m_z + m_w * m_w);
	m_x /= mag;
	m_y /= mag;
	m_z /= mag;
	m_w /= mag;
}
//decrease the vector2 by the scale increased through magnitude


//==============DOT multiplication==============
float Vector4::dot(const Vector4 & other) const
{
	return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z + m_w * other.m_w;
}
//==============DOT multiplication==============

//cross multiplication 
Vector4 Vector4::cross(const Vector4 & other) const
{
	return{ m_y * other.m_z - m_z * other.m_y,
			m_z * other.m_x - m_x * other.m_z,
			m_x * other.m_y - m_y * other.m_x,
			0 };
}