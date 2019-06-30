#pragma once

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