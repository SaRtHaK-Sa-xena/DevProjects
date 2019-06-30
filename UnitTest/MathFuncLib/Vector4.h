#pragma once

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