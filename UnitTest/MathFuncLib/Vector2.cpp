#include "Vector2.h"
#include <iostream>

Vector2::Vector2()
{
	m_x = 1;
	m_y = 1;

}
Vector2::Vector2(float X, float Y)
{
	m_x = X;
	m_y = Y;

	data[0] = X;
	data[1] = Y;
}


Vector2::operator float*() { return &m_x; }


//==================OPERATOR ======================
Vector2 Vector2::operator+(const Vector2 & other)
{
	return { m_x + other.m_x, m_y + other.m_y };
}
Vector2 Vector2::operator-(const Vector2 & other)
{
	m_x -= other.m_x;
	m_y -= other.m_y;
	return *this;
}
Vector2 Vector2::operator/= (float scalar)
{
	m_x /= scalar;
	m_y /= scalar;
	return *this;
}
Vector2 Vector2::operator*(float scalar)const
{
	return{ m_x * scalar, m_y * scalar };
}
Vector2 operator*(float scalar, const Vector2 & vec)
{
	return vec * scalar;
}
Vector2 Vector2::operator=(Vector2 & other)
{
	m_x = other.m_x;
	m_y = other.m_y;
	return *this;
}
//==================OPERATOR======================

float Vector2::GetX()
{
	return m_x;
}
float Vector2::GetY()
{
	return m_y;
}

void Vector2::SetX(float x_value)
{
	m_x = x_value;
}
void Vector2::SetY(float y_value)
{
	m_y = y_value;
}

float Vector2::dot(const Vector2 & other) const
{
	return m_x * other.m_x + m_y * other.m_y;
}

float Vector2::magnitude() const
{
	return sqrt(m_x*m_x + m_y * m_y);
}

void Vector2::normalise()
{
	float mag = sqrt(m_x*m_x + m_y * m_y);
	m_x /= mag;
	m_y /= mag;
}

void Vector2::DisplayVectorCoordinates()
{
	std::cout << "(" << GetX() << "," << "" << GetY() << ")" << std::endl;
}