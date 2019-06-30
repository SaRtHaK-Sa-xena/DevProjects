#pragma once

class Vector2
{
public:

	Vector2();
	Vector2(float X, float Y);

	union {
		struct {
			float m_x;
			float m_y;
		};
		float data[2];
	};


	float operator[](int index) const
	{
		return data[index];
	}
	float &operator[](int index)
	{
		return data[index];
	}
	operator float*();

	//==========PLUS====================
	Vector2 operator+(const Vector2 &other);
	//==========PLUS====================

	//==========MINUS EQUAL==============
	Vector2 operator-(const Vector2 &other);
	//==========MINUS EQUAL==============

	//==========MULTIPLY=================
	Vector2 operator*(float scalar) const;

	//==========MULTIPLY=================

	//=========DIVIDE EQUAL==============
	Vector2 operator/=(float scalar);
	//=========DIVIDE EQUAL==============

	//=========EQUAL=====================
	Vector2 operator=(Vector2 &other);
	//=========EQUAL=====================


	//void operator/(float scalar);


	//===========GETTERS===============
	float GetX();
	float GetY();
	//===========GETTERS===============

	//===========SETTERS===============
	void SetX(float x_value);
	void SetY(float y_value);
	//===========SETTERS===============

	float dot(const Vector2 &other) const;
	float magnitude()const;
	void normalise();
	void DisplayVectorCoordinates();


};
Vector2 operator*(float scalar, const Vector2 &vec);