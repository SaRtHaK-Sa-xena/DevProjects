#include "stdafx.h"
#include "Vector3.h"
#include <iostream>
using namespace std;

//basic constructor
Vector3::Vector3()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;

	data[0] = m_x;
	data[1] = m_y;
	data[2] = m_z;

}


//setting constructor
Vector3::Vector3(float X, float Y, float Z)
{
	m_x = X;
	m_y = Y;
	m_z = Z;
}



//========GETTERS================
float Vector3::GetX()
{
	return m_x;
}
float Vector3::GetY()
{
	return m_y;
}
float Vector3::GetZ()
{
	return m_z;
}
//========GETTERS================

//=========SETTERS================
void Vector3::SetX(float x_value)
{
	m_x = x_value;
}
void Vector3::SetY(float y_value)
{
	m_y = y_value;
}
void Vector3::SetZ(float z_value)
{
	m_z = z_value;
}
//=========SETTERS================



//=================Vector3 Initialization==========================

//allows Vector3 to work with float
Vector3::operator float*() { return data; }
//allows Vector3 to work with float


//allows Vector3 const to work with float
Vector3::operator const float*() const
{
	return data;
}
//allows Vector3 const to work with float




//==============VECTOR 3 OPERATORS======================

//==================OPERATOR(+)======================
Vector3 Vector3::operator+(const Vector3 &other) const
{
	return{ m_x + other.m_x, m_y + other.m_y, m_z + other.m_z };
}
//==================OPERATOR(+)======================


//==================OPERATOR(+=)======================
Vector3 Vector3::operator+=(const Vector3 & other)
{
	m_x += other.m_x;
	m_y += other.m_y;
	m_z += other.m_z;
	return *this;
}
//==================OPERATOR(+=)======================

//==================OPERATOR(-)======================
Vector3 Vector3::operator- (const Vector3 &other)
{
	Vector3 result;

	result.SetX(m_x -= other.m_x);
	result.SetY(m_y -= other.m_y);
	result.SetZ(m_z -= other.m_z);

	return result;
}
//==================OPERATOR(-)======================


//==================OPERATOR(*)======================
Vector3 Vector3::operator * (float scalar)
{
	Vector3 result;

	result.SetX(m_x * scalar);
	result.SetY(m_y * scalar);
	result.SetZ(m_z * scalar);

	return result;
}
//==================OPERATOR(*)======================


//==================OPERATOR(*)======================
Vector3 operator * (float scalar, Vector3 &vec3)
{
	//vector3 multiplied by float
	return	vec3 * scalar;
}
//==================OPERATOR(*)======================


//==================OPERATOR(/=)======================
Vector3 Vector3::operator /= (float scalar)
{
	Vector3 result;

	result.SetX(m_x /= scalar);
	result.SetY(m_y /= scalar);
	result.SetZ(m_z /= scalar);

	return result;
}
//==================OPERATOR(/=)======================


//==================OPERATOR(=)======================
Vector3 Vector3::operator = (const Vector3& other)
{
	m_x = other.m_x;
	m_y = other.m_y;
	m_z = other.m_z;
	return *this;
}
//==================OPERATOR(=)======================


//==============DOT multiplication==============
float Vector3::dot(const Vector3 & other) const
{
	return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
}
//==============DOT multiplication==============


//finds square root of the vector3 for magnitude
float Vector3::magnitude() const
{
	return sqrt(m_x*m_x + m_y * m_y + m_z * m_z);
}
//finds square root of the vector2 for magnitude


//decrease the vector3 by the scale increased through magnitude
void Vector3::normalise()
{
	float mag = sqrt(m_x*m_x + m_y * m_y + m_z * m_z);
	m_x /= mag;
	m_y /= mag;
	m_z /= mag;
}
//decrease the vector3 by the scale increased through magnitude


//cross multiplication with vector3
Vector3 Vector3::cross(const Vector3 & other) const
{
	return{ m_y * other.m_z - m_z * other.m_y,
			m_z * other.m_x - m_x * other.m_z,
			m_x * other.m_y - m_y * other.m_x };
}
//cross multiplication with vector3
