#include "stdafx.h"
#include "Matrix3.h"
#include <iostream>

using namespace std;

//basic constructor equals the identity matrix
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


//setting constructor
Matrix3::Matrix3(float aX, float aY, float aZ, float bX, float bY, float bZ, float cX, float cY, float cZ)
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

//returns the corresponding vector3 index
Vector3 & Matrix3::operator[](int index)
{
	return axis[index];
}
//returns the corresponding vector3 index


//returns the const version of the vector3 index
const Vector3 & Matrix3::operator[](int index) const
{
	return axis[index];
}
//returns the const version of the vector3 index

//returns float of data
Matrix3::operator float*()
{
	return *data;
}
//returns float of data


//==================OPERATOR(*)======================
Matrix3 Matrix3::operator*(const Matrix3 &other)const
{
	// r = rows
	// c = columns

	Matrix3 result;

	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
		{
			result.data[c][r] = data[0][r] * other.data[c][0] +
				data[1][r] * other.data[c][1] +
				data[2][r] * other.data[c][2];
		}
	}
	return result;
}
//==================OPERATOR(*)======================


//transposes Matrix3
Matrix3 Matrix3::transposed() const
{
	Matrix3 result; // flip row and column
	for (int r = 0; r < 3; ++r)
		for (int c = 0; c < 3; ++c)
			result.data[r][c] = data[c][r];
	return result;
}


//==================OPERATOR(*)======================
Vector3 Matrix3::operator*(const Vector3 &v)const
{
	Vector3 result;

	for (int r = 0; r < 3; r++)
	{
		result[r] = data[0][r] * v[0] + data[1][r] * v[1] + data[2][r] * v[2];
	}

	return result;
}
//==================OPERATOR(*)======================


//==================OPERATOR(=)======================
Matrix3 & Matrix3::operator=(const Matrix3 &other)
{
	a_x = other.a_x;
	a_y = other.a_y;
	a_z = other.a_z;

	b_x = other.b_x;
	b_y = other.b_y;
	b_z = other.b_z;

	c_x = other.c_x;
	c_y = other.c_y;
	c_z = other.c_z;

	return *this;
}
//==================OPERATOR(=)======================


//==================OPERATOR(=)======================
Matrix3 & Matrix3::operator=(Vector3 & other)
{
	a_x = other.m_x;
	a_y = other.m_y;
	a_z = other.m_z;

	return *this;
}
//==================OPERATOR(=)======================

//makes the default constructor, which is the identity matrix
const Matrix3 Matrix3::identity = Matrix3
   (1, 0, 0,
	0, 1, 0,
	0, 0, 1);

//makes the default constructor, which is the identity matrix


//=================sets scale by changing matrix values==========
void Matrix3::setScaled(float x, float y, float z)
{
	xAxis = { x,0,0 };
	yAxis = { 0,y,0 };
	zAxis = { 0,0,z };
}
//=================sets scale by changing matrix values==========

//sets by using copied values of given vector3
void Matrix3::setScaled(const Vector3 &v)
{
	xAxis = { v.m_x,0,0 };
	yAxis = { 0,v.m_y,0 };
	zAxis = { 0,0,v.m_z };
}


//makes the matrix have values from vector3
void Matrix3::scale(const Vector3 &v)
{
	Matrix3 m;
	m.setScaled(v.m_x, v.m_y, v.m_z);

	*this = *this * m;
}


//makes the matrix through values from given width, height, and i
void Matrix3::scale(float width, float height, int i)
{
	Matrix3 m;
	m.setScaled(width, height, 1);

	*this = *this * m;
}


//sets rotation for rotating on x axis
Matrix3 & Matrix3::setRotateX(float radians) { // leave X axis and elements unchanged
	xAxis = { 1, 0, 0 };
	yAxis = { 0, cosf(radians), sinf(radians) };
	zAxis = { 0, -sinf(radians), cosf(radians) };

	return *this;
}


//sets rotation for rotating on y axis
Matrix3 & Matrix3::setRotateY(float radians) {
	xAxis = { cosf(radians), 0, -sinf(radians) };
	yAxis = { 0, 1, 0 };
	zAxis = { sinf(radians), 0, cosf(radians) };
	return *this;
}


//sets rotation for rotating on z axis
Matrix3 &Matrix3::setRotateZ(float radians) {

	xAxis = { cosf(radians), sinf(radians), 0 };
	yAxis = { -sinf(radians), cosf(radians), 0 };
	zAxis = { 0, 0, 1 };

	return *this;
}


//cause rotation for x
void Matrix3::rotateX(float radians)
{
	Matrix3 m;
	m.setRotateX(radians);
	*this = *this * m;
}


//cause rotation for y
void Matrix3::rotateY(float radians)
{
	Matrix3 m;
	m.setRotateY(radians);
	*this = *this *m;
}


//cause rotation for z
void Matrix3::rotateZ(float radians)
{
	Matrix3 m;
	m.setRotateZ(radians);
	*this = *this *m;
}


//sets Euler
void Matrix3::setEuler(float pitch, float yaw, float roll)
{
	Matrix3 x, y, z;
	x.setRotateX(pitch);
	y.setRotateY(yaw);
	z.setRotateZ(roll);
	// combine rotations in a specific order
	*this = z * y * x;
}