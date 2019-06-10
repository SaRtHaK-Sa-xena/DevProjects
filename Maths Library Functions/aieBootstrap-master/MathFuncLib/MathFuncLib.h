#pragma once
#include <iostream>
// MathFuncsLib.h

//===============VECTOR3==============
class Vector3
{
public:

	Vector3();
	Vector3(float X, float Y, float Z);

	//float operator[](int index) const; //returns 
	//float& operator[](int index);

	//float VectorArray[3]; //To Be Used
	float m_x, m_y, m_z;

	double PrintVectorx(float x);
	void DisplayVector3Coordinates();


	float GetX();
	float GetY();
	float GetZ();

	void SetX(float x_value);
	void SetY(float y_value);
	void SetZ(float z_value);


	//=============================
	void operator-= (const Vector3 &other);
	void operator+ (const Vector3 &other);
	void operator* (float scalar);
	void operator/= (float scalar);
	void operator= (const Vector3 &other);


};
//===============VECTOR3==============


//============VECTOR2=================
class Vector2
{
public:

	Vector2();
	Vector2(float X, float Y);

	float m_x, m_y;

	//==========PLUS====================
	void operator+(const Vector2 &other); //========WORKS
	//==========PLUS====================

	//==========MINUS EQUAL==============
	void operator-=(const Vector2 &other);
	//==========MINUS EQUAL==============

	//==========MULTIPLY=================
	void operator*(float scalar);
	//==========MULTIPLY=================

	//=========DIVIDE EQUAL==============
	void operator/=(float scalar);
	//=========DIVIDE EQUAL==============

	//=========EQUAL=====================
	void operator=(const Vector2 &other);
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


	
	void Add(Vector2 *vector1, Vector2 *vector2);
	void DisplayVectorCoordinates();


	//double PrintVector2Dx(float x);
};
//============VECTOR2=================


//==============EXAMPLE=================
namespace MathFuncs
{
	class MyMathFuncs
	{
	public:
		// Returns a + b
		static double Add(double a, double b);

		// Returns a - b
		static double Subtract(double a, double b);

		// Returns a * b
		static double Multiply(double a, double b);

		// Returns a / b
		static double Divide(double a, double b);
	};
}
//==============EXAMPLE=================

class Matrix2
{
	float m[2][2];
};

class Matrix3
{
public:

	float m[3][3];

	float m_x;
	float m_y;
	float m_z;

	Matrix3(float m[]) //3x3

	float operator*(const Matrix3 &other);

};

class Matrix4
{
};
