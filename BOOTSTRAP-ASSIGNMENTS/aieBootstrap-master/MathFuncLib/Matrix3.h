#pragma once
#include "Vector3.h"

class Matrix3
{
public:
	//=============initialize values for Default Constructor=============

	union {
		struct {

			float a_x;
			float a_y;
			float a_z;

			float b_x;
			float b_y;
			float b_z;

			float c_x;
			float c_y;
			float c_z;
		};

		float data[3][3];

		struct {
			Vector3 xAxis;
			Vector3 yAxis;
			union {
				Vector3 zAxis;
				Vector3 translation;
			};
		};

		Vector3 axis[3];

	};
	//=============initialize values for Default Constructor=============

	Matrix3();
	Matrix3(float aX, float bX, float cX, float aY, float bY, float cY, float aZ, float bZ, float cZ); //3x3

	Vector3& operator[](int index);
	const Vector3& operator[](int index)const;

	Matrix3 &operator=(const Matrix3 &other);
	Matrix3 &operator=(Vector3 &other);
	operator float*();
	Vector3 operator*(const Vector3 &v)const;

	Matrix3 operator*(const Matrix3 &other)const;

	Matrix3 transposed() const;
	static const Matrix3 identity;


	//============rotation================
	void setScaled(float x, float y, float z);
	void setScaled(const Vector3 &v);

	void scale(const Vector3 &v);
	void scale(float width, float height, int i);

	Matrix3 &setRotateX(float radians);
	Matrix3 &setRotateY(float radians);
	Matrix3 &setRotateZ(float radians);



	void rotateX(float radians);
	void rotateY(float radians);
	void rotateZ(float radians);

	void setEuler(float pitch, float yaw, float roll);

	void translate(float x, float y)
	{
		translation += Vector3(x, y, 0);
	}
	//============rotation================

};