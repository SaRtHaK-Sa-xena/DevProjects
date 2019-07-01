#pragma once
#include "MathFuncLib.h"

class BulletObject
{
public:

	BulletObject()
	{
		position = Matrix3::identity; //default
		speed = 0;
		rotation = 0;
	}
	~BulletObject() {};

	BulletObject(Matrix3 m_position, float m_speed, float m_rotation)
	{
		position = m_position;
		speed = m_speed;
		rotation = m_rotation;
	}

protected:

	Matrix3 position;
	float speed;
	float rotation;
};