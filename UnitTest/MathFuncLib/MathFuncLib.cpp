
#include "stdafx.h"
#include "MathFuncLib.h"
#include <stdexcept>

using namespace std;


//===============================VECTOR 4=========================
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
	vec4 * scalar;
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

Vector4 Vector4::operator * (float scalar) const
{
	return { m_x * scalar, m_y * scalar, m_z *scalar, m_w * scalar };
}

Vector4 Vector4::operator *(const Matrix4 &other)const
{
	m_x * other.m_x;
	m_y * other.m_y;
	m_z * other.m_z;
	m_w * other.m_w;
	return *this;
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
//===============================VECTOR 4=========================












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


//==================OPERATOR ======================
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


//=======================================================MATRIX3======================================
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

Matrix3 Matrix3::operator *(const Matrix3 &other)const
{
	// r = rows
	// c = columns

	Matrix3 result;

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			result.data[c][r] = data[0][r] * other.data[c][0] +
								data[1][r] * other.data[c][1] +
								data[2][r] * other.data[c][2];
		}
	}
	return result;
}


//float Matrix3::operator*(const Matrix3 & other)
//{
//	Matrix3 result;
//
//	for (int r = 0; r < 3; r++)
//	{
//		for (int c = 0; c < 3; c++)
//		{
//			result.m[c][r] = m[0][r] * other.m[c][0] +
//				m[1][r] * other.m[c][1] +
//				m[2][r] * other.m[c][2];
//		}
//	}
//
//	return 0.0f;
//}

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

Matrix3 Matrix3::operator=(const Matrix3 &other)
{
	a_x = other.a_x; 
	a_y = other.a_y; 
	a_z = other.a_z; 

	b_x = other.b_x; 
	b_y = other.a_y; 
	b_z = other.b_z; 
	
	c_x = other.c_x; 
	c_y = other.c_y; 
	c_z = other.c_z; 

}

Matrix3 Matrix3::operator=(Vector3 & other)
{
	a_x = other.m_x;
	a_y = other.m_y;
	a_z = other.m_z;
}

const Matrix3 Matrix3::identity = Matrix3
	(1, 0, 0,
	0, 1, 0,
	0, 0, 1);



//=======================rotation================
void Matrix3::setScaled(float x, float y, float z)
{
	xAxis = { x,0,0 };
	yAxis = { 0,y,0 };
	zAxis = { 0,0,z };
}

void Matrix3::setScaled(const Vector3 &v)
{
	xAxis = { v.m_x,0,0 };
	yAxis = { 0,v.m_y,0 };
	zAxis = { 0,0,v.m_z };
}

void Matrix3::scale(const Vector3 &v)
{
	Matrix3 m;
	m.setScaled(v.m_x, v.m_y, v.m_z);

	*this = *this * m;
}

void Matrix3::setRotateX(float radians) { // leave X axis and elements unchanged
	xAxis = { 1, 0, 0 };
	yAxis = { 0, cosf(radians), sinf(radians) };
	zAxis = { 0, -sinf(radians), cosf(radians) };
}

void Matrix3::setRotateY(float radians) { // leave X axis and elements unchanged
	xAxis = { cosf(radians), 0, -sinf(radians) };
	yAxis = { 0, 1, 0};
	zAxis = { sinf(radians), 0, cosf(radians) };
}

void Matrix3::setRotateZ(float radians) { // leave X axis and elements unchanged
	xAxis = { cosf(radians), -sinf(radians), 0};
	yAxis = { sinf(radians), 1, cosf(radians) };
	zAxis = { 0, 0, 1 };
}

void Matrix3::rotateX(float radians) 
{ 
	Matrix3 m;
	m.setRotateX(radians);
	*this = *this * m;
}

void Matrix3::setEuler(float pitch, float yaw, float roll) 
{
	Matrix3 x, y, z;
	x.setRotateX(pitch);
	y.setRotateY(yaw);
	z.setRotateZ(roll);
	// combine rotations in a specific order
	*this = z * y * x;
}

//=======================rotation================




//=======================================================MATRIX3======================================
//
//=====================================MATRIX 4========================================================

Matrix4::Matrix4()
{
	a_x = 1;
	a_y = 0;
	a_z = 0;
	a_w = 0;

	b_x = 0;
	b_y = 1;
	b_z = 0;
	b_w = 0;

	c_x = 0;
	c_y = 0;
	c_z = 1;
	c_w = 0;

	d_x = 0;
	d_y = 0;
	d_z = 0;
	d_w = 1;

	data[0][0] = a_x;
	data[0][1] = a_y;
	data[0][2] = a_z;
	data[0][3] = a_w;

	data[1][0] = b_x;
	data[1][1] = b_y;
	data[1][2] = b_z;
	data[1][3] = b_w;

	data[2][0] = c_x;
	data[2][1] = c_y;
	data[2][2] = c_z;
	data[2][3] = c_w;

	data[3][0] = d_x;
	data[3][1] = d_y;
	data[3][2] = d_z;
	data[3][3] = d_w;
}

Matrix4::Matrix4(float aX, float bX, float cX, float dX,
	float aY, float bY, float cY, float dY,
	float aZ, float bZ, float cZ, float dZ,
	float aW, float bW, float cW, float dW)
{
	a_x = aX;
	a_y = aY;
	a_z = aZ;
	a_w = aW;

	b_x = bX;
	b_y = bY;
	b_z = bZ;
	b_w = bW;

	c_x = cX;
	c_y = cY;
	c_z = cZ;
	c_w = cW;

	d_x = dX;
	d_y = dY;
	d_z = dZ;
	d_w = dW;
}

Matrix4 Matrix4::operator=(Matrix4 &other)
{
	a_x = other.a_x;
	a_y = other.a_y;
	a_z = other.a_z;
	a_w = other.a_w;

	b_x = other.b_x;
	b_y = other.a_y;
	b_z = other.b_z;
	b_w = other.b_w;

	c_x = other.c_x;
	c_y = other.c_y;
	c_z = other.c_z;
	c_w = other.c_w;
}

Vector4 Matrix4::operator*(const Vector3 &v)const
{
	Vector4 result;

	for (int r = 0; r < 4; r++)
	{
		result[r] = data[0][r] * v[0] + data[1][r] * v[1] + data[2][r] * v[2] + data[3][r] * v[3];
	}

	return result;
}

Matrix4 Matrix4::operator*(const Matrix4 &other) const
{
	Matrix4 result;

	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			result.data[c][r] = data[0][r] * other.data[c][0] +
				data[1][r] * other.data[c][1] +
				data[2][r] * other.data[c][2] +
				data[3][r] * other.data[c][3];
		}
	}
	return result;
}

Matrix4 Matrix4::transposed()const
{
	Matrix4 result;
	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			result.data[r][c] = data[c][r];
		}
	}
	return result;
}

//IDENTITY
const Matrix4 Matrix4::identity = Matrix4
	(1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1);

Matrix4::operator float*()
{
	return &data[4][4];
}

void Matrix4::setScaled(float x, float y, float z)
{
	xAxis = { x,0,0,0 };
	yAxis = { 0,y,0,0 };
	zAxis = { 0,0,z,0 };
	translation = { 0,0,0,1 };
}
//=====================================MATRIX 4========================================================


