#include "Vector4.h"
#include <iostream>

using namespace std;

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

Vector4::Vector4(float X, float Y, float Z, float W)
{
	m_x = X;
	m_y = Y;
	m_z = Z;
	m_w = W;
}

Vector4 operator * (float scalar, const Vector4 &vec4)
{
	return	vec4 * scalar;

}

float Vector4::operator[](int index) const
{
	return data[index];
}

float& Vector4::operator[](int index)
{
	return data[index];
}

Vector4::operator float* ()
{
	return data;
}

Vector4::operator const float*()
{
	return data;
}

Vector4 Vector4::operator+(const Vector4 &other) const
{
	return { m_x + other.m_x, m_y + other.m_y , m_z + other.m_z , m_w + other.m_w };
}

Vector4 Vector4::operator+=(const Vector4 & other)
{
	m_x += other.m_x;
	m_y += other.m_y;
	m_z += other.m_z;
	m_w += other.m_w;
	return *this;
}

Vector4& Vector4::operator -(const Vector4 &other)
{
	m_x -= other.m_x;
	m_y -= other.m_y;
	m_z -= other.m_z;
	m_w -= other.m_w;
	return *this;
}

Vector4 & Vector4::operator-=(const Vector4 * other)
{
	m_x -= other->m_x;
	m_y -= other->m_y;
	m_z -= other->m_z;
	m_w -= other->m_w;

	return *this;

}

Vector4 & Vector4::operator*=(float scalar)
{
	m_x *= scalar;
	m_y *= scalar;
	m_z *= scalar;
	m_w *= scalar;

	return *this;

}

Vector4 Vector4::operator * (float scalar) const
{
	return { m_x * scalar, m_y * scalar, m_z *scalar, m_w * scalar };
}


Vector4& Vector4::operator /(float scalar)
{
	m_x /= scalar;
	m_y /= scalar;
	m_z /= scalar;
	m_w /= scalar;
	return *this;
}
Vector4& Vector4::operator = (const Vector4 &other)
{
	m_x = other.m_x;
	m_y = other.m_y;
	m_z = other.m_z;
	m_w = other.m_w;

	return *this;
}
float Vector4::magnitude() const
{
	return sqrt(m_x*m_x + m_y * m_y + m_z * m_z + m_w * m_w);
}
void Vector4::normalise()
{
	float mag = sqrt(m_x*m_x + m_y * m_y + m_z * m_z + m_w * m_w);
	m_x /= mag;
	m_y /= mag;
	m_z /= mag;
	m_w /= mag;
}
float Vector4::dot(const Vector4 & other) const
{
	return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z + m_w * other.m_w;
}
Vector4 Vector4::cross(const Vector4 & other) const
{
	return{ m_y * other.m_z - m_z * other.m_y,
			m_z * other.m_x - m_x * other.m_z,
			m_x * other.m_y - m_y * other.m_x,
			0 };
}