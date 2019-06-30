#pragma once
#include "Vector4.h"

class Matrix4
{
public:

	union {
		struct {
			float a_x;
			float a_y;
			float a_z;
			float a_w;

			float b_x;
			float b_y;
			float b_z;
			float b_w;

			float c_x;
			float c_y;
			float c_z;
			float c_w;

			float d_x;
			float d_y;
			float d_z;
			float d_w;
		};
		float data[4][4];
		struct {
			Vector4 xAxis;
			Vector4 yAxis;
			Vector4 zAxis;
			union {
				Vector4 wAxis;
				Vector4 translation;
			};
		};
		Vector4 axis[4];
	};

	Matrix4();
	Matrix4(float aX, float aY, float aZ, float aW,
		float bX, float bY, float bZ, float bW,
		float cX, float cY, float cZ, float cW,
		float dX, float dY, float dZ, float dW);

	Vector4 &operator[](int index);
	const Vector4 &operator[](int index)const;

	Matrix4 operator=(Matrix4 &other);
	Matrix4 operator=(Vector4 &other);
	Vector4 operator *(const Vector4 &v)const;
	Matrix4 operator *(const Matrix4 &other)const;

	Matrix4 transposed() const;
	static const Matrix4 identity;

	operator float*();

	//==========rotation========================
	void setScaled(float x, float y, float z, float w);
	void setScaled(const Vector4 &v);

	Matrix4 &setRotateX(float radians);
	Matrix4 &setRotateY(float radians);
	Matrix4 &setRotateZ(float radians);

	void rotateX(float radians);
	void rotateY(float radians);
	void rotateZ(float radians);

	void translate(float x, float y, float z)
	{
		translation += Vector4(x, y, z, 0);
	}
	//==========rotation========================

};