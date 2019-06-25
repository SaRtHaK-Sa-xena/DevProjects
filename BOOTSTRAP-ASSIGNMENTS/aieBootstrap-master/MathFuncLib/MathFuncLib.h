#pragma once
#include <iostream>
// MathFuncsLib.h

//============VECTOR2=================
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
//============VECTOR2=================








//===============VECTOR3==============

class Vector3
{
public:

	Vector3();
	Vector3(float X, float Y, float Z);

	//union {
	//	struct {
	//		float m_x;
	//		float m_y;
	//		float m_z;
	//	};
	//	float data[3];
	//};
	
	union {
		struct {
			float m_x, m_y;
			union {
				float m_z, m_w;
			};
		};
		float data[3];
	};

	double PrintVectorx(float x);
	void DisplayVector3Coordinates();


	float GetX();
	float GetY();
	float GetZ();

	void SetX(float x_value);
	void SetY(float y_value);
	void SetZ(float z_value);

	float operator[](int index)const
	{
		return data[index];
	}
	float &operator[](int index)
	{
		return data[index];
	}
	operator float*();
	operator const float*()const;


	//=============================
	Vector3 operator- (const Vector3 &other);
	Vector3 operator+ (const Vector3 &other)const;
	Vector3 operator +=(const Vector3 &other);
	Vector3 operator* (float scalar);
	Vector3 operator*(float scalar)const 
	{
		return{ m_x * scalar, m_y * scalar, m_z * scalar };
	}
	Vector3 operator/= (float scalar);
	Vector3 operator= (const Vector3 &other);

	float dot(const Vector3 &other) const;
	float magnitude()const;
	void normalise();
	Vector3 cross(const Vector3 &other)const;
	
};
Vector3 operator* (float scalar, Vector3 &vec3);
//===============VECTOR3==============














class Vector4
{
public:
	union {
		struct {
			float m_x;
			float m_y;
			float m_z;
			float m_w;
		};
		float translation; //just added
		float data[4];
	};

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

	Vector4 &operator /(float scalar);

	Vector4& operator = (const Vector4 &other);

	float magnitude()const;
	void normalise();
	float dot(const Vector4 &other)const;

	Vector4 cross(const Vector4 &other) const;
};
Vector4 operator * (float scalar, const Vector4 &vec4);



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




