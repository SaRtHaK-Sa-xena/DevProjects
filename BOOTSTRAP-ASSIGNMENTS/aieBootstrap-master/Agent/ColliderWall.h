#pragma once
#include <Vector2.h>

enum wallSide
{
	rightSide, leftSide, topSide, bottomSide

};

struct Collider
{
	Vector2 TopLeftposition; //(2,3)
	Vector2 BottomRightPosition; //(2,4)

	wallSide sideOfWall;

};