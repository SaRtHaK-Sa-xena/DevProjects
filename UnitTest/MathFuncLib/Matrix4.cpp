#include "Matrix4.h"
#include <iostream>

using namespace std;

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

//Matrix4::Matrix4(float aX, float bX, float cX, float dX,
//	float aY, float bY, float cY, float dY,
//	float aZ, float bZ, float cZ, float dZ,
//	float aW, float bW, float cW, float dW)

Matrix4::Matrix4(float aX, float aY, float aZ, float aW,
	float bX, float bY, float bZ, float bW,
	float cX, float cY, float cZ, float cW,
	float dX, float dY, float dZ, float dW)
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

Vector4 & Matrix4::operator[](int index)
{
	return axis[index];
}

const Vector4 & Matrix4::operator[](int index) const
{
	return axis[index];
}

Matrix4 Matrix4::operator=(Matrix4 &other)
{
	a_x = other.a_x;
	a_y = other.a_y;
	a_z = other.a_z;
	a_w = other.a_w;

	b_x = other.b_x;
	b_y = other.b_y;
	b_z = other.b_z;
	b_w = other.b_w;

	c_x = other.c_x;
	c_y = other.c_y;
	c_z = other.c_z;
	c_w = other.c_w;

	d_x = other.d_x;
	d_y = other.d_y;
	d_z = other.d_z;
	d_w = other.d_w;

	return *this;
}

Matrix4 Matrix4::operator=(Vector4 & other)
{
	a_x = other.m_x;
	a_y = other.m_y;
	a_z = other.m_z;
	a_w = other.m_w;

	return *this;
}

Vector4 Matrix4::operator*(const Vector4 &v)const
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
	return *data;
}

void Matrix4::setScaled(float x, float y, float z, float w)
{
	xAxis = { x,0,0,0 };
	yAxis = { 0,y,0,0 };
	zAxis = { 0,0,z,0 };
	wAxis = { 0,0,0,w };
	translation = { 0,0,0,1 };
}

void Matrix4::setScaled(const Vector4 & v)
{
	xAxis = { v.m_x,0,0,0 };
	yAxis = { 0,v.m_y,0,0 };
	zAxis = { 0,0,v.m_z,0 };
	wAxis = { 0,0,0,v.m_w };
}

Matrix4 & Matrix4::setRotateX(float radians)
{
	xAxis = { 1, 0, 0, 0 };
	yAxis = { 0, cosf(radians), sinf(radians), 0 };
	zAxis = { 0, -sinf(radians), cosf(radians), 0 };
	wAxis = { 0, 0, 0, 1 };

	return *this;

}

Matrix4 & Matrix4::setRotateY(float radians)
{
	xAxis = { cosf(radians), 0, -sinf(radians), 0 };
	yAxis = { 0, 1, 0, 0 };
	zAxis = { sinf(radians), 0, cosf(radians), 0 };
	wAxis = { 0, 0, 0, 1 };
	return *this;
}

Matrix4 & Matrix4::setRotateZ(float radians)
{
	xAxis = { cosf(radians), sinf(radians), 0, 0 };
	yAxis = { -sinf(radians), cosf(radians), 0, 0 };
	zAxis = { 0, 0, 1, 0 };
	wAxis = { 0, 0, 0, 1 };

	return *this;

}