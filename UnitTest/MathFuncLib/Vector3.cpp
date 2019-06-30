#include "Vector3.h"
#include <iostream>
using namespace std;

Vector3::Vector3()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;

	data[0] = m_x;
	data[1] = m_y;
	data[2] = m_z;

}
Vector3::Vector3(float X, float Y, float Z)
{
	m_x = X;
	m_y = Y;
	m_z = Z;
}


double Vector3::PrintVectorx(float x)
{
	return x;
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

void Vector3::DisplayVector3Coordinates()
{
	cout << "(" << GetX() << "," << "" << GetY() << "," << "" << GetZ() << ")" << endl;
}

//=================Vector3 Initialization==========================
Vector3::operator float*() { return data; }

Vector3::operator const float*() const
{
	return data;
}




//========================VECTOR 3==========================
Vector3 Vector3::operator+(const Vector3 &other) const
{
	return{ m_x + other.m_x, m_y + other.m_y, m_z + other.m_z };
}
Vector3 Vector3::operator+=(const Vector3 & other)
{
	m_x += other.m_x;
	m_y += other.m_y;
	m_z += other.m_z;
	return *this;
}
Vector3 Vector3::operator- (const Vector3 &other)
{
	Vector3 result;

	result.SetX(m_x -= other.m_x);
	result.SetY(m_y -= other.m_y);
	result.SetZ(m_z -= other.m_z);

	return result;
}


Vector3 Vector3::operator * (float scalar)
{
	Vector3 result;

	result.SetX(m_x * scalar);
	result.SetY(m_y * scalar);
	result.SetZ(m_z * scalar);

	return result;
}

Vector3 operator * (float scalar, Vector3 &vec3)
{
	return	vec3 * scalar;

}

Vector3 Vector3::operator /= (float scalar)
{
	Vector3 result;

	result.SetX(m_x /= scalar);
	result.SetY(m_y /= scalar);
	result.SetZ(m_z /= scalar);

	return result;
}
Vector3 Vector3::operator = (const Vector3& other)
{
	m_x = other.m_x;
	m_y = other.m_y;
	m_z = other.m_z;
	return *this;
}
float Vector3::dot(const Vector3 & other) const
{
	return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
}

float Vector3::magnitude() const
{
	return sqrt(m_x*m_x + m_y * m_y + m_z * m_z);
}

void Vector3::normalise()
{
	float mag = sqrt(m_x*m_x + m_y * m_y + m_z * m_z);
	m_x /= mag;
	m_y /= mag;
	m_z /= mag;
}


Vector3 Vector3::cross(const Vector3 & other) const
{
	return{ m_y * other.m_z - m_z * other.m_y,
			m_z * other.m_x - m_x * other.m_z,
			m_x * other.m_y - m_y * other.m_x };
}