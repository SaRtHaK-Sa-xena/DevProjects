
#include "stdafx.h"
#include "MathFuncLib.h"
#include <stdexcept>

using namespace std;

//=================Vector3 Initialization==========================
Vector3::Vector3()
{
	m_x = 1;
	m_y = 1;
	m_z = 1;
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
	cout << "(" << GetX() << "," << "" << GetY() << "," << "" << GetZ() <<  ")" << endl;
}

//=================Vector3 Initialization==========================

//========================VECTOR 3==========================
void Vector3::operator+(const Vector3 &other)
{
	SetX(m_x + other.m_x);
	SetY(m_y + other.m_y);
	SetZ(m_z + other.m_z);
}
void Vector3::operator-= (const Vector3 &other)
{
	SetX(m_x -= other.m_x);
	SetY(m_y -= other.m_y);
	SetZ(m_z -= other.m_z);
}
void Vector3::operator * (float scalar)  
{
	SetX(m_x * scalar);
	SetY(m_y * scalar);
	SetZ(m_z * scalar);
}
void Vector3::operator /= (float scalar) 
{
	SetX(m_x /= scalar);
	SetY(m_y /= scalar);
	SetZ(m_z /= scalar);
}
void Vector3::operator = (const Vector3& other) 
{
	SetX(m_x = other.m_x);
	SetY(m_y = other.m_y);
	SetZ(m_z = other.m_z);
}













//=============VECTOR2==================
Vector2::Vector2()
{
	m_x = 1;
	m_y = 1;
}

Vector2::Vector2(float X, float Y)
{
	m_x = X;
	m_y = Y;
}

//==================OPERATOR PLUS======================
void Vector2::operator+(const Vector2 & other)
{
	SetX(m_x + other.m_x);
	SetY(m_y + other.m_y);
}
void Vector2::operator-=(const Vector2 & other)
{
	SetX(m_x -= other.m_x);
	SetY(m_y -= other.m_y);
}
void Vector2::operator/= (float scalar)
{
	SetX(m_x /= scalar);
	SetY(m_y /= scalar);
}
void Vector2::operator*(float scalar)
{
	//m_x = m_x * scalar;
	//m_y = m_y * scalar;

	SetX(m_x * scalar);
	SetY(m_y * scalar);
}
void Vector2::operator=(const Vector2 & other)
{
	SetX(m_x = other.m_x);
	SetY(m_y = other.m_y);
}
//==================OPERATOR PLUS======================

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



//void Vector2::Add(Vector2 *vector1, Vector2 *vector2)
//{
//	//get X,Y (vector1)
//	float x_vector1 = vector1->GetX();
//	float y_vector1 = vector1->GetY();
//	
//	//get X,Y (vector2)
//	float x_vector2 = vector2->GetX();
//	float y_vector2 = vector2->GetY();
//
//	SetX(x_vector1 + x_vector2);
//	SetY(y_vector1 + y_vector2);
//
//}


void Vector2::DisplayVectorCoordinates()
{
	cout << "(" << GetX() << "," << "" << GetY() << ")" << endl;
}



//============EXAMPLE===================
namespace MathFuncs
{
	double MyMathFuncs::Add(double a, double b)
	{
		return a + b;
	}

	double MyMathFuncs::Subtract(double a, double b)
	{
		return a - b;
	}

	double MyMathFuncs::Multiply(double a, double b)
	{
		return a * b;
	}

	double MyMathFuncs::Divide(double a, double b)
	{
		return a / b;
	}
}
//============EXAMPLE===================

float Matrix3::operator*(const Matrix3 & other)
{
	Matrix3 result;

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			result.m[c][r] = m[0][r] * other.m[c][0] +
				m[1][r] * other.m[c][1] +
				m[2][r] * other.m[c][2];
		}
	}

	return 0.0f;
}
