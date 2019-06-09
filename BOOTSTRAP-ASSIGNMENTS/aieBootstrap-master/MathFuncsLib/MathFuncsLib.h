#pragma once

class Vector3
{
public:

	Vector3() {};

	float operator[](int index) const; //returns 
	float& operator[](int index);

	float VectorArray[3]; //To Be Used
	float x, y, z;



	double PrintVectorx(float x);
};

class Vector2
{
public:

	Vector2();
	float x, y;


	//double PrintVector2Dx(float x);
};