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
	float data[3];

	double PrintVectorx(float x);
	void DisplayVector3Coordinates();


	float GetX();
	float GetY();
	float GetZ();

	void SetX(float x_value);
	void SetY(float y_value);
	void SetZ(float z_value);


	operator float*();
	operator const float*()const;


	//=============================
	Vector3 operator- (const Vector3 &other);
	Vector3 operator+ (const Vector3 &other);
	Vector3 operator* (float scalar);
	Vector3 operator/= (float scalar);
	Vector3 operator= (const Vector3 &other);


};
Vector3 operator* (float scalar, Vector3 &vec3);
//===============VECTOR3==============


//============VECTOR2=================
class Vector2
{
public:

	Vector2();
	Vector2(float X, float Y);

	float m_x, m_y;

	float data[2];

	operator float*();

	//==========PLUS====================
	Vector2 operator+(const Vector2 &other); //========WORKS
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
	Vector2 operator=(Vector2 &other); //const before Vector2
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


	
	//void Add(Vector2 *vector1, Vector2 *vector2);
	void DisplayVectorCoordinates();


	//double PrintVector2Dx(float x);
};
//============VECTOR2=================
Vector2 operator*(float scalar, const Vector2 &vec);

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


class Matrix3
{
public:
	//=============initialize values for Default Constructor=============
	float m[3][3];

	float a_x;
	float b_x;
	float c_x;

	float a_y;
	float b_y;
	float c_y;

	float a_z;
	float b_z;
	float c_z;

	float data[3][3];


	Vector3 xAxis;
	Vector3 yAxis;
	Vector3 zAxis;
	//=============initialize values for Default Constructor=============

	Matrix3();
	Matrix3(float aX, float bX, float cX, float aY, float bY, float cY, float aZ, float bZ, float cZ); //3x3


	Matrix3 operator=(const Matrix3 &other);
	Matrix3 operator=(Vector3 &other);
	operator float*();
	Vector3 operator*(const Vector3 &v)const;
	//float operator*(const Matrix3 &other);

	Matrix3 operator *(const Matrix3 &other)const;

	Matrix3 transposed() const;
	static const Matrix3 identity;


	//============rotation================
	void setScaled(float x, float y, float z);
	void setScaled(const Vector3 &v);

	void scale(const Vector3 &v);

	void setRotateX(float radians);
	void setRotateY(float radians);
	void setRotateZ(float radians);

	void rotateX(float radians);

	void setEuler(float pitch, float yaw, float roll);
	//============rotation================

};

class Matrix4
{
public:

	float m[4][4];

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

	float data[4][4];

	Vector4 xAxis;
	Vector4 yAxis;
	Vector4 zAxis;
	Vector4 translation;




	Matrix4();
	Matrix4(float aX, float bX, float cX, float dX,
		float aY, float bY, float cY, float dY, 
		float aZ, float bZ, float cZ, float dZ,
		float aW, float bW, float cW, float dW);

	Matrix4 operator=(Matrix4 &other);
	Vector4 operator *(const Vector3 &v)const;
	Matrix4 operator *(const Matrix4 &other)const;

	Matrix4 transposed() const;
	static const Matrix4 identity;

	operator float*();

	//==========rotation========================
	void setScaled(float x, float y, float z);

	void translate(float x, float y, float z)
	{
		translation += Vector4(x, y, z, 0);
	}
	//==========rotation========================

};



class Vector4
{
public:
	float m_x;
	float m_y;
	float m_z;
	float m_w;

	float data[4];

	Vector4();
	Vector4(float X, float Y, float Z, float W);
	

	float operator[](int index)const;
	float &operator[](int index);

	operator float*();
	operator const float*();

	Vector4 operator +(const Vector4 &other) const;

	Vector4 operator +=(const Vector4 &other);

	Vector4 &operator -(const Vector4 &other);
	Vector4 &operator -=(const Vector4 *other);

	Vector4 &operator *=(float scalar);


	Vector4 operator * (float scalar) const;

	Vector4 operator * (const Matrix4 &other) const;

	Vector4 &operator /(float scalar);

	Vector4& operator = (const Vector4 &other);

	//magnitude
	float magnitude()const;
	void normalise();
	float dot(const Vector4 &other)const;

	Vector4 cross(const Vector4 &other) const;

};
Vector4 operator * (float scalar, const Vector4 &vec4);
