// MathFuncsLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "MathFuncsLib.h"

// TODO: This is an example of a library function
//void fnMathFuncsLib()
//{
//}

Vector3::Vector3()
{
	float x = 1;
	float y = 1;
	float z = 1;

	VectorArray[0] = x;
	VectorArray[1] = y;
	VectorArray[2] = z;
}
float Vector3::operator[](int index) const
{
	return VectorArray[index];
	//return 0.0f;
}
float& Vector3::operator[](int index)
{
	return VectorArray[index];
	// TODO: insert return statement here
}
double Vector3::PrintVectorx(float x)
{
	return x;
}
//========================VECTOR 3==========================


Vector2::Vector2()
{
	float x = 1;
	float y = 1;
}
