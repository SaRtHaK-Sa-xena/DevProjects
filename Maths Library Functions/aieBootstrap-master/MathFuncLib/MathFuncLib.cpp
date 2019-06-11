
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
	cout << "(" << GetX() << "," << "" << GetY() << "," << "" << GetZ() <<  ")" << endl;
}

//=================Vector3 Initialization==========================
Vector3::operator float*() { return data; }

Vector3::operator const float*() const
{
	return data;
}



//========================VECTOR 3==========================
Vector3 Vector3::operator+(const Vector3 &other)
{
	SetX(m_x + other.m_x);
	SetY(m_y + other.m_y);
	SetZ(m_z + other.m_z);
}
Vector3 Vector3::operator- (const Vector3 &other)
{
	SetX(m_x -= other.m_x);
	SetY(m_y -= other.m_y);
	SetZ(m_z -= other.m_z);
}
Vector3 Vector3::operator * (float scalar)  
{
	SetX(m_x * scalar);
	SetY(m_y * scalar);
	SetZ(m_z * scalar);
}
Vector3 Vector3::operator /= (float scalar) 
{
	SetX(m_x /= scalar);
	SetY(m_y /= scalar);
	SetZ(m_z /= scalar);
}
Vector3 Vector3::operator = (const Vector3& other) 
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

	data[0] = X;
	data[1] = Y;
}


Vector2::operator float*() { return &m_x; }


//==================OPERATOR PLUS======================
Vector2 Vector2::operator+(const Vector2 & other)
{
	SetX(m_x + other.m_x);
	SetY(m_y + other.m_y);
}
Vector2 Vector2::operator-(const Vector2 & other)
{
	SetX(m_x -= other.m_x);
	SetY(m_y -= other.m_y);
}
Vector2 Vector2::operator/= (float scalar)
{
	SetX(m_x /= scalar);
	SetY(m_y /= scalar);
}
Vector2 Vector2::operator*(float scalar)const
{
	//m_x = m_x * scalar;
	//m_y = m_y * scalar;

	m_x * scalar; //SetX()
	m_y * scalar;
}
Vector3 operator*(float scalar, Vector3  &vec3)
{
	scalar * vec3;
}
Vector2 operator*(float scalar, const Vector2 & vec)
{
	vec * scalar;
}
Vector2 Vector2::operator=(Vector2 & other)
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

Matrix3::Matrix3()
{
	a_x = 1;
	b_x = 0;
	c_x = 0;

	a_y = 0;
	b_y = 1;
	c_y = 0;

	a_z = 0;
	b_z = 0;
	c_z = 1;

	

	data[0][0] = a_x;
	data[0][1] = a_y;
	data[0][2] = a_z;

	data[1][0] = b_x;
	data[1][1] = b_y;
	data[1][2] = b_z;

	data[2][0] = c_x;
	data[2][1] = c_y;
	data[2][2] = c_z;
}

Matrix3::Matrix3(float aX, float bX, float cX, float aY, float bY, float cY, float aZ, float bZ, float cZ)
{
	a_x = aX;
	b_x = bX;
	c_x = cX;

	a_y = aY;
	b_y = bY;
	c_y = cY;

	a_z = aZ;
	b_z = bZ;
	c_z = cZ;

}


Matrix3::operator float*()
{
	return &data[3][3];
}

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

Matrix3 Matrix3::transposed() const
{
	Matrix3 result; // flip row and column
	for (int r = 0 ; r < 3 ; ++r)
		for (int c = 0; c < 3; ++c)
			result.data[r][c] = data[c][r];
	return result;
}

Vector3 Matrix3::operator*(const Vector3 &v)const
{
	Vector3 result;

	for (int r = 0; r < 3; r++)
	{
		result[r] = data[0][r] * v[0] + data[1][r] * v[1] + data[2][r] * v[2];
	}

	return result;
}

const Matrix3 Matrix3::identity = Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);





Matrix4::operator float*()
{
	return &data[4][4];
}


